/*****************************************************************************/
/** Ejemplo de FLEX: S E M - 1
<jbenedi@dsic.upv.es> **/
/*****************************************************************************/
%{
	#include <stdio.h>
	#include <string.h>
	#include "header.h"
	#include "asin.h"
	#define	retornar(x) {if (verbosidad) ECHO; return x;}
%}
/*----------------------------------------------------------------------
Estas opciones evitan "warnings" innecesarios y permiten obtener el
numero de linea actual en la variable global "yylineno".
----------------------------------------------------------------------*/
%option noinput
%option nounput
%option yylineno

delimitador [ \t]+
newline \n
digito [0-9]
letra [A-Za-z]
id {letra}({letra}|{digito}|_)*
cte {digito}*\.?{digito}*
comentario \/\/.*\n
%%

{newline} { if(verbosidad) {ECHO; fprintf(stdout, "%3d.- ", yylineno);}}

int { retornar(INTEGER_); }
bool { retornar(BOOLEAN_); }
struct { retornar(STRUCT_); }
return { retornar(RETURN_); }
read { retornar(READ_); }
print { retornar(PRINT_); }
if { retornar(IF_); }
else { retornar(ELSE_); }
while { retornar(WHILE_); }
true { retornar(TRUE_); }
false { retornar(FALSE_); }

"(" { retornar(OPAREN_); }
")" { retornar(CPAREN_); }
"[" { retornar(OBRACK_); }
"]" { retornar(CBRACK_); }
"{" { retornar(OBRACE_); }
"}" { retornar(CBRACE_); }
";" { retornar(SEMIC_); }

"&&" { retornar(AND_); }
"||" { retornar(OR_); }
"==" { retornar(EQ_); }
"!=" { retornar(NEQ_); }

">" { retornar(GT_); }
">=" { retornar(GTEQ_); }
"<" { retornar(LT_); }
"<=" { retornar(LTEQ_); }

"+" { retornar(PLUS_); }
"-" { retornar(MINUS_); }
"*" { retornar(MULT_); }
"/" { retornar(DIV_); }
"!" { retornar(EXCL_); }

"=" { retornar(ASIG_); }
"," { retornar(COMMA_); }
"." { retornar(DOT_) ; }

{id} { yylval.ident = strdup(yytext);  retornar(ID_); }
{cte} { yylval.cent = atoi(yytext); retornar(CTE_); }

{comentario} { if (verbosidad) {ECHO; fprintf(stdout, "%3d.- ", yylineno); } }
{delimitador} { if (verbosidad) ECHO ; }
. { yyerror("Caracter desconocido") ;}
<<EOF>> { if (verbosidad) fprintf(stdout, "\n"); return 0;}
%%
