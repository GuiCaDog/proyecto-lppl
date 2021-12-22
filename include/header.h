/*****************************************************************************/
/**   Ejemplo de un posible fichero de cabeceras donde situar las           **/
/** definiciones de constantes, variables y estructuras para MenosC.        **/
/** Los alumos deberan adaptarlo al desarrollo de su propio compilador.     **/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0

#define OP_EQ       0
#define OP_NEQ      1
#define OP_GT       2
#define OP_LT       3
#define OP_GTEQ     4
#define OP_LTEQ     5
#define OP_PLUS     6
#define OP_MINUS    7
#define OP_MULT     8
#define OP_DIV      9
#define OP_INC      10
#define OP_DEC      11
#define OP_NOT      12
#define OP_AND      13
#define OP_OR       14

/****************************************************** Constantes simbólicas */
#define TALLA_TIPO_SIMPLE 1 /* Talla asociada a los tipos simples */
#define TALLA_SEGENLACES 2 /* Talla del segmento de Enlaces de Control*/
/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();

extern FILE *yyin;                           /* Fichero de entrada           */
extern int   yylineno;                       /* Contador del numero de linea */
extern char *yytext;                         /* Patron detectado             */
/********* Funciones y variables externas definidas en el Programa Principal */
extern void yyerror(const char * msg) ;   /* Tratamiento de errores          */

extern int verbosidad;                   /* Flag si se desea una traza       */
extern int numErrores;              /* Contador del numero de errores        */
extern int verTdS; /* Flag para saber si mostrar la TdS */
/************************************* Variables externas definidas en las librerías */
extern int dvar; /* Desplazamiento en el Segmento de Variables */
extern int niv; /* Nivel de anidamiento "global" o "local" */
extern int si;

typedef struct lista/* Tipo de atributo para listas */
{ 
  int  refe;
  int  talla;
} LISTA;

typedef struct exp /* Tipo de atributo para expresiones*/
{ 
  int  t;
  int  v;
} EXP;
#endif  /* _HEADER_H */
/*****************************************************************************/
