/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
