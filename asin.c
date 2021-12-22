/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/asin.y"

	#include <stdio.h>
	#include <string.h>
	#include "libtds.h"
    #include "libgci.h"
	#include "header.h"

#line 79 "asin.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "asin.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER_ = 3,                   /* INTEGER_  */
  YYSYMBOL_BOOLEAN_ = 4,                   /* BOOLEAN_  */
  YYSYMBOL_STRUCT_ = 5,                    /* STRUCT_  */
  YYSYMBOL_RETURN_ = 6,                    /* RETURN_  */
  YYSYMBOL_READ_ = 7,                      /* READ_  */
  YYSYMBOL_PRINT_ = 8,                     /* PRINT_  */
  YYSYMBOL_IF_ = 9,                        /* IF_  */
  YYSYMBOL_ELSE_ = 10,                     /* ELSE_  */
  YYSYMBOL_WHILE_ = 11,                    /* WHILE_  */
  YYSYMBOL_TRUE_ = 12,                     /* TRUE_  */
  YYSYMBOL_FALSE_ = 13,                    /* FALSE_  */
  YYSYMBOL_OPAREN_ = 14,                   /* OPAREN_  */
  YYSYMBOL_CPAREN_ = 15,                   /* CPAREN_  */
  YYSYMBOL_OBRACK_ = 16,                   /* OBRACK_  */
  YYSYMBOL_CBRACK_ = 17,                   /* CBRACK_  */
  YYSYMBOL_OBRACE_ = 18,                   /* OBRACE_  */
  YYSYMBOL_CBRACE_ = 19,                   /* CBRACE_  */
  YYSYMBOL_SEMIC_ = 20,                    /* SEMIC_  */
  YYSYMBOL_AND_ = 21,                      /* AND_  */
  YYSYMBOL_OR_ = 22,                       /* OR_  */
  YYSYMBOL_EQ_ = 23,                       /* EQ_  */
  YYSYMBOL_NEQ_ = 24,                      /* NEQ_  */
  YYSYMBOL_GT_ = 25,                       /* GT_  */
  YYSYMBOL_GTEQ_ = 26,                     /* GTEQ_  */
  YYSYMBOL_LT_ = 27,                       /* LT_  */
  YYSYMBOL_LTEQ_ = 28,                     /* LTEQ_  */
  YYSYMBOL_PLUS_ = 29,                     /* PLUS_  */
  YYSYMBOL_MINUS_ = 30,                    /* MINUS_  */
  YYSYMBOL_MULT_ = 31,                     /* MULT_  */
  YYSYMBOL_DIV_ = 32,                      /* DIV_  */
  YYSYMBOL_EXCL_ = 33,                     /* EXCL_  */
  YYSYMBOL_ASIG_ = 34,                     /* ASIG_  */
  YYSYMBOL_COMMA_ = 35,                    /* COMMA_  */
  YYSYMBOL_DOT_ = 36,                      /* DOT_  */
  YYSYMBOL_ID_ = 37,                       /* ID_  */
  YYSYMBOL_CTE_ = 38,                      /* CTE_  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_programa = 40,                  /* programa  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_listaDeclaraciones = 42,        /* listaDeclaraciones  */
  YYSYMBOL_declaracion = 43,               /* declaracion  */
  YYSYMBOL_declaracionVariable = 44,       /* declaracionVariable  */
  YYSYMBOL_tipoSimple = 45,                /* tipoSimple  */
  YYSYMBOL_listaCampos = 46,               /* listaCampos  */
  YYSYMBOL_declaracionFuncion = 47,        /* declaracionFuncion  */
  YYSYMBOL_48_2 = 48,                      /* @2  */
  YYSYMBOL_49_3 = 49,                      /* $@3  */
  YYSYMBOL_parametrosFormales = 50,        /* parametrosFormales  */
  YYSYMBOL_listaParametrosFormales = 51,   /* listaParametrosFormales  */
  YYSYMBOL_bloque = 52,                    /* bloque  */
  YYSYMBOL_declaracionVariableLocal = 53,  /* declaracionVariableLocal  */
  YYSYMBOL_listaInstrucciones = 54,        /* listaInstrucciones  */
  YYSYMBOL_instruccion = 55,               /* instruccion  */
  YYSYMBOL_instruccionAsignacion = 56,     /* instruccionAsignacion  */
  YYSYMBOL_instruccionEntradaSalida = 57,  /* instruccionEntradaSalida  */
  YYSYMBOL_instruccionSeleccion = 58,      /* instruccionSeleccion  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_instruccionIteracion = 60,      /* instruccionIteracion  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_expresion = 62,                 /* expresion  */
  YYSYMBOL_expresionIgualdad = 63,         /* expresionIgualdad  */
  YYSYMBOL_expresionRelacional = 64,       /* expresionRelacional  */
  YYSYMBOL_expresionAditiva = 65,          /* expresionAditiva  */
  YYSYMBOL_expresionMultiplicativa = 66,   /* expresionMultiplicativa  */
  YYSYMBOL_expresionUnaria = 67,           /* expresionUnaria  */
  YYSYMBOL_expresionSufija = 68,           /* expresionSufija  */
  YYSYMBOL_constante = 69,                 /* constante  */
  YYSYMBOL_parametrosActuales = 70,        /* parametrosActuales  */
  YYSYMBOL_listaParametrosActuales = 71,   /* listaParametrosActuales  */
  YYSYMBOL_operadorLogico = 72,            /* operadorLogico  */
  YYSYMBOL_operadorIgualdad = 73,          /* operadorIgualdad  */
  YYSYMBOL_operadorRelacional = 74,        /* operadorRelacional  */
  YYSYMBOL_operadorAditivo = 75,           /* operadorAditivo  */
  YYSYMBOL_operadorMultiplicativo = 76,    /* operadorMultiplicativo  */
  YYSYMBOL_operadorUnario = 77             /* operadorUnario  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    32,    32,    32,    38,    39,    46,    47,    50,    54,
      64,    71,    73,    77,    82,    90,    92,    89,   103,   104,
     108,   114,   124,   136,   137,   140,   141,   144,   145,   146,
     147,   148,   151,   159,   175,   190,   197,   204,   203,   211,
     210,   218,   219,   234,   235,   250,   251,   265,   266,   280,
     281,   297,   298,   320,   321,   322,   329,   341,   353,   368,
     369,   370,   373,   374,   377,   378,   382,   383,   387,   388,
     391,   392,   393,   394,   397,   398,   401,   402,   405,   406,
     407
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER_", "BOOLEAN_",
  "STRUCT_", "RETURN_", "READ_", "PRINT_", "IF_", "ELSE_", "WHILE_",
  "TRUE_", "FALSE_", "OPAREN_", "CPAREN_", "OBRACK_", "CBRACK_", "OBRACE_",
  "CBRACE_", "SEMIC_", "AND_", "OR_", "EQ_", "NEQ_", "GT_", "GTEQ_", "LT_",
  "LTEQ_", "PLUS_", "MINUS_", "MULT_", "DIV_", "EXCL_", "ASIG_", "COMMA_",
  "DOT_", "ID_", "CTE_", "$accept", "programa", "$@1",
  "listaDeclaraciones", "declaracion", "declaracionVariable", "tipoSimple",
  "listaCampos", "declaracionFuncion", "@2", "$@3", "parametrosFormales",
  "listaParametrosFormales", "bloque", "declaracionVariableLocal",
  "listaInstrucciones", "instruccion", "instruccionAsignacion",
  "instruccionEntradaSalida", "instruccionSeleccion", "$@4",
  "instruccionIteracion", "$@5", "expresion", "expresionIgualdad",
  "expresionRelacional", "expresionAditiva", "expresionMultiplicativa",
  "expresionUnaria", "expresionSufija", "constante", "parametrosActuales",
  "listaParametrosActuales", "operadorLogico", "operadorIgualdad",
  "operadorRelacional", "operadorAditivo", "operadorMultiplicativo",
  "operadorUnario", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
#endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -89,     9,    92,   -89,   -89,   -89,    10,    92,   -89,   -89,
     -19,   -89,    89,   -89,     0,     1,    45,     7,   -89,    33,
      34,    22,    25,    61,    89,   -89,    60,    65,    67,    73,
      98,   -89,   -89,   -89,   -89,    85,   -89,    89,   100,   -89,
     -89,   -89,    92,   -89,    86,    -1,     0,    44,   105,   107,
     108,   110,   -89,   -15,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,    44,   -89,   -89,   -89,   -12,   -89,    78,    42,    63,
      82,    83,   -89,   -89,   -89,    44,    88,    44,    44,    44,
       4,    44,    44,    90,    46,    44,    44,    91,   111,   -89,
     -89,    44,   -89,   -89,    44,   -89,   -89,   -89,   -89,    44,
     -89,   -89,    44,   -89,   -89,    44,   -89,   114,    48,    95,
      95,   -89,    54,    81,    97,   -89,     5,   117,   -89,    62,
     -89,   -89,    42,    63,    82,    83,   -89,   106,   113,   119,
     120,   102,   -89,    44,    44,   -89,   -89,   -89,   -89,    35,
      35,    44,    84,   -89,   127,   -89,    87,   -89,    35,   -89,
     -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    11,    12,     0,     3,     4,     6,
       0,     7,     0,     5,    15,     0,     0,     0,     8,     0,
       0,     0,     0,     0,    18,    13,     0,     0,     0,     0,
       0,    19,    10,    14,     9,    20,    16,     0,     0,    21,
      23,    17,    25,    24,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,    26,    28,    30,    29,    31,    60,
      61,     0,    78,    79,    80,    55,    59,     0,    41,    43,
      45,    47,    49,    51,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,    66,
      67,     0,    68,    69,     0,    70,    72,    71,    73,     0,
      74,    75,     0,    76,    77,     0,    52,     0,     0,    37,
      39,    27,     0,     0,     0,    54,    64,     0,    63,     0,
      56,    22,    42,    44,    46,    48,    50,     0,     0,     0,
       0,     0,    32,     0,     0,    58,    57,    35,    36,     0,
       0,     0,     0,    65,     0,    40,     0,    34,     0,    33,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   -89,   -89,   131,    99,    13,   -89,   -89,   -89,
     -89,   -89,   103,   -89,   -89,    93,   -88,   -89,   -89,   -89,
     -89,   -89,   -89,   -47,    51,    49,    40,    47,   -72,   -89,
     -89,   -89,    12,   -89,   -89,   -89,   -89,   -89,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,     9,    10,    16,    11,    19,
      38,    30,    31,    41,    42,    45,    54,    55,    56,    57,
     129,    58,   130,   116,    68,    69,    70,    71,    72,    73,
      74,   117,   118,    91,    94,    99,   102,   105,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,    81,    85,   106,    86,    47,    48,    49,    50,     3,
      51,    48,    49,    50,    84,    51,    17,    52,    14,    82,
      18,    83,    52,   111,    87,    15,    89,    90,    12,    22,
     108,   109,   110,   126,   112,   113,    53,    29,    20,   119,
     134,    53,    48,    49,    50,    23,    51,    24,     4,     5,
      29,   144,   145,    52,    25,    44,    59,    60,    61,    26,
     150,   115,    27,   128,    21,    92,    93,    89,    90,    89,
      90,   131,    53,    62,    63,    89,    90,    64,    28,   136,
      32,    65,    66,    89,    90,    33,   142,    34,    95,    96,
      97,    98,     4,     5,   146,     4,     5,     6,    88,    89,
      90,   132,    89,    90,   147,    89,    90,   149,    89,    90,
      35,   100,   101,    36,   103,   104,    89,    90,    40,    76,
      37,    77,    78,    46,    79,   107,   137,   114,   120,   127,
     121,   133,   135,   138,   139,   140,   141,   148,    13,   124,
      39,    43,   122,   123,     0,    80,   143,     0,     0,   125
};

static const yytype_int16 yycheck[] =
{
      47,    16,    14,    75,    16,     6,     7,     8,     9,     0,
      11,     7,     8,     9,    61,    11,    16,    18,    37,    34,
      20,    36,    18,    19,    36,    12,    21,    22,    18,    16,
      77,    78,    79,   105,    81,    82,    37,    24,    37,    86,
      35,    37,     7,     8,     9,    38,    11,    14,     3,     4,
      37,   139,   140,    18,    20,    42,    12,    13,    14,    37,
     148,    15,    37,    15,    19,    23,    24,    21,    22,    21,
      22,    17,    37,    29,    30,    21,    22,    33,    17,    17,
      20,    37,    38,    21,    22,    20,   133,    20,    25,    26,
      27,    28,     3,     4,   141,     3,     4,     5,    20,    21,
      22,    20,    21,    22,    20,    21,    22,    20,    21,    22,
      37,    29,    30,    15,    31,    32,    21,    22,    18,    14,
      35,    14,    14,    37,    14,    37,    20,    37,    37,    15,
      19,    34,    15,    20,    15,    15,    34,    10,     7,    99,
      37,    42,    91,    94,    -1,    52,   134,    -1,    -1,   102
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    41,     0,     3,     4,     5,    42,    43,    44,
      45,    47,    18,    43,    37,    45,    46,    16,    20,    48,
      37,    19,    45,    38,    14,    20,    37,    37,    17,    45,
      50,    51,    20,    20,    20,    37,    15,    35,    49,    51,
      18,    52,    53,    44,    45,    54,    37,     6,     7,     8,
       9,    11,    18,    37,    55,    56,    57,    58,    60,    12,
      13,    14,    29,    30,    33,    37,    38,    62,    63,    64,
      65,    66,    67,    68,    69,    77,    14,    14,    14,    14,
      54,    16,    34,    36,    62,    14,    16,    36,    20,    21,
      22,    72,    23,    24,    73,    25,    26,    27,    28,    74,
      29,    30,    75,    31,    32,    76,    67,    37,    62,    62,
      62,    19,    62,    62,    37,    15,    62,    70,    71,    62,
      37,    19,    63,    64,    65,    66,    67,    15,    15,    59,
      61,    17,    20,    34,    35,    15,    17,    20,    20,    15,
      15,    34,    62,    71,    55,    55,    62,    20,    10,    20,
      55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    41,    40,    42,    42,    43,    43,    44,    44,
      44,    45,    45,    46,    46,    48,    49,    47,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    56,    56,    56,    57,    57,    59,    58,    61,
      60,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     6,
       6,     1,     1,     3,     4,     0,     0,     8,     0,     1,
       2,     4,     7,     0,     2,     0,     2,     3,     1,     1,
       1,     1,     4,     7,     6,     5,     5,     0,     8,     0,
       6,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     3,     1,     3,     4,     4,     1,
       1,     1,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 32 "src/asin.y"
          { dvar = 0; niv = 0; cargaContexto(niv); }
#line 1261 "asin.c"
    break;

  case 3: /* programa: $@1 listaDeclaraciones  */
#line 33 "src/asin.y"
          { if((yyvsp[0].cent) == 0) yyerror("Programa sin main declarado");
            else if((yyvsp[0].cent) == -2) yyerror("Programa con mas de una funcion main");
          }
#line 1269 "asin.c"
    break;

  case 4: /* listaDeclaraciones: declaracion  */
#line 38 "src/asin.y"
                      { (yyval.cent) = (yyvsp[0].cent); }
#line 1275 "asin.c"
    break;

  case 5: /* listaDeclaraciones: listaDeclaraciones declaracion  */
#line 40 "src/asin.y"
          { 
          if((yyvsp[-1].cent) == -1 && (yyvsp[0].cent) == -1) (yyval.cent) = -2;
          else (yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent); 
          }
#line 1284 "asin.c"
    break;

  case 6: /* declaracion: declaracionVariable  */
#line 46 "src/asin.y"
                              { (yyval.cent) = 0; }
#line 1290 "asin.c"
    break;

  case 7: /* declaracion: declaracionFuncion  */
#line 47 "src/asin.y"
                             { (yyval.cent) = (yyvsp[0].cent); }
#line 1296 "asin.c"
    break;

  case 8: /* declaracionVariable: tipoSimple ID_ SEMIC_  */
#line 51 "src/asin.y"
          { if (!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1)) 
		yyerror("Identificador repetido");
            else dvar +=  TALLA_TIPO_SIMPLE;  }
#line 1304 "asin.c"
    break;

  case 9: /* declaracionVariable: tipoSimple ID_ OBRACK_ CTE_ CBRACK_ SEMIC_  */
#line 55 "src/asin.y"
          { int numel = (yyvsp[-2].cent);
            if ((yyvsp[-2].cent) <= 0) {
               yyerror("Talla negativa para el array");
               numel = 0;
            }
            int refe = insTdA((yyvsp[-5].cent), numel);
            if ( ! insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, refe))
		yyerror("Identificador repetido");
	    else dvar += numel * TALLA_TIPO_SIMPLE; }
#line 1318 "asin.c"
    break;

  case 10: /* declaracionVariable: STRUCT_ OBRACE_ listaCampos CBRACE_ ID_ SEMIC_  */
#line 65 "src/asin.y"
          { if (! insTdS((yyvsp[-1].ident), VARIABLE, T_RECORD, niv, dvar, (yyvsp[-3].lista).refe))
		yyerror("Identificador repetido");
            else dvar += (yyvsp[-3].lista).talla;
	     }
#line 1327 "asin.c"
    break;

  case 11: /* tipoSimple: INTEGER_  */
#line 72 "src/asin.y"
          { (yyval.cent) = T_ENTERO; }
#line 1333 "asin.c"
    break;

  case 12: /* tipoSimple: BOOLEAN_  */
#line 74 "src/asin.y"
          { (yyval.cent) = T_LOGICO; }
#line 1339 "asin.c"
    break;

  case 13: /* listaCampos: tipoSimple ID_ SEMIC_  */
#line 78 "src/asin.y"
          { (yyval.lista).refe = insTdR(-1, (yyvsp[-1].ident), (yyvsp[-2].cent), 0);
	    if ( (yyval.lista).refe == -1) 
		yyerror("Campo repetido");
            (yyval.lista).talla = TALLA_TIPO_SIMPLE; }
#line 1348 "asin.c"
    break;

  case 14: /* listaCampos: listaCampos tipoSimple ID_ SEMIC_  */
#line 83 "src/asin.y"
          { (yyval.lista).refe = insTdR((yyvsp[-3].lista).refe, (yyvsp[-1].ident), (yyvsp[-2].cent), (yyvsp[-3].lista).talla);
	    if ( (yyval.lista).refe == -1) 
		yyerror("Campo repetido");
            (yyval.lista).talla = (yyvsp[-3].lista).talla + TALLA_TIPO_SIMPLE; }
#line 1357 "asin.c"
    break;

  case 15: /* @2: %empty  */
#line 90 "src/asin.y"
          { niv+=1; cargaContexto(niv); (yyval.cent) = dvar; dvar = 0; }
#line 1363 "asin.c"
    break;

  case 16: /* $@3: %empty  */
#line 92 "src/asin.y"
          { if( ! insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), niv-1, -1, (yyvsp[-1].lista).refe)) {
	         yyerror("Identificador de funcion repetido"); 
              }
          }
#line 1372 "asin.c"
    break;

  case 17: /* declaracionFuncion: tipoSimple ID_ @2 OPAREN_ parametrosFormales CPAREN_ $@3 bloque  */
#line 97 "src/asin.y"
          {  if(strcmp((yyvsp[-6].ident), "main") == 0) (yyval.cent) = -1;
             else (yyval.cent) = 0;
             if(verTdS) mostrarTdS(); descargaContexto(niv);  niv-=1; dvar = (yyvsp[-5].cent); 
          }
#line 1381 "asin.c"
    break;

  case 18: /* parametrosFormales: %empty  */
#line 103 "src/asin.y"
          { (yyval.lista).refe = insTdD(-1, T_VACIO); }
#line 1387 "asin.c"
    break;

  case 19: /* parametrosFormales: listaParametrosFormales  */
#line 105 "src/asin.y"
          { (yyval.lista).refe = (yyvsp[0].lista).refe; }
#line 1393 "asin.c"
    break;

  case 20: /* listaParametrosFormales: tipoSimple ID_  */
#line 109 "src/asin.y"
          { (yyval.lista).talla = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE;
            (yyval.lista).refe = insTdD(-1, (yyvsp[-1].cent));
            if( ! insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -(yyval.lista).talla, -1))
	       yyerror("Parametro repetido"); 
          }
#line 1403 "asin.c"
    break;

  case 21: /* listaParametrosFormales: tipoSimple ID_ COMMA_ listaParametrosFormales  */
#line 115 "src/asin.y"
          { (yyval.lista).talla = (yyvsp[0].lista).talla + TALLA_TIPO_SIMPLE;
            (yyval.lista).refe = insTdD((yyvsp[0].lista).refe, (yyvsp[-3].cent));
            if( ! insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, -(yyval.lista).talla, -1))
	       yyerror("Parametro repetido"); 
          }
#line 1413 "asin.c"
    break;

  case 22: /* bloque: OBRACE_ declaracionVariableLocal listaInstrucciones RETURN_ expresion SEMIC_ CBRACE_  */
#line 125 "src/asin.y"
      {
        INF inf = obtTdD(-1);
        if (inf.tipo == T_ERROR) {

           yyerror("Error en la declaracion de la funcion.");
        }
        else if (inf.tipo != (yyvsp[-2].exp).t) {
            yyerror("Tipos de retorno no compatibles.");
        }
      }
#line 1428 "asin.c"
    break;

  case 32: /* instruccionAsignacion: ID_ ASIG_ expresion SEMIC_  */
#line 152 "src/asin.y"
      {
        SIMB simb = obtTdS((yyvsp[-3].ident)); 
        if (simb.t == T_ERROR) yyerror("Identificador no declarado.");
        else if ((yyvsp[-1].exp).t != T_ERROR) {
            if (simb.t != (yyvsp[-1].exp).t) { yyerror("Asignacion con tipos no compatibles."); }
        }
      }
#line 1440 "asin.c"
    break;

  case 33: /* instruccionAsignacion: ID_ OBRACK_ expresion CBRACK_ ASIG_ expresion SEMIC_  */
#line 160 "src/asin.y"
      {
        if ((yyvsp[-4].exp).t != T_ERROR && (yyvsp[-4].exp).t != T_ENTERO) { yyerror("Indexacion con expresion no entera."); }
        else {
            SIMB simb = obtTdS((yyvsp[-6].ident));
            if (simb.t != T_ERROR && (yyvsp[-4].exp).t != T_ERROR && (yyvsp[-1].exp).t != T_ERROR) {
                if (simb.t != T_ARRAY) { yyerror("Indexacion en identificador no de tipo array."); }
                else {
                    DIM dim = obtTdA(simb.ref);
                    if (dim.telem != (yyvsp[-1].exp).t) {
                        yyerror("Asignacion con tipos no compatibles");
                    }
                }
            }
        }
      }
#line 1460 "asin.c"
    break;

  case 34: /* instruccionAsignacion: ID_ DOT_ ID_ ASIG_ expresion SEMIC_  */
#line 176 "src/asin.y"
      {
        SIMB simb = obtTdS((yyvsp[-5].ident)); 
        if (simb.t != T_ERROR && (yyvsp[-1].exp).t != T_ERROR) {
            if (simb.t != T_RECORD) { yyerror("Acceso a campo de identificador no de tipo registro."); }
            else {
                CAMP camp = obtTdR(simb.ref, (yyvsp[-5].ident));
                if (camp.t != (yyvsp[-1].exp).t) {
                    yyerror("Asignacion con tipos no compatibles");
                }
            }
        }
      }
#line 1477 "asin.c"
    break;

  case 35: /* instruccionEntradaSalida: READ_ OPAREN_ ID_ CPAREN_ SEMIC_  */
#line 191 "src/asin.y"
      {
        SIMB simb = obtTdS((yyvsp[-2].ident)); 
        if (simb.t != T_ERROR) {
            if (simb.t != T_ENTERO) { yyerror("Identificador con tipo no entero."); }
        }
  }
#line 1488 "asin.c"
    break;

  case 36: /* instruccionEntradaSalida: PRINT_ OPAREN_ expresion CPAREN_ SEMIC_  */
#line 198 "src/asin.y"
      {
        if ((yyvsp[-2].exp).t != T_ERROR && (yyvsp[-2].exp).t != T_ENTERO) { yyerror("Expresion con tipo no entero."); }
      }
#line 1496 "asin.c"
    break;

  case 37: /* $@4: %empty  */
#line 204 "src/asin.y"
      { 
        if ((yyvsp[0].exp).t != T_ERROR && (yyvsp[0].exp).t != T_LOGICO) { yyerror("Expresion de if con tipo no booleano."); } 
      }
#line 1504 "asin.c"
    break;

  case 39: /* $@5: %empty  */
#line 211 "src/asin.y"
      {
        if ((yyvsp[0].exp).t != T_ERROR && (yyvsp[0].exp).t != T_LOGICO) { yyerror("Expresion de while no booleana."); }
      }
#line 1512 "asin.c"
    break;

  case 41: /* expresion: expresionIgualdad  */
#line 218 "src/asin.y"
                            { (yyval.exp).t = (yyvsp[0].exp).t; }
#line 1518 "asin.c"
    break;

  case 42: /* expresion: expresion operadorLogico expresionIgualdad  */
#line 220 "src/asin.y"
    {
        (yyval.exp).t = T_ERROR;
        if ((yyvsp[-2].exp).t != T_ERROR && (yyvsp[0].exp).t != T_ERROR) {
            if((yyvsp[-2].exp).t != (yyvsp[0].exp).t)
                yyerror("Los tipos no son equivalentes");
            else if ((yyvsp[-2].exp).t != T_LOGICO)
                yyerror("Las expresion deber ser lógicas");
            else
                (yyval.exp).t = T_LOGICO;
        }
    }
#line 1534 "asin.c"
    break;

  case 43: /* expresionIgualdad: expresionRelacional  */
#line 234 "src/asin.y"
                              { (yyval.exp).t = (yyvsp[0].exp).t; }
#line 1540 "asin.c"
    break;

  case 44: /* expresionIgualdad: expresionIgualdad operadorIgualdad expresionRelacional  */
#line 236 "src/asin.y"
    {
        (yyval.exp).t = T_ERROR;
        if ((yyvsp[-2].exp).t != T_ERROR && (yyvsp[0].exp).t != T_ERROR) {
            if ((yyvsp[-2].exp).t != (yyvsp[0].exp).t)
                yyerror("Los tipos no son equivalentes.");
            else if ((yyvsp[-2].exp).t != T_LOGICO || (yyvsp[-2].exp).t != T_ENTERO)
                yyerror("Las expresiones deben ser lógicas o enteros");
            else {
                (yyval.exp).t = T_LOGICO;
            }
        }
    }
#line 1557 "asin.c"
    break;

  case 45: /* expresionRelacional: expresionAditiva  */
#line 250 "src/asin.y"
                           { (yyval.exp).t = (yyvsp[0].exp).t; }
#line 1563 "asin.c"
    break;

  case 46: /* expresionRelacional: expresionRelacional operadorRelacional expresionAditiva  */
#line 252 "src/asin.y"
    {
        (yyval.exp).t = T_ERROR;
        if ((yyvsp[-2].exp).t != T_ERROR && (yyvsp[0].exp).t != T_ERROR) {
            if ((yyvsp[-2].exp).t != (yyvsp[0].exp).t)
                yyerror("Los tipos no son equivalentes.");
            else if ((yyvsp[-2].exp).t != T_ENTERO)
                yyerror("Las expresiones deben ser enteras");
            else
                (yyval.exp).t = T_LOGICO;
        }
    }
#line 1579 "asin.c"
    break;

  case 47: /* expresionAditiva: expresionMultiplicativa  */
#line 265 "src/asin.y"
                                  { (yyval.exp).t = (yyvsp[0].exp).t; }
#line 1585 "asin.c"
    break;

  case 48: /* expresionAditiva: expresionAditiva operadorAditivo expresionMultiplicativa  */
#line 267 "src/asin.y"
    {
        (yyval.exp).t = T_ERROR;
        if ((yyvsp[-2].exp).t != T_ERROR && (yyvsp[0].exp).t != T_ERROR) {
            if ((yyvsp[-2].exp).t != (yyvsp[0].exp).t)
                yyerror("Los tipos no son equivalentes.");
            else if ((yyvsp[-2].exp).t != T_ENTERO)
                yyerror("Las expresiones deben ser enteras");
            else
                (yyval.exp).t = T_ENTERO;
        }
    }
#line 1601 "asin.c"
    break;

  case 49: /* expresionMultiplicativa: expresionUnaria  */
#line 280 "src/asin.y"
                          { (yyval.exp).t = (yyvsp[0].exp).t; (yyval.exp).v = (yyvsp[0].exp).v; }
#line 1607 "asin.c"
    break;

  case 50: /* expresionMultiplicativa: expresionMultiplicativa operadorMultiplicativo expresionUnaria  */
#line 282 "src/asin.y"
    {
        (yyval.exp).t = T_ERROR;
        if ((yyvsp[-2].exp).t != T_ERROR && (yyvsp[0].exp).t != T_ERROR) {
            if ((yyvsp[-2].exp).t != (yyvsp[0].exp).t)
                yyerror("Los tipos no son equivalentes.");
            else if ((yyvsp[-2].exp).t != T_ENTERO)
                yyerror("Las expresiones deben ser enteras.");
            else
                (yyval.exp).t = T_ENTERO;
        }
        (yyval.exp).v = creaVarTemp();
        emite((yyvsp[-1].cent), crArgEnt((yyvsp[-2].exp).v), crArgEnt((yyvsp[0].exp).v), crArgPos(niv, (yyval.exp).v));
    }
#line 1625 "asin.c"
    break;

  case 51: /* expresionUnaria: expresionSufija  */
#line 297 "src/asin.y"
                          { (yyval.exp).t = (yyvsp[0].exp).t; }
#line 1631 "asin.c"
    break;

  case 52: /* expresionUnaria: operadorUnario expresionUnaria  */
#line 299 "src/asin.y"
    {
        (yyval.exp).t = T_ERROR;
        if ((yyvsp[0].exp).t != T_ERROR) {
            if ((yyvsp[0].exp).t == T_ENTERO) {
                if ((yyvsp[-1].cent) == OP_NOT)
                    yyerror("El operador NOT es incompatible con enteros");
                else
                    (yyval.exp).t = T_ENTERO;
            } else if ((yyvsp[0].exp).t == T_LOGICO) {
                if ((yyvsp[-1].cent) != OP_MINUS && (yyvsp[-1].cent) != OP_PLUS)
                    (yyval.exp).t = T_LOGICO;
                else
                    yyerror("La suma y la resta son operadores binarios. Es incompatible con tipos logicos.");
            } else {
                yyerror("Los tipos no son equivalentes.");
            }
        }
    }
#line 1654 "asin.c"
    break;

  case 53: /* expresionSufija: constante  */
#line 320 "src/asin.y"
                    {(yyval.exp).t = (yyvsp[0].exp).t; }
#line 1660 "asin.c"
    break;

  case 54: /* expresionSufija: OPAREN_ expresion CPAREN_  */
#line 321 "src/asin.y"
                                    {(yyval.exp).t = (yyvsp[-1].exp).t; }
#line 1666 "asin.c"
    break;

  case 55: /* expresionSufija: ID_  */
#line 323 "src/asin.y"
          {
            (yyval.exp).t = T_ERROR;
            SIMB simb = obtTdS((yyvsp[0].ident));
            if(simb.t == T_ERROR) { yyerror("Identificador no declarado"); }
            else { (yyval.exp).t = simb.t; }
          }
#line 1677 "asin.c"
    break;

  case 56: /* expresionSufija: ID_ DOT_ ID_  */
#line 330 "src/asin.y"
    {
        (yyval.exp).t = T_ERROR;
        SIMB simb = obtTdS((yyvsp[-2].ident));
        if (simb.t == T_ERROR) { yyerror("Identificador no declarado."); }
        else if (simb.t != T_RECORD) { yyerror("Acceso a campo de identificador no de tipo registro."); }
        else {
            CAMP camp = obtTdR(simb.ref, (yyvsp[0].ident));
            if (camp.t == T_ERROR) { yyerror("Acceso a campo no declarado."); }   
            else { (yyval.exp).t = camp.t; }
        }
    }
#line 1693 "asin.c"
    break;

  case 57: /* expresionSufija: ID_ OBRACK_ expresion CBRACK_  */
#line 342 "src/asin.y"
    {   
        (yyval.exp).t = T_ERROR;
        if ((yyvsp[-1].exp).t != T_ENTERO) { yyerror("Indexacion con expresion no entera."); }
        SIMB simb = obtTdS((yyvsp[-3].ident));
        if (simb.t == T_ERROR) { yyerror("Identificador no declarado."); }
        else if (simb.t != T_ARRAY) { yyerror("Acceso a contenido de identificador no de tipo array."); }
        else {
            DIM dim = obtTdA(simb.ref);
            (yyval.exp).t = dim.telem;
            }
    }
#line 1709 "asin.c"
    break;

  case 58: /* expresionSufija: ID_ OPAREN_ parametrosActuales CPAREN_  */
#line 354 "src/asin.y"
    {
        (yyval.exp).t = T_ERROR;
        SIMB simb = obtTdS((yyvsp[-3].ident));
        if (simb.t == T_ERROR) { yyerror("No existe ninguna variable con ese identificador."); }
        INF inf = obtTdD(simb.ref);
        if (inf.tipo == T_ERROR) { yyerror("No existe ninguna función con ese identificador."); }
        else if ( ! cmpDom(simb.ref, (yyvsp[-1].lista).refe))
	        yyerror("Dominios incompatibles");
        else 
        { (yyval.exp).t = inf.tipo; }
    }
#line 1725 "asin.c"
    break;

  case 59: /* constante: CTE_  */
#line 368 "src/asin.y"
               { (yyval.exp).t = T_ENTERO; }
#line 1731 "asin.c"
    break;

  case 60: /* constante: TRUE_  */
#line 369 "src/asin.y"
                { (yyval.exp).t = T_LOGICO; }
#line 1737 "asin.c"
    break;

  case 61: /* constante: FALSE_  */
#line 370 "src/asin.y"
                 { (yyval.exp).t = T_LOGICO; }
#line 1743 "asin.c"
    break;

  case 62: /* parametrosActuales: %empty  */
#line 373 "src/asin.y"
          {(yyval.lista).refe = insTdD(-1, T_VACIO);}
#line 1749 "asin.c"
    break;

  case 63: /* parametrosActuales: listaParametrosActuales  */
#line 374 "src/asin.y"
                                  {(yyval.lista).refe = (yyvsp[0].lista).refe;}
#line 1755 "asin.c"
    break;

  case 64: /* listaParametrosActuales: expresion  */
#line 377 "src/asin.y"
                    { (yyval.lista).refe = insTdD(-1, (yyvsp[0].exp).t); }
#line 1761 "asin.c"
    break;

  case 65: /* listaParametrosActuales: expresion COMMA_ listaParametrosActuales  */
#line 379 "src/asin.y"
          { (yyval.lista).refe = insTdD((yyvsp[0].lista).refe, (yyvsp[-2].exp).t); }
#line 1767 "asin.c"
    break;

  case 66: /* operadorLogico: AND_  */
#line 382 "src/asin.y"
                    { (yyval.cent) = OP_AND; }
#line 1773 "asin.c"
    break;

  case 67: /* operadorLogico: OR_  */
#line 383 "src/asin.y"
                    { (yyval.cent) = OP_OR;  }
#line 1779 "asin.c"
    break;

  case 68: /* operadorIgualdad: EQ_  */
#line 387 "src/asin.y"
                    { (yyval.cent) = EIGUAL; }
#line 1785 "asin.c"
    break;

  case 69: /* operadorIgualdad: NEQ_  */
#line 388 "src/asin.y"
                    { (yyval.cent) = EDIST; }
#line 1791 "asin.c"
    break;

  case 70: /* operadorRelacional: GT_  */
#line 391 "src/asin.y"
                    { (yyval.cent) = EMAY; }
#line 1797 "asin.c"
    break;

  case 71: /* operadorRelacional: LT_  */
#line 392 "src/asin.y"
                    { (yyval.cent) = EMEN; }
#line 1803 "asin.c"
    break;

  case 72: /* operadorRelacional: GTEQ_  */
#line 393 "src/asin.y"
                    { (yyval.cent) = EMAYEQ; }
#line 1809 "asin.c"
    break;

  case 73: /* operadorRelacional: LTEQ_  */
#line 394 "src/asin.y"
                    { (yyval.cent) = EMENEQ; }
#line 1815 "asin.c"
    break;

  case 74: /* operadorAditivo: PLUS_  */
#line 397 "src/asin.y"
                    { (yyval.cent) = ESUM; }
#line 1821 "asin.c"
    break;

  case 75: /* operadorAditivo: MINUS_  */
#line 398 "src/asin.y"
                    { (yyval.cent) = EDIF; }
#line 1827 "asin.c"
    break;

  case 76: /* operadorMultiplicativo: MULT_  */
#line 401 "src/asin.y"
                    { (yyval.cent) = EMULT; }
#line 1833 "asin.c"
    break;

  case 77: /* operadorMultiplicativo: DIV_  */
#line 402 "src/asin.y"
                    { (yyval.cent) = EDIVI; }
#line 1839 "asin.c"
    break;

  case 78: /* operadorUnario: PLUS_  */
#line 405 "src/asin.y"
                    { (yyval.cent) = ESUM; }
#line 1845 "asin.c"
    break;

  case 79: /* operadorUnario: MINUS_  */
#line 406 "src/asin.y"
                    { (yyval.cent) = EDIF; }
#line 1851 "asin.c"
    break;

  case 80: /* operadorUnario: EXCL_  */
#line 407 "src/asin.y"
                    { (yyval.cent) = ESIG; }
#line 1857 "asin.c"
    break;


#line 1861 "asin.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 409 "src/asin.y"

