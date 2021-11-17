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
%type <camp> listaCampos parametrosFormales listaParametrosFormales
%type <func> declaracionFuncion 

%%

/******************************* GUILLEM *******************************/ 
programa
	: { dvar = 0; niv = 0; } listaDeclaraciones
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
            else dvar +=  TALLA_TIPO_SIMPLE; }
	| tipoSimple ID_ OBRACK_ CTE_ CBRACK_ SEMIC_
	  { int numel = $<cent>4;
            if ($4 <= 0) {
               yyerror("Talla negativa para el array");
               numel = 0;
            }
            int refe = insTdA($<cent>1, numel);
            if ( ! insTdS($<ident>2, VARIABLE, T_ARRAY, niv, dvar, refe))
		yyerror("Identificador repetido");
	    else dvar += numel * TALLA_TIPO_SIMPLE; }
	| STRUCT_ OBRACE_ listaCampos CBRACE_ ID_ SEMIC_
	  { if (! insTdS($<ident>5, VARIABLE, T_RECORD, niv, dvar, $3.refe))
		yyerror("Identificador repetido");
            else dvar += $3.talla;
	     }
	;
tipoSimple 
	: INTEGER_ 
	  { $<cent>$ = T_ENTERO; }
	| BOOLEAN_
	  { $<cent>$ = T_ENTERO; }
	;
listaCampos 
	: tipoSimple ID_ SEMIC_
	  { int refe = insTdR(-1, $<ident>2, $<cent>1, 0);
            $$.talla = TALLA_TIPO_SIMPLE;
	    $$.refe = refe; }
	| listaCampos tipoSimple ID_ SEMIC_
	  { insTdR($1.refe, $<ident>3, $<cent>2, $1.talla);
            $$.talla = $1.talla + TALLA_TIPO_SIMPLE;
	    $$.refe = $1.refe; }
	;
declaracionFuncion 
	: tipoSimple ID_ OPAREN_ parametrosFormales CPAREN_ bloque
	  { niv+=1; cargaContexto(niv); $$.aux = dvar; dvar = 0; 
            insTdS($<ident>2, FUNCION, $<cent>1, niv-1, dvar, $4.refe); 
	    descargaContexto(niv); niv-=1; dvar = $$.aux; }
	;
parametrosFormales 
	: { $$.refe = insTdD(-1, T_VACIO); } 
	| listaParametrosFormales
	  { $$.refe = $1.refe; 
            $$.talla = $1.talla - TALLA_SEGENLACES; }
	;
listaParametrosFormales 
	: tipoSimple ID_
	  { $$.talla = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE;
            int refe = insTdD(-1, $<cent>1);
            $$.refe = refe;
            insTdS($<ident>2, PARAMETRO, $<cent>1, niv, -$$.talla, refe); }
	| tipoSimple ID_ COMMA_ listaParametrosFormales
	  { $$.talla = $4.talla + TALLA_TIPO_SIMPLE;
            int refe = insTdD($4.refe, $<cent>1);
            $$.refe = refe;
            insTdS($<ident>2, PARAMETRO, $<cent>1, niv, -$$.talla, refe); }
	;

/******************************** AREG ********************************/ 
/** Solamente hay que incrementar y decrementar el nivel en el inicio y
    fin de bloque respectivamente, ya que las declaraciones de variables
    tienen en cuenta el nivel
 */
bloque 
	: OBRACE_ {niv += 1;} declaracionVariableLocal listaInstrucciones RETURN_ expresion SEMIC_ {niv -= 1;} CBRACE_
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
expresionIgualdad 
	: expresionRelacional
	| expresionIgualdad operadorIgualdad expresionRelacional
	;
/******************************** FRAN ********************************/ 
expresionRelacional 
	: expresionAditiva
	| expresionRelacional operadorRelacional expresionAditiva
	;
expresionAditiva 
	: expresionMultiplicativa
	| expresionAditiva operadorAditivo expresionMultiplicativa
	;
expresionMultiplicativa 
	: expresionUnaria
	| expresionMultiplicativa operadorMultiplicativo expresionUnaria
	;
expresionUnaria 
	: expresionSufija
	| operadorUnario expresionUnaria
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
	: EQ_
	| NEQ_
	;
operadorRelacional
	: GT_
	| LT_
	| GTEQ_
	| LTEQ_
	;
operadorAditivo 
	: PLUS_
	| MINUS_
	;
operadorMultiplicativo
	: MULT_
	| DIV_
	;
operadorUnario 
	: PLUS_
	| MINUS_
	| EXCL_
	;
%%
