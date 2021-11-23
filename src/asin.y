%{
	#include <stdio.h>
	#include "libtds.h"
	#include "header.h"
%}

%union {
  int cent ;
  char *ident ;
  ATR atr;
  CAMPO camp;
  FUNC func;
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
%type <cent> tipoSimple
%type <cent> operadorUnario operadorIgualdad operadorRelacional operadorAditivo operadorMultiplicativo
%type <camp> listaCampos parametrosFormales listaParametrosFormales
%type <exp> expresionIgualdad expresionRelacional expresionAditiva expresionMultiplicativa expresionUnaria expresionSufija

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
            $$.talla = TALLA_TIPO_SIMPLE; }
	| listaCampos tipoSimple ID_ SEMIC_
	  { $$.refe = insTdR($1.refe, $3, $2, $1.talla);
            $$.talla = $1.talla + TALLA_TIPO_SIMPLE; }
	;
declaracionFuncion 
	: tipoSimple ID_  
          { niv+=1; cargaContexto(niv); $<cent>$ = dvar; dvar = 0; }
          OPAREN_ parametrosFormales CPAREN_  
          { insTdS($<ident>2, FUNCION, $<cent>1, niv-1, dvar, $<camp>5.refe); } 
          bloque 
          { mostrarTdS(); descargaContexto(niv);  niv-=1; dvar = $<cent>3; }
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
            insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1); }
	| tipoSimple ID_ COMMA_ listaParametrosFormales
	  { $$.talla = $4.talla + TALLA_TIPO_SIMPLE;
            $$.refe = insTdD($4.refe, $1);
            insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1); }
	;

/******************************** AREG ********************************/ 
/** Solamente hay que incrementar y decrementar el nivel en el inicio y
    fin de bloque respectivamente, ya que las declaraciones de variables
    tienen en cuenta el nivel
 */
bloque 
	: OBRACE_ declaracionVariableLocal listaInstrucciones RETURN_ expresion SEMIC_ CBRACE_
	;
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
	| ID_ OBRACK_ expresion CBRACK_ ASIG_ expresion SEMIC_
	| ID_ DOT_ ID_ ASIG_ expresion SEMIC_
	;
instruccionEntradaSalida 
	: READ_ OPAREN_ ID_ CPAREN_ SEMIC_
	| PRINT_ OPAREN_ expresion CPAREN_ SEMIC_
	;
instruccionSeleccion 
	: IF_ OPAREN_ expresion CPAREN_ instruccion ELSE_ instruccion
	;
instruccionIteracion 
	: WHILE_ OPAREN_ expresion CPAREN_ instruccion
	;
/******************************* MYKOLA *******************************/ 
expresion 
	: expresionIgualdad
	| expresion operadorLogico expresionIgualdad
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
                if ($1 != OP_INC && $1 != OP_DEC)
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
	: constante 
	| OPAREN_ expresion CPAREN_
	| ID_
	| ID_ DOT_ ID_
	| ID_ OBRACK_ expresion CBRACK_
	| ID_ OPAREN_ parametrosActuales CPAREN_
	;
constante 
	: CTE_
	| TRUE_
	| FALSE_
	;
parametrosActuales 
	:
	| listaParametrosActuales
	;
listaParametrosActuales 
	: expresion
	| expresion COMMA_ listaParametrosActuales
	;
operadorLogico
	: AND_
	| OR_
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
