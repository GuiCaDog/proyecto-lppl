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

typedef struct atr /*Atributo para símbolos con más de 1 atributo*/
{ 
  char *name;
  int  refe;
  int  type;
  int  talla;
  int  desp;
} ATR;

typedef struct camp /*Atributo para símbolos con más de 1 atributo*/
{ 
  int  refe;
  int  talla;
} CAMPO;

typedef struct func /*Atributo para símbolos con más de 1 atributo*/
{ 
  int  aux;
} FUNC;

#endif  /* _HEADER_H */
/*****************************************************************************/
