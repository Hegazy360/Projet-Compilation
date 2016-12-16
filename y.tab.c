/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "cpyrr.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "tablex.h"
#include "tabrep.h"
#include "tabdecl.h"
#include "assnom.h"
#include "tabregion.h"
#include "arbre.h"
#include "pile.h"
extern struct record_region tabreg[MAXREG];
extern struct tablex tablexico[500];
extern struct element tabdecl[MAXDECL];
extern char* yytext;
extern int yylex();
extern int yyerror();
extern int numligne;
extern int indice_declaration;
extern int pileRegion[60];
extern int tabrep[1000];
extern int indice_representation;
extern int num_association_nom;
int type_retourne;
int num_region=0;
int num_parametres=0;
int num_lexico;
int num_decl;
int num_champ;
int num_lex_champ;
int dimension;
int borne_sup[15];
int borne_inf[15];
int NIS;
int tailleExecution;
int erreur = 0;
int first_representation;
int taille = 0;
int num_lexico_fp=0;
char flag = 0;

#line 107 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROG = 258,
    DEBUT = 259,
    FIN = 260,
    STRUCT = 261,
    FSTRUCT = 262,
    TABLEAU = 263,
    DE = 264,
    VARIABLE = 265,
    PROCEDURE = 266,
    FONCTION = 267,
    RETOURNE = 268,
    VIDE = 269,
    POINT_VIRGULE = 270,
    DEUX_POINTS = 271,
    POINT = 272,
    POINT_2 = 273,
    CROCHET_OUVRANT = 274,
    CROCHET_FERMANT = 275,
    VIRGULE = 276,
    PARENTHESE_OUVRANTE = 277,
    PARENTHESE_FERMANTE = 278,
    TYPE = 279,
    IDF = 280,
    ENTIER = 281,
    REEL = 282,
    BOOLEEN = 283,
    CARACTERE = 284,
    CHAINE = 285,
    CSTE_ENTIERE = 286,
    CSTE_REEL = 287,
    SI = 288,
    ALORS = 289,
    SINON = 290,
    TANT_QUE = 291,
    FAIRE = 292,
    OPAFF = 293,
    PLUS = 294,
    MOINS = 295,
    MULT = 296,
    DIV = 297,
    OP_COMP = 298,
    BOOL = 299
  };
#endif
/* Tokens.  */
#define PROG 258
#define DEBUT 259
#define FIN 260
#define STRUCT 261
#define FSTRUCT 262
#define TABLEAU 263
#define DE 264
#define VARIABLE 265
#define PROCEDURE 266
#define FONCTION 267
#define RETOURNE 268
#define VIDE 269
#define POINT_VIRGULE 270
#define DEUX_POINTS 271
#define POINT 272
#define POINT_2 273
#define CROCHET_OUVRANT 274
#define CROCHET_FERMANT 275
#define VIRGULE 276
#define PARENTHESE_OUVRANTE 277
#define PARENTHESE_FERMANTE 278
#define TYPE 279
#define IDF 280
#define ENTIER 281
#define REEL 282
#define BOOLEEN 283
#define CARACTERE 284
#define CHAINE 285
#define CSTE_ENTIERE 286
#define CSTE_REEL 287
#define SI 288
#define ALORS 289
#define SINON 290
#define TANT_QUE 291
#define FAIRE 292
#define OPAFF 293
#define PLUS 294
#define MOINS 295
#define MULT 296
#define DIV 297
#define OP_COMP 298
#define BOOL 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 246 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    52,    55,    56,    59,    60,    63,    66,
      67,    71,    72,    73,    74,    77,    77,    80,    80,    81,
      81,    84,    87,    88,    91,    91,    94,    95,    98,    98,
     101,   102,   105,   106,   107,   108,   109,   112,   112,   115,
     115,   115,   115,   118,   118,   118,   118,   121,   124,   125,
     126,   129,   129,   130,   133,   134,   135,   136,   137,   138,
     141,   142,   143,   144,   147,   148,   151,   152,   155,   158,
     159,   162,   163,   166,   169,   170,   173,   176,   176,   179,
     180,   183,   184,   185,   186,   189,   190,   193,   196,   197,
     198,   201,   202,   203,   206,   207,   208,   209,   210,   213,
     214,   215
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROG", "DEBUT", "FIN", "STRUCT",
  "FSTRUCT", "TABLEAU", "DE", "VARIABLE", "PROCEDURE", "FONCTION",
  "RETOURNE", "VIDE", "POINT_VIRGULE", "DEUX_POINTS", "POINT", "POINT_2",
  "CROCHET_OUVRANT", "CROCHET_FERMANT", "VIRGULE", "PARENTHESE_OUVRANTE",
  "PARENTHESE_FERMANTE", "TYPE", "IDF", "ENTIER", "REEL", "BOOLEEN",
  "CARACTERE", "CHAINE", "CSTE_ENTIERE", "CSTE_REEL", "SI", "ALORS",
  "SINON", "TANT_QUE", "FAIRE", "OPAFF", "PLUS", "MOINS", "MULT", "DIV",
  "OP_COMP", "BOOL", "$accept", "programme", "$@1", "corps",
  "liste_declarations", "liste_instructions", "suite_liste_inst",
  "declaration", "declaration_type", "$@2", "suite_declaration_type",
  "$@3", "$@4", "dimension", "liste_dimensions", "une_dimension", "$@5",
  "liste_champs", "un_champ", "$@6", "nom_type", "type_simple",
  "declaration_variable", "$@7", "declaration_procedure", "@8", "$@9",
  "$@10", "declaration_fonction", "@11", "$@12", "@13", "liste_parametres",
  "liste_param", "un_param", "$@14", "instruction",
  "instruction_point_virgule", "instruction_cond", "resultat_retourne",
  "appel", "liste_arguments", "liste_args", "un_arg", "condition",
  "tant_que", "affectation", "$@15", "expression", "variable", "indices",
  "exparith", "e1", "e2", "e3", "exprel", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -131

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-131)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,  -131,    52,     9,  -131,     4,    34,  -131,  -131,    84,
    -131,   107,  -131,    45,    99,   103,  -131,  -131,    53,  -131,
      69,    53,    95,    -2,  -131,  -131,  -131,  -131,  -131,   106,
    -131,  -131,  -131,  -131,  -131,   105,  -131,    98,   100,  -131,
    -131,  -131,  -131,  -131,    19,  -131,  -131,  -131,  -131,  -131,
     105,    81,    73,    29,  -131,  -131,    64,    51,  -131,   108,
      81,    92,    53,  -131,  -131,  -131,   104,    90,   114,  -131,
    -131,   115,    64,   109,    93,    22,    64,    64,    64,    64,
      64,   113,  -131,    71,  -131,  -131,    64,   107,   112,   118,
      64,    72,   116,   116,   102,    22,  -131,    64,  -131,  -131,
      29,    29,  -131,  -131,  -131,    64,  -131,   119,   110,   111,
     108,  -131,  -131,  -131,  -131,  -131,  -131,   121,  -131,  -131,
      35,  -131,   128,  -131,  -131,  -131,   120,  -131,  -131,   107,
     107,   122,  -131,  -131,   123,   127,     9,    77,   124,   125,
    -131,  -131,  -131,   130,   131,  -131,    35,  -131,  -131,  -131,
     136,  -131,    64,   138,  -131,    77,  -131,     9,   139,     0,
     140,   135,  -131,    72,  -131,  -131,    72,  -131,  -131,  -131,
      64,   141,  -131,  -131,  -131,    64,  -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     0,     0,    39,    43,     0,
       3,     0,     5,     6,     0,     0,    13,    14,    66,    62,
      81,     0,     0,     0,    59,    56,    57,    58,     9,     0,
      55,    61,    64,    65,    60,    77,    37,     0,     0,    15,
       4,     7,    11,    12,     0,    95,    96,    63,    98,    67,
      97,    79,    87,    90,    93,    80,     0,     0,    68,    82,
       0,     0,     0,     8,    10,    54,     0,     0,     0,    40,
      44,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,     0,    69,     0,    71,    73,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,   101,     0,    94,    99,
      88,    89,    91,    92,    85,     0,    70,     0,    74,     0,
      84,    78,    31,    32,    33,    34,    35,     0,    38,    30,
      50,    41,     0,    17,    19,    16,     0,    72,    86,     0,
       0,     0,    51,    53,     0,    48,     0,     0,     0,     0,
     100,    75,    76,     0,     0,    47,    50,    42,    45,    28,
       0,    26,     0,     0,    36,     0,    49,     0,     0,     0,
       0,    22,    24,     0,    52,    46,     0,    18,    27,    21,
       0,     0,    20,    29,    23,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -130,   145,   -10,  -131,  -131,    25,  -131,
    -131,  -131,  -131,  -131,    -9,  -131,  -131,  -131,     5,  -131,
     -73,  -113,    30,  -131,    31,  -131,  -131,  -131,    41,  -131,
    -131,  -131,    70,    16,  -131,  -131,   142,  -131,  -131,  -131,
      42,  -131,  -131,    61,  -131,  -131,  -131,  -131,  -131,    44,
      78,   -18,   -40,     3,    36,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,    23,    13,    14,    71,
     125,   138,   139,   153,   160,   161,   171,   150,   151,   158,
     118,   119,    15,    68,    16,    37,    92,   136,    17,    38,
      93,   157,   121,   134,   135,   144,    28,    29,    30,    47,
      48,    58,    83,    84,    32,    33,    34,    67,    49,    50,
      59,    60,    52,    53,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    40,    61,    63,    75,     1,   147,   167,     6,     7,
       8,    18,    19,     5,     6,     7,     8,    18,    19,     6,
       7,     8,     9,    20,   148,   149,    74,   165,     9,    20,
      24,    21,    95,     9,    22,    25,    26,    21,    81,    85,
      22,    72,   164,    88,    20,    98,    27,    31,    24,    35,
      45,    46,     4,    25,    26,     6,     7,     8,    99,    36,
     132,    77,    78,    73,    27,    31,   133,    35,   107,     9,
      79,    80,   111,    72,    82,    44,    20,   108,    20,   126,
     100,   101,    45,    46,    45,    46,    72,    85,    56,    20,
     172,    57,   105,   173,   106,    45,    46,   112,   113,   114,
     115,   116,   117,   113,   114,   115,   116,   117,   123,    39,
     124,     5,    77,    78,    42,   102,   103,    62,    43,   141,
     142,    65,    66,    69,    76,    70,    87,    86,    90,    89,
      91,    94,    96,   104,   162,   109,    97,    56,   120,   128,
     131,   137,   146,   140,   152,   129,   145,   155,   130,   149,
     154,   159,   162,   143,   163,   166,   170,   176,    41,   175,
     169,   174,   156,   122,   168,    64,   127,   110
};

static const yytype_uint8 yycheck[] =
{
      18,    11,    21,     5,    44,     3,   136,     7,    10,    11,
      12,    13,    14,     4,    10,    11,    12,    13,    14,    10,
      11,    12,    24,    25,   137,    25,    44,   157,    24,    25,
       5,    33,    72,    24,    36,     5,     5,    33,    56,    57,
      36,    22,   155,    62,    25,    23,     5,     5,    23,     5,
      31,    32,     0,    23,    23,    10,    11,    12,    76,    25,
      25,    39,    40,    44,    23,    23,    31,    23,    86,    24,
      41,    42,    90,    22,    23,    22,    25,    87,    25,    97,
      77,    78,    31,    32,    31,    32,    22,   105,    19,    25,
     163,    22,    21,   166,    23,    31,    32,    25,    26,    27,
      28,    29,    30,    26,    27,    28,    29,    30,     6,    25,
       8,     4,    39,    40,    15,    79,    80,    22,    15,   129,
     130,    15,    17,    25,    43,    25,    34,    19,    38,    25,
      16,    16,    23,    20,   152,    23,    43,    19,    22,    20,
      19,    13,    15,    23,    19,    35,    23,    16,    37,    25,
      20,    15,   170,    31,    16,    16,    21,   175,    13,    18,
      20,   170,   146,    93,   159,    23,   105,    89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    46,    47,     0,     4,    10,    11,    12,    24,
      48,    49,    50,    52,    53,    67,    69,    73,    13,    14,
      25,    33,    36,    51,    53,    67,    69,    73,    81,    82,
      83,    85,    89,    90,    91,    94,    25,    70,    74,    25,
      50,    49,    15,    15,    22,    31,    32,    84,    85,    93,
      94,    96,    97,    98,    99,   100,    19,    22,    86,    95,
      96,   100,    22,     5,    81,    15,    17,    92,    68,    25,
      25,    54,    22,    44,    96,    97,    43,    39,    40,    41,
      42,    96,    23,    87,    88,    96,    19,    34,   100,    25,
      38,    16,    71,    75,    16,    97,    23,    43,    23,    96,
      98,    98,    99,    99,    20,    21,    23,    96,    50,    23,
      95,    96,    25,    26,    27,    28,    29,    30,    65,    66,
      22,    77,    77,     6,     8,    55,    96,    88,    20,    35,
      37,    19,    25,    31,    78,    79,    72,    13,    56,    57,
      23,    50,    50,    31,    80,    23,    15,    48,    66,    25,
      62,    63,    19,    58,    20,    16,    78,    76,    64,    15,
      59,    60,    96,    16,    66,    48,    16,     7,    63,    20,
      21,    61,    65,    65,    59,    18,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    47,    46,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    52,    52,    54,    53,    56,    55,    57,
      55,    58,    59,    59,    61,    60,    62,    62,    64,    63,
      65,    65,    66,    66,    66,    66,    66,    68,    67,    70,
      71,    72,    69,    74,    75,    76,    73,    77,    78,    78,
      78,    80,    79,    79,    81,    81,    81,    81,    81,    81,
      82,    82,    82,    82,    83,    83,    84,    84,    85,    86,
      86,    87,    87,    88,    89,    89,    90,    92,    91,    93,
      93,    94,    94,    94,    94,    95,    95,    96,    97,    97,
      97,    98,    98,    98,    99,    99,    99,    99,    99,   100,
     100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     1,     1,     2,     3,     1,
       2,     2,     2,     1,     1,     0,     5,     0,     5,     0,
       5,     3,     1,     3,     0,     4,     1,     3,     0,     4,
       1,     1,     1,     1,     1,     1,     4,     0,     5,     0,
       0,     0,     7,     0,     0,     0,     9,     3,     1,     3,
       0,     0,     4,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     0,     1,     2,     2,
       3,     1,     3,     1,     4,     6,     6,     0,     4,     1,
       1,     1,     2,     3,     4,     3,     4,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     1,     3,
       5,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 52 "cpyrr.y" /* yacc.c:1646  */
    {empile(num_region);}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "cpyrr.y" /* yacc.c:1646  */
    {inserer_table_region(NIS,(yyval));(yyval)=concat_father_son(creer_noeud(-1,-999),(yyvsp[0]));}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 55 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_brother((yyvsp[-1]),(yyvsp[0]));}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 56 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=insere_arbre((yyvsp[-1]),(yyvsp[0]));}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "cpyrr.y" /* yacc.c:1646  */
    {depile();(yyval)=(yyvsp[-1]);}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=insere_arbre((yyvsp[-1]),(yyvsp[0]));}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 71 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 72 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 73 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 74 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 77 "cpyrr.y" /* yacc.c:1646  */
    {num_lexico = indice((yyvsp[0]));empiler(create_ElementPile(-1,FLOAT,CHAR,(yyvsp[0])));}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 77 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_DECL,-999),concat_father_brother(creer_noeud(T_IDF,-999),(yyvsp[0])));}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 80 "cpyrr.y" /* yacc.c:1646  */
    {first_representation = indice_representation;indice_representation++;}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 80 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_STRUCT,-999),(yyvsp[-2]));inserer_tabrep(first_representation,num_champ);inserer_struct(num_region,first_representation,num_lexico,taille_struct(first_representation));num_champ=0;}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 81 "cpyrr.y" /* yacc.c:1646  */
    {flag = 1;first_representation = indice_representation;indice_representation+=2;}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 81 "cpyrr.y" /* yacc.c:1646  */
    {num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_tabrep(first_representation,association_nom());inserer_tabrep(first_representation+1,dimension);inserer_tab(num_region,first_representation,num_lexico,taille_tab(first_representation));dimension = 0;flag=0;}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 87 "cpyrr.y" /* yacc.c:1646  */
    {dimension++;(yyval)=(yyvsp[0]);}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 88 "cpyrr.y" /* yacc.c:1646  */
    {dimension++;}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 91 "cpyrr.y" /* yacc.c:1646  */
    {inserer_tabrep(indice_representation,(yyvsp[0]));indice_representation++;}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 91 "cpyrr.y" /* yacc.c:1646  */
    {inserer_tabrep(indice_representation,(yyvsp[0]));indice_representation++;}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 94 "cpyrr.y" /* yacc.c:1646  */
    {num_champ++;(yyval)=(yyvsp[0]);}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 95 "cpyrr.y" /* yacc.c:1646  */
    {num_champ++;(yyval)=insere_arbre((yyvsp[-2]),(yyvsp[0]));}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 98 "cpyrr.y" /* yacc.c:1646  */
    {inserer_tabrep(indice_representation,indice((yyvsp[0])));indice_representation++;}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 98 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_CHAMP,-999),(yyvsp[0]));num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_tabrep(indice_representation,association_nom());indice_representation++;}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 101 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 102 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_IDF,-999);}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 105 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_INT,-999);}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 106 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_FLOAT,999);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 107 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_BOOL,-999);}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 108 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_CHAR,-999);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 112 "cpyrr.y" /* yacc.c:1646  */
    {num_lexico = indice(yytext);empiler(create_ElementPile(-1,FLOAT,CHAR,(yyvsp[0])));}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 112 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_VAR,-999),concat_father_brother(creer_noeud(T_IDF,-999),(yyvsp[0])));num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_var(num_region,num_lexico,association_nom(),region_declaration());}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 115 "cpyrr.y" /* yacc.c:1646  */
    {num_region++;empile(num_region);NIS=taillePileRegion()-1;inserer_table_region(NIS,(yyval));first_representation = indice_representation;indice_representation++;}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 115 "cpyrr.y" /* yacc.c:1646  */
    {num_lexico_fp = indice((yyvsp[0]));}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 115 "cpyrr.y" /* yacc.c:1646  */
    {inserer_procedure(getValeur(taillePileRegion()-2),num_region,first_representation,num_lexico_fp);inserer_tabrep(first_representation,num_parametres);num_parametres = 0;}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 115 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_PROC,-999),concat_father_brother(creer_noeud(T_IDF,-999),concat_father_brother((yyvsp[-2]),(yyvsp[0]))));affiche_arbre((yyval));inserer_table_region(NIS,(yyval));}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 118 "cpyrr.y" /* yacc.c:1646  */
    {num_region++;empile(num_region);NIS=taillePileRegion()-1;inserer_table_region(NIS,(yyval));first_representation = indice_representation;indice_representation+=2;}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 118 "cpyrr.y" /* yacc.c:1646  */
    {num_lexico_fp = indice((yyvsp[0]));}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 118 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_FONCTION,-999),concat_father_brother(creer_noeud(T_IDF,-999),concat_father_brother((yyvsp[-2]),concat_father_son(creer_noeud(T_RETOURNE,-999),(yyvsp[0])))));inserer_fonction(getValeur(taillePileRegion()-2),num_region,first_representation,num_lexico_fp);inserer_tabrep(first_representation,indice(yytext));inserer_tabrep(first_representation+1,num_parametres);num_parametres = 0;}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 121 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 124 "cpyrr.y" /* yacc.c:1646  */
    {num_parametres++;(yyval)=(yyvsp[0]);}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 125 "cpyrr.y" /* yacc.c:1646  */
    {num_parametres++;(yyval)=insere_arbre((yyvsp[-2]),(yyvsp[0]));}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 129 "cpyrr.y" /* yacc.c:1646  */
    {num_lexico = indice(yytext);inserer_tabrep(indice_representation,indice((yyvsp[0])));indice_representation++;}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 129 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_PARAM,-999),(yyvsp[0]));num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_var(num_region,num_lexico,association_nom(),region_declaration());inserer_tabrep(indice_representation,indice(yytext));indice_representation++;}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 130 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_CSTE,-999);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 133 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 134 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 135 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 136 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 137 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 138 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 142 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 143 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_VIDE,-999);}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 144 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_RETOURNE,-999),(yyvsp[0]));}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 147 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 148 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 152 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 155 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_APPEL_FONC,-999),(yyvsp[0]));}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 159 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 162 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 163 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=insere_arbre((yyvsp[-2]),(yyvsp[0]));}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 166 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 169 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_IF,-999),concat_father_brother((yyvsp[-2]),(yyvsp[0])));}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 170 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_IF,-999),concat_father_brother((yyvsp[-4]),concat_father_brother((yyvsp[-2]),(yyvsp[0]))));}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 173 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_WHILE,-999),concat_father_brother((yyvsp[-3]),(yyvsp[0])));}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 176 "cpyrr.y" /* yacc.c:1646  */
    {num_association_nom = indice((yyvsp[0]));if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d :Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,(yyvsp[0])); return -1;}}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 176 "cpyrr.y" /* yacc.c:1646  */
    {num_association_nom = indice((yyvsp[-3]));(yyval)=concat_father_son(creer_noeud(T_OPAFF,-999),concat_father_brother((yyvsp[-3]),(yyvsp[0])));}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 179 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 180 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 183 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_IDF,(yyvsp[0]));}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 184 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_IDF,(yyvsp[-1])),(yyvsp[0]));}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 185 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_brother((yyvsp[-2]),creer_noeud(T_IDF,(yyvsp[0])));}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 186 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_brother((yyvsp[-3]),concat_father_son(creer_noeud(T_IDF,(yyvsp[-1])),(yyvsp[0])));}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 189 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 190 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_brother((yyvsp[-3]),(yyvsp[-1]));}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 193 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 196 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_PLUS,-999),concat_father_brother((yyvsp[-2]),(yyvsp[0])));}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 197 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_MOINS,-999),concat_father_brother((yyvsp[-2]),(yyvsp[0])));}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 198 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 201 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_MULT,-999),concat_father_brother((yyvsp[-2]),(yyvsp[0])));}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 202 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_DIV,-999),concat_father_brother((yyvsp[-2]),(yyvsp[0])));}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 203 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 206 "cpyrr.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 207 "cpyrr.y" /* yacc.c:1646  */
    {if(!flag){(yyval) = creer_noeud(T_CSTE,(yyvsp[0]));}}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 208 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_REEL,(yyvsp[0]));}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 209 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 210 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 213 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_OP,-999),concat_father_brother((yyvsp[-2]),(yyvsp[0])));}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 214 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=concat_father_son(creer_noeud(T_OP,-999),concat_father_brother((yyvsp[-3]),(yyvsp[-1])));}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 215 "cpyrr.y" /* yacc.c:1646  */
    {(yyval)=creer_noeud(T_BOOL,-999);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2021 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 220 "cpyrr.y" /* yacc.c:1906  */


int yyerror(){
	printf("Erreur en ligne %d\n", numligne);

	return -1;
}

int main()
{
creertablexico();
cree_tabdec();
cree_tabrep();
creer_tabregion();
yyparse();
if(erreur!=1){
fprintf(stdout,"*****************************\n");
fprintf(stdout,"FICHIER COMPILER AVEC SUCCES\n");
fprintf(stdout,"*****************************\n");

affichage_tab_lex();
affiche_decla();
affiche_rep();
affiche_region();
// arbre a1 = creer_noeud(T_IDF,-999);
// arbre a2 = creer_noeud(T_IDF,-999);
// arbre a3 = insere_arbre(a1,a2);
// affiche_arbre(a3);
}


}
