%{
	#include <stdio.h>
	#include "libtds.h"
	#include "header.h"
%}

%union {
  int cent ;
  char *ident ;
  ATR atr;
}

%token INTEGER_ BOOLEAN_ STRUCT_ RETURN_ READ_ PRINT_
%token IF_ ELSE_ WHILE_ TRUE_ FALSE_
%token OPAREN_ CPAREN_ OBRACK_ CBRACK_ OBRACE_ CBRACE_ SEMIC_
%token AND_ OR_ EQ_ NEQ_ GT_ GTEQ_ LT_ LTEQ_
%token PLUS_ MINUS_ MULT_ DIV_ EXCL_
%token ASIG_ COMMA_ DOT_
%token <ident> ID_ 
%token <cent> CTE_
%type <atr> declaracion declaracionVariable tipoSimple listaCampos 
%type <atr> declaracionFuncion
%%

programa
	: { dvar = 0; niv = 0; } listaDeclaraciones
	;
listaDeclaraciones
	: declaracion
	| listaDeclaraciones declaracion
	;
declaracion 
	: declaracionVariable
	  { insTdS($1.name, VARIABLE, $1.type, niv, dvar, $1.refe); 
	    dvar += $1.talla; }
	| declaracionFuncion
	;
declaracionVariable 
	: tipoSimple ID_ SEMIC_
	  { $$.name = $2; 
	    $$.type = $1.type; 
	    $$.talla = $1.talla; }
	| tipoSimple ID_ OBRACK_ CTE_ CBRACK_ SEMIC_
	  { $$.name = $2; 
	    $$.type = $1.type; 
	    $$.talla = $1.talla; }
	| STRUCT_ OBRACE_ listaCampos CBRACE_ ID_ SEMIC_
	  { $$.name = $5; 
	    $$.type = T_RECORD; 
	    $$.talla = $3.talla; }
	;
tipoSimple 
	: INTEGER_ 
	  { $$.type = T_ENTERO; 
            $$.talla = TALLA_TIPO_SIMPLE; 
            $$.refe = -1; }
	| BOOLEAN_
	  { $$.type = T_ENTERO; 
            $$.talla = TALLA_TIPO_SIMPLE; 
            $$.refe = -1; }
	;
listaCampos 
	: tipoSimple ID_ SEMIC_
	| listaCampos tipoSimple ID_ SEMIC_
	;
declaracionFuncion 
	: tipoSimple ID_ OPAREN_ parametrosFormales CPAREN_ bloque
	;
parametrosFormales 
	: 
	| listaParametrosFormales
	;
listaParametrosFormales 
	: tipoSimple ID_
	| tipoSimple ID_ COMMA_ listaParametrosFormales
	;
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
expresion 
	: expresionIgualdad
	| expresion operadorLogico expresionIgualdad
	;
expresionIgualdad 
	: expresionRelacional
	| expresionIgualdad operadorIgualdad expresionRelacional
	;
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
