%{
	#include <stdio.h>
	#include <string.h>
	#include "libtds.h"
        #include "libgci.h"
	#include "header.h"
%}

%union {
  int cent ;
  char *ident ;
  LISTA lista;
  EXP exp;
  PR pr;
}

%token INTEGER_ BOOLEAN_ STRUCT_ RETURN_ READ_ PRINT_
%token IF_ ELSE_ WHILE_ TRUE_ FALSE_
%token OPAREN_ CPAREN_ OBRACK_ CBRACK_ OBRACE_ CBRACE_ SEMIC_
%token AND_ OR_ EQ_ NEQ_ GT_ GTEQ_ LT_ LTEQ_
%token PLUS_ MINUS_ MULT_ DIV_ EXCL_
%token ASIG_ COMMA_ DOT_
%token <ident> ID_ 
%token <cent> CTE_
%type <cent> tipoSimple operadorUnario operadorIgualdad operadorRelacional operadorAditivo operadorMultiplicativo operadorLogico declaracionFuncion declaracion listaDeclaraciones bloque
%type <lista> listaCampos parametrosFormales listaParametrosFormales parametrosActuales listaParametrosActuales
%type <exp> expresion expresionIgualdad expresionRelacional expresionAditiva expresionMultiplicativa expresionUnaria expresionSufija constante instruccionSeleccion instruccionIteracion
%%

/******************************* GUILLEM *******************************/ 
programa
	: { si=0; dvar = 0; niv = 0; cargaContexto(niv); 

	    /* Reservar espacio para variables globales */
            $<pr>$.ref1 = creaLans(si);
            emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));

	    /* Emitir el salto al comienzo de la funcion */
            $<pr>$.ref2 = creaLans(si);
            emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));

          } listaDeclaraciones 
          { if($2 == 0) yyerror("Programa sin main declarado");
            else if($2 == -2) yyerror("Programa con mas de una funcion main");
	    else {
		/*Completar la reserva de espacio para las variables globales*/
        	completaLans($<pr>1.ref1, crArgEnt(dvar));
		/*Completar el salto al comienzo de la funci´on ''main''*/
		SIMB simbMain = obtTdS("main"); 
        	completaLans($<pr>1.ref2, crArgEtq(simbMain.d));
            }
          } 
	;
listaDeclaraciones
	: declaracion { $$ = $1; } 
	| listaDeclaraciones declaracion 
          { 
          if($1 == -1 && $2 == -1) $$ = -2;
          else $$ = $1 + $2; 
          } 
	;
declaracion 
	: declaracionVariable { $$ = 0; }
	| declaracionFuncion { $$ = $1; }
	;
declaracionVariable 
	: tipoSimple ID_ SEMIC_
	  { if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) 
		yyerror("Identificador repetido");
            else dvar +=  TALLA_TIPO_SIMPLE;  }
	| tipoSimple ID_ OBRACK_ CTE_ CBRACK_ SEMIC_
	  { int numel = $4;
            if ($4 <= 0) {
               yyerror("Talla negativa para el array");
               numel = 0;
            }
            int refe = insTdA($1, numel);
            if ( ! insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe))
		yyerror("Identificador repetido");
	    else dvar += numel * TALLA_TIPO_SIMPLE; } 
	| STRUCT_ OBRACE_ listaCampos CBRACE_ ID_ SEMIC_
	  { if (! insTdS($5, VARIABLE, T_RECORD, niv, dvar, $3.refe))
		yyerror("Identificador repetido");
            else dvar += $3.talla;
	     }
	;
tipoSimple 
	: INTEGER_ 
	  { $$ = T_ENTERO; }
	| BOOLEAN_
	  { $$ = T_LOGICO; }
	;
listaCampos 
	: tipoSimple ID_ SEMIC_
	  { $$.refe = insTdR(-1, $2, $1, 0);
	    if ( $$.refe == -1) 
		yyerror("Campo repetido");
            $$.talla = TALLA_TIPO_SIMPLE; }
	| listaCampos tipoSimple ID_ SEMIC_
	  { $$.refe = insTdR($1.refe, $3, $2, $1.talla);
	    if ( $$.refe == -1) 
		yyerror("Campo repetido");
            $$.talla = $1.talla + TALLA_TIPO_SIMPLE; }
	;
declaracionFuncion 
	: tipoSimple ID_  
          { niv+=1; cargaContexto(niv); $<cent>$ = dvar; dvar = 0; }
          OPAREN_ parametrosFormales CPAREN_  
          { if( ! insTdS($2, FUNCION, $1, niv-1, si, $5.refe)) {
	         yyerror("Identificador de funcion repetido"); 
              }
          } 
          bloque 
          {  if(strcmp($2, "main") == 0) $$ = -1;
             else $$ = 0;
             if(verTdS) mostrarTdS(); descargaContexto(niv);  niv-=1; dvar = $<cent>3; 
          }
	;
parametrosFormales 
	: { $$.refe = insTdD(-1, T_VACIO); } 
	| listaParametrosFormales
	  { $$.refe = $1.refe; }
	;
listaParametrosFormales 
	: tipoSimple ID_
	  { $$.talla = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE;
            $$.refe = insTdD(-1, $1);
            if( ! insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1))
	       yyerror("Parametro repetido"); 
          }
	| tipoSimple ID_ COMMA_ listaParametrosFormales
	  { $$.talla = $4.talla + TALLA_TIPO_SIMPLE;
            $$.refe = insTdD($4.refe, $1);
            if( ! insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1))
	       yyerror("Parametro repetido"); 
          }
	;

/******************************** AREG ********************************/ 
bloque 
	: 
      {
        /* Cargar enlaces de control */
        emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());

        /* Reservar espacio para variables locales y temporales */
        emite(FPTOP, crArgNul(), crArgNul(), crArgNul());

        $<cent>$ = creaLans(si);

        /* TODO: Confirmar que crArgEnt(-1) hace que se reemplace por LANS*/
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));
      }
      OBRACE_ declaracionVariableLocal listaInstrucciones RETURN_ expresion SEMIC_ CBRACE_
      {
        INF inf = obtTdD(-1);
        if (inf.tipo == T_ERROR) {

           yyerror("Error en la declaracion de la funcion.");
        }
        else if (inf.tipo != $6.t) {
            yyerror("Tipos de retorno no compatibles.");
        }

        /* TODO: Completar la reserva para las variables locales y temporales */
        /* completaLans($<cent>$, crArgEnt(dvar)); */
        completaLans($<cent>2, crArgEnt(dvar));
        
        /* TODO: Guardar el valor de retorno */
        /* Quitar dirret de aqui, entiendo que tiene que estar en el bloque llamador
           y tiene que apilarse ahi para ser desapilado aca y no tener que calcular? */
        int dirret = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE + inf.tsp;
        emite(EASIG, crArgPos(niv, $6.v), crArgNul(), crArgPos(niv, dirret));

        /* Liberar el segmento de variables locales y temporales  */
        emite(TOPFP, crArgNul(), crArgNul(), crArgNul());
        
        /* Descargar los enlaces de control  */
        emite(FPPOP, crArgNul(), crArgNul(), crArgNul());

        /* Emitir FIN si es ‘‘main’’ y RETURN si no es  */
        if (strcmp(inf.nom, "main") == 0) { 
            emite(FIN, crArgNul(), crArgNul(), crArgNul());
        }
        else { 
            emite(RET, crArgNul(), crArgNul(), crArgNul()); 
        }
      }	;
declaracionVariableLocal 
	:
	| declaracionVariableLocal declaracionVariable
	;
listaInstrucciones 
	:
	| listaInstrucciones instruccion
	;
instruccion 
	: OBRACE_ listaInstrucciones CBRACE_ 
	| instruccionAsignacion
	| instruccionSeleccion
	| instruccionEntradaSalida
	| instruccionIteracion
	;
instruccionAsignacion 
	: ID_ ASIG_ expresion SEMIC_
      {
        SIMB simb = obtTdS($1); 
        if (simb.t == T_ERROR) yyerror("Identificador no declarado.");
        else if ($3.t != T_ERROR) {
            if (simb.t != $3.t) { yyerror("Asignacion con tipos no compatibles."); }
        }

        emite(EASIG, crArgPos(niv, $3.v), crArgNul(), crArgPos(simb.n, simb.d));
      }
	| ID_ OBRACK_ expresion CBRACK_ ASIG_ expresion SEMIC_
      {
        if ($3.t != T_ERROR && $3.t != T_ENTERO) { yyerror("Indexacion con expresion no entera."); }
        else {
            SIMB simb = obtTdS($1);
            if (simb.t != T_ERROR && $3.t != T_ERROR && $6.t != T_ERROR) {
                if (simb.t != T_ARRAY) { yyerror("Indexacion en identificador no de tipo array."); }
                else {
                    DIM dim = obtTdA(simb.ref);
                    if (dim.telem != $6.t) {
                        yyerror("Asignacion con tipos no compatibles");
                    }

                    emite(EVA, crArgPos(simb.n, simb.d), crArgPos(niv, $3.v), crArgPos(niv, $6.v));
                }
            }
        }
      }
	| ID_ DOT_ ID_ ASIG_ expresion SEMIC_
      {
        SIMB simb = obtTdS($1); 
        if (simb.t != T_ERROR && $5.t != T_ERROR) {
            if (simb.t != T_RECORD) { yyerror("Acceso a campo de identificador no de tipo registro."); }
            else {
                CAMP camp = obtTdR(simb.ref, $1);
                if (camp.t != $5.t) {
                    yyerror("Asignacion con tipos no compatibles");
                }
                int d = simb.d + camp.d;  
                /* TODO: confirmar que esto esta bien */
                emite(EASIG, crArgPos(niv, d), crArgNul(), crArgPos(niv, $5.v));
            }
        }
      }
	;
instruccionEntradaSalida 
	: READ_ OPAREN_ ID_ CPAREN_ SEMIC_
      {
        SIMB simb = obtTdS($3); 
        if (simb.t != T_ERROR) {
            if (simb.t != T_ENTERO) { yyerror("Identificador con tipo no entero."); }
        }
        /* TODO: confirmar que funciona como se espera */
        emite(EREAD, crArgNul(), crArgNul(), crArgPos(simb.n, simb.d));
      }
	| PRINT_ OPAREN_ expresion CPAREN_ SEMIC_
      {
        if ($3.t != T_ERROR && $3.t != T_ENTERO) { yyerror("Expresion con tipo no entero."); }

        /* TODO: confirmar que funciona como se espera */
        emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, $3.v));
      }
	;
instruccionSeleccion 
	: IF_ OPAREN_ expresion CPAREN_ 
      { 
        if ($3.t != T_ERROR && $3.t != T_LOGICO) { yyerror("Expresion de if con tipo no booleano."); } 

        /* Uso EXP como tipo aunque no sea autoexplicativo, ya que solo necesito 
           saber el SI final y la referencia a la LANS */
        /* Respecto a la teoria, $$.t := S.fin y $$.v := S.lf */
        $<exp>$.v = creaLans(si);
        
        /* TODO: ¿-1 hace que se use el valor con la LANS completada? */
        emite(EIGUAL, crArgPos(niv, $3.v), crArgEnt(0), crArgEtq(-1));
        
      }
	  instruccion
      {
        $<exp>$.t = creaLans(si); 
        /* TODO: ¿-1 hace que se use el valor con la LANS completada? */
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        completaLans($<exp>5.v, crArgEtq(si));
      }

      ELSE_ instruccion 
      {
        completaLans($<exp>7.t, crArgEtq(si));
      }
	;
instruccionIteracion 
	: WHILE_ {$<exp>$.v = si; } OPAREN_ expresion CPAREN_ 
      { 
        /* Uso EXP como tipo aunque no sea autoexplicativo, ya que solo necesito 
           saber el SI inicial y la referencia a la LANS */
        /* Respecto a la teoria, $$.t := S.ini y $$.v := S.lf */

        $<exp>$.v = creaLans(si);
        if ($4.t != T_ERROR && $4.t != T_LOGICO) { yyerror("Expresion de while no booleana."); }
        
        /* TODO: ¿-1 hace que se use el valor con la LANS completada? */
        emite(EIGUAL, crArgPos(niv, $4.v), crArgEnt(0), crArgEtq(-1));
      }

      instruccion

      {
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<exp>$.v));
        /* TODO: puse Etq porque es lo que se usa en el emite de arriba pero no estoy seguro */
	/* -Guillem: aqui deberia ser $<exp>6.t? */
        completaLans($<exp>5.t, crArgEtq(si)); 
      }
	;
/******************************* MYKOLA *******************************/ 
expresion 
	: expresionIgualdad { $$.t = $1.t; $$.v = $1.v;}
	| expresion operadorLogico expresionIgualdad
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if($1.t != $3.t)
                yyerror("Los tipos no son equivalentes");
            else if ($1.t != T_LOGICO)
                yyerror("Las expresion deber ser lógicas");
            else {
                $$.t = T_LOGICO;
                $$.v = creaVarTemp();
                emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.v));
                emite($2, crArgPos(niv, $1.v), crArgPos(niv, $3.v), crArgEtq(si + 2));
                emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.v));
            }
        }
    }
	;
/******************************** FRAN ********************************/ 
expresionIgualdad 
	: expresionRelacional { $$.t = $1.t; $$.v = $1.v; }
	| expresionIgualdad operadorIgualdad expresionRelacional
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if ($1.t != $3.t)
                yyerror("Los tipos no son equivalentes.");
            else if ($1.t != T_LOGICO || $1.t != T_ENTERO)
                yyerror("Las expresiones deben ser lógicas o enteros");
            else {
                $$.t = T_LOGICO;
                $$.v = creaVarTemp();
                emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.v));
                emite($2, crArgPos(niv, $1.v), crArgPos(niv, $3.v), crArgEtq(si + 2));
                emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.v));
            }
        }
    }
	;
expresionRelacional 
	: expresionAditiva { $$.t = $1.t; $$.v = $1.v; }
	| expresionRelacional operadorRelacional expresionAditiva
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if ($1.t != $3.t)
                yyerror("Los tipos no son equivalentes.");
            else if ($1.t != T_ENTERO)
                yyerror("Las expresiones deben ser enteras");
            else {
                $$.t = T_LOGICO;
                $$.v = creaVarTemp();
                emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.v));
                emite($2, crArgPos(niv, $1.v), crArgPos(niv, $3.v), crArgEtq(si + 2));
                emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.v));
            }
        }
    }
	;
expresionAditiva 
	: expresionMultiplicativa { $$.t = $1.t; $$.v = $1.v; }
	| expresionAditiva operadorAditivo expresionMultiplicativa
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if ($1.t != $3.t)
                yyerror("Los tipos no son equivalentes.");
            else if ($1.t != T_ENTERO)
                yyerror("Las expresiones deben ser enteras");
            else {
                $$.t = T_ENTERO;
                $$.v = creaVarTemp();
                emite($2, crArgPos(niv, $1.v), crArgPos(niv, $3.v), crArgPos(niv, $$.v));
            }
        }
    }
	;
expresionMultiplicativa 
	: expresionUnaria { $$.t = $1.t; $$.v = $1.v; }
	| expresionMultiplicativa operadorMultiplicativo expresionUnaria
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if ($1.t != $3.t)
                yyerror("Los tipos no son equivalentes.");
            else if ($1.t != T_ENTERO)
                yyerror("Las expresiones deben ser enteras.");
            else
                $$.t = T_ENTERO;
        }
        $$.v = creaVarTemp();
        emite($2, crArgPos(niv, $1.v), crArgPos(niv, $3.v), crArgPos(niv, $$.v));
    }
	;
expresionUnaria 
	: expresionSufija { $$.t = $1.t; $$.v = $1.v; }
	| operadorUnario expresionUnaria
    {
        $$.t = T_ERROR;
        if ($2.t != T_ERROR) {
            if ($2.t == T_ENTERO) {
                if ($1 == OP_NOT)
                    yyerror("El operador NOT es incompatible con enteros");
                else {
                    $$.t = T_ENTERO;
                    if ($1 == OP_MINUS) {
                        $$.v = creaVarTemp();
                        emite(ESIG, crArgPos(niv, $2.v), crArgNul(), crArgPos(niv, $$.v));
                    }
                }
            } else if ($2.t == T_LOGICO) {
                if ($1 != OP_MINUS && $1 != OP_PLUS) {
                    $$.t = T_LOGICO;
                    $$.v = creaVarTemp();
                    emite(EDIF, crArgEnt(1), crArgPos(niv, $2.v), crArgPos(niv, $$.v));
                }
                else
                    yyerror("La suma y la resta son operadores binarios. Es incompatible con tipos logicos.");
            } else {
                yyerror("Los tipos no son equivalentes.");
            }
        }
    }
	;
/******************************* MYKOLA *******************************/ 
expresionSufija 
	: constante {
        $$.t = $1.t; 
        $$.v = creaVarTemp(); 
        emite(EASIG, crArgEnt($1.v), crArgNul(), crArgPos(niv, $$.v));
        }
	| OPAREN_ expresion CPAREN_ {$$.t = $2.t; $$.v = $2.v;}
	| ID_ 
    {
        $$.t = T_ERROR;
        SIMB simb = obtTdS($1);
        if(simb.t == T_ERROR) { yyerror("Identificador no declarado"); }
        else { 
            $$.t = simb.t; 
            $$.v = creaVarTemp();
            emite(EASIG, crArgPos(niv, $1.v), crArgNul(), crArgPos(niv, $$.v));
        }
    }
    | ID_ DOT_ ID_
    {
        $$.t = T_ERROR;
        SIMB simb = obtTdS($1);
        if (simb.t == T_ERROR) { yyerror("Identificador no declarado."); }
        else if (simb.t != T_RECORD) { yyerror("Acceso a campo de identificador no de tipo registro."); }
        else {
            CAMP camp = obtTdR(simb.ref, $3);
            if (camp.t == T_ERROR) { yyerror("Acceso a campo no declarado."); }   
            else { 
                $$.t = camp.t;
                d = simb.d + camp.d;
                $$.v = creaVarTemp();
                emite(EASIG, crArgPos(niv, d), crArgNul(), crArgPos(niv, $$.v));
            }
        }
    }
	| ID_ OBRACK_ expresion CBRACK_
    {   
        $$.t = T_ERROR;
        if ($3.t != T_ENTERO) { yyerror("Indexacion con expresion no entera."); }
        SIMB simb = obtTdS($1);
        if (simb.t == T_ERROR) { yyerror("Identificador no declarado."); }
        else if (simb.t != T_ARRAY) { yyerror("Acceso a contenido de identificador no de tipo array."); }
        else {
            DIM dim = obtTdA(simb.ref);
            $$.t = dim.telem;
            $$.v = creaVarTemp();
            emite(EAV, crArgPos(simb.n, simb.d), crArgPos(niv, $3.v), crArgPos(niv, $$.v))
            }
    }
	| ID_ OPAREN_ 
    {
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(TALLA_TIPO_SIMPLE));
    }
    parametrosActuales CPAREN_
    {
        $$.t = T_ERROR;
        SIMB simb = obtTdS($1);
        if (simb.t == T_ERROR) { yyerror("No existe ninguna variable con ese identificador."); }
        INF inf = obtTdD(simb.ref);
        if (inf.tipo == T_ERROR) { yyerror("No existe ninguna función con ese identificador."); }
        else if ( ! cmpDom(simb.ref, $3.refe))
	        yyerror("Dominios incompatibles");
        else { 
            $$.t = inf.tipo; 
            emite(CALL, crArgNul(), crArgNul(), crArgEtq(simb.d)); 
            emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(inf.tsp));
            $$.v = creaVarTemp();
            emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, $$.v));
        }
    }
	;
/* Asumo $$.v como valor de la CTE (ya esta en el header) */
constante 
	: CTE_ { $$.t = T_ENTERO; $$.v = $1;}
	| TRUE_ { $$.t = T_LOGICO; $$.v = 1;}
	| FALSE_ { $$.t = T_LOGICO; $$.v = 0;}
	;
parametrosActuales 
	: {$$.refe = insTdD(-1, T_VACIO);}
	| listaParametrosActuales {$$.refe = $1.refe;}
	;
listaParametrosActuales 
	: expresion 
    { 
        $$.refe = insTdD(-1, $1.t); 
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.v));
    }
	| expresion COMMA_ { emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.v)); }
    listaParametrosActuales
    { $$.refe = insTdD($3.refe, $1.t); }
	;
operadorLogico
	: AND_      { $$ = EMULT; }
	| OR_       { $$ = ESUM;  }
	;
/******************************** FRAN ********************************/ 
operadorIgualdad
	: EQ_       { $$ = EIGUAL; }
	| NEQ_      { $$ = EDIST; }
	;
operadorRelacional
	: GT_       { $$ = EMAY; }
	| LT_       { $$ = EMEN; }
	| GTEQ_     { $$ = EMAYEQ; }
	| LTEQ_     { $$ = EMENEQ; }
	;
operadorAditivo 
	: PLUS_     { $$ = ESUM; }
	| MINUS_    { $$ = EDIF; }
	;
operadorMultiplicativo
	: MULT_     { $$ = EMULT; }
	| DIV_      { $$ = EDIVI; }
	;
operadorUnario 
	: PLUS_     { $$ = ESUM; }
	| MINUS_    { $$ = EDIF; }
	| EXCL_     { $$ = ESIG; }
	;
%%
