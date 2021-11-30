%{
	#include <stdio.h>
	#include <string.h>
	#include "libtds.h"
	#include "header.h"
%}

%union {
  int cent ;
  char *ident ;
  CAMPO camp;
  EXP exp;
}

%token INTEGER_ BOOLEAN_ STRUCT_ RETURN_ READ_ PRINT_
%token IF_ ELSE_ WHILE_ TRUE_ FALSE_
%token OPAREN_ CPAREN_ OBRACK_ CBRACK_ OBRACE_ CBRACE_ SEMIC_
%token AND_ OR_ EQ_ NEQ_ GT_ GTEQ_ LT_ LTEQ_
%token PLUS_ MINUS_ MULT_ DIV_ EXCL_
%token ASIG_ COMMA_ DOT_
%token <ident> ID_ 
%token <cent> CTE_
%type <cent> tipoSimple operadorUnario operadorIgualdad operadorRelacional operadorAditivo operadorMultiplicativo operadorLogico
%type <camp> listaCampos parametrosFormales listaParametrosFormales
%type <exp> expresion expresionIgualdad expresionRelacional expresionAditiva expresionMultiplicativa expresionUnaria expresionSufija constante parametrosActuales listaParametrosActuales

%%

/******************************* GUILLEM *******************************/ 
programa
	: { dvar = 0; niv = 0; cargaContexto(niv); } listaDeclaraciones 
	;
listaDeclaraciones
	: declaracion
	| listaDeclaraciones declaracion
	;
declaracion 
	: declaracionVariable
	| declaracionFuncion
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
          { if( ! insTdS($2, FUNCION, $1, niv-1, -1, $5.refe)) {
               if(strcmp($2, "main") == 0)
	         yyerror("Programa con mas de una funcion main"); 
               else
	         yyerror("Identificador de funcion repetido"); 
              }
          } 
          bloque 
          { if(verTdS) mostrarTdS(); descargaContexto(niv);  niv-=1; dvar = $<cent>3; }
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
	: OBRACE_ declaracionVariableLocal listaInstrucciones RETURN_ expresion SEMIC_ CBRACE_
      {
        INF inf = obtTdD(-1);
        if (inf.tipo != T_ERROR && inf.tipo != $5.t) {
            yyerror("Tipos de retorno no compatibles.");
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
        if (simb.t != T_ERROR && $3.t != T_ERROR) {
            if (simb.t != $3.t) { yyerror("Asignacion con tipos no compatibles."); }
        }
      }
	| ID_ OBRACK_ expresion CBRACK_ ASIG_ expresion SEMIC_
      {
        if ($3.t != T_ERROR && $3.t != T_ENTERO) { yyerror("Indexacion con expresion no entera."); }
        else {
            SIMB simb = obtTdS($1);
            if (simb.t != T_ERROR && $3.t != T_ERROR) {
                if (simb.t != T_ARRAY) { yyerror("Indexacion en identificador no de tipo array."); }
                else {
                    DIM dim = obtTdA(simb.ref);
                    if (dim.telem != $6.t) {
                        yyerror("Asignacion con tipos no compatibles");
                    }
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
  }
	| PRINT_ OPAREN_ expresion CPAREN_ SEMIC_
      {
        if ($3.t != T_ERROR && $3.t != T_ENTERO) { yyerror("Expresion con tipo no entero."); }
      }
	;
instruccionSeleccion 
	: IF_ OPAREN_ expresion CPAREN_ instruccion ELSE_ instruccion
      {
        if ($3.t != T_ERROR && $3.t != T_LOGICO) { yyerror("Expresion de if con tipo no booleano."); }
      }
	;
instruccionIteracion 
	: WHILE_ OPAREN_ expresion CPAREN_ instruccion
      {
        if ($3.t != T_ERROR && $3.t != T_LOGICO) { yyerror("Expresion de while no booleana."); }
      }
	;
/******************************* MYKOLA *******************************/ 
expresion 
	: expresionIgualdad { $$.t = $1.t; }
	| expresion operadorLogico expresionIgualdad
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if($1.t != $3.t)
                yyerror("Los tipos no son equivalentes");
            else if ($1.t != T_LOGICO)
                yyerror("Las expresion deber ser lógicas");
            else
                $$.t = T_LOGICO;
        }
    }
	;
/******************************** FRAN ********************************/ 
expresionIgualdad 
	: expresionRelacional { $$.t = $1.t; }
	| expresionIgualdad operadorIgualdad expresionRelacional
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if ($1.t != $3.t)
                yyerror("Los tipos no son equivalentes.");
            else if ($1.t != T_LOGICO || $1.t != T_ENTERO)
                yyerror("Las expresiones deben ser lógicas o enteros");
            else
                $$.t = T_LOGICO;
        }
    }
	;
expresionRelacional 
	: expresionAditiva { $$.t = $1.t; }
	| expresionRelacional operadorRelacional expresionAditiva
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if ($1.t != $3.t)
                yyerror("Los tipos no son equivalentes.");
            else if ($1.t != T_ENTERO)
                yyerror("Las expresiones deben ser enteras");
            else
                $$.t = T_LOGICO;
        }
    }
	;
expresionAditiva 
	: expresionMultiplicativa { $$.t = $1.t; }
	| expresionAditiva operadorAditivo expresionMultiplicativa
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if ($1.t != $3.t)
                yyerror("Los tipos no son equivalentes.");
            else if ($1.t != T_ENTERO)
                yyerror("Las expresiones deben ser enteras");
            else
                $$.t = T_ENTERO;
        }
    }
	;
expresionMultiplicativa 
	: expresionUnaria { $$.t = $1.t; }
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
    }
	;
expresionUnaria 
	: expresionSufija { $$.t = $1.t; }
	| operadorUnario expresionUnaria
    {
        $$.t = T_ERROR;
        if ($2.t != T_ERROR) {
            if ($2.t == T_ENTERO) {
                if ($1 == OP_NOT)
                    yyerror("El operador NOT es incompatible con enteros");
                else
                    $$.t = T_ENTERO;
            } else if ($2.t == T_LOGICO) {
                if ($1 != OP_MINUS && $1 != OP_PLUS)
                    $$.t = T_LOGICO;
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
	: constante {$$.t = $1.t; }
	| OPAREN_ expresion CPAREN_ {$$.t = $2.t; }
	| ID_ 
          {
            $$.t = T_ERROR;
            SIMB simb = obtTdS($1);
            if(simb.t == T_ERROR) { yyerror("Identificador no declarado"); }
            else { $$.t = simb.t; }
          }
        | ID_ DOT_ ID_
        /*********************CAMBIAR MENSAJE ERROR**********************/
    {
        $$.t = T_ERROR;
        SIMB simb = obtTdS($1);
        if (simb.t == T_ERROR) { yyerror("Identificador no declarado."); }
        else if (simb.t != T_RECORD) { yyerror("Acceso a campo de identificador no de tipo registro."); }
        else {
            CAMP camp = obtTdR(simb.ref, $3);
            if (camp.t == T_ERROR) { yyerror("ERROR A DEFINIR"); }   
            else { $$.t = camp.t; }
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
            }
    }
	| ID_ OPAREN_ parametrosActuales CPAREN_
    /***********************COMPLETAR*****************/
    {
        $$.t = T_ERROR;
        SIMB simb = obtTdS($1);
        if (simb.t == T_ERROR) { yyerror("No existe ninguna variable con ese identificador."); }
        INF inf = obtTdD(simb.ref);
        if (inf.tipo == T_ERROR) { yyerror("No existe ninguna función con ese identificador."); }
        else if (inf.tsp != $3.t * TALLA_TIPO_SIMPLE) { yyerror("Número incorrecto de parametros actuales"); }
        else if ( ! cmpDom()) /******COMPLETAR******/
        else 
        { $$.t = inf.tipo; }
    }
	;
constante 
	: CTE_ { $$.t = T_ENTERO; }
	| TRUE_ { $$.t = T_LOGICO; }
	| FALSE_ { $$.t = T_LOGICO; }
	;
parametrosActuales 
	: {$$.t = 0;}
	| listaParametrosActuales {$$.t = $1.t;}
	;
listaParametrosActuales 
	: expresion { $$.t = 1;}
	| expresion COMMA_ listaParametrosActuales
          { $$.t = $3.t + 1; }
	;
operadorLogico
	: AND_      { $$ = OP_AND; }
	| OR_       { $$ = OP_OR;  }
	;
/******************************** FRAN ********************************/ 
operadorIgualdad
	: EQ_       { $$ = OP_EQ; }
	| NEQ_      { $$ = OP_NEQ; }
	;
operadorRelacional
	: GT_       { $$ = OP_GT; }
	| LT_       { $$ = OP_LT; }
	| GTEQ_     { $$ = OP_GTEQ; }
	| LTEQ_     { $$ = OP_LTEQ; }
	;
operadorAditivo 
	: PLUS_     { $$ = OP_PLUS; }
	| MINUS_    { $$ = OP_MINUS; }
	;
operadorMultiplicativo
	: MULT_     { $$ = OP_MULT; }
	| DIV_      { $$ = OP_DIV; }
	;
operadorUnario 
	: PLUS_     { $$ = OP_INC; }
	| MINUS_    { $$ = OP_DEC; }
	| EXCL_     { $$ = OP_NOT; }
	;
%%
