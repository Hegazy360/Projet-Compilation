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
    CROCHET_OUVRANT = 273,
    CROCHET_FERMANT = 274,
    VIRGULE = 275,
    PARENTHESE_OUVRANTE = 276,
    PARENTHESE_FERMANTE = 277,
    TYPE = 278,
    IDF = 279,
    ENTIER = 280,
    REEL = 281,
    BOOLEEN = 282,
    CARACTERE = 283,
    CHAINE = 284,
    CSTE_ENTIERE = 285,
    CSTE_REEL = 286,
    SI = 287,
    ALORS = 288,
    SINON = 289,
    TANT_QUE = 290,
    FAIRE = 291,
    OPAFF = 292,
    PLUS = 293,
    MOINS = 294,
    MULT = 295,
    DIV = 296,
    OP_COMP = 297
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
#define CROCHET_OUVRANT 273
#define CROCHET_FERMANT 274
#define VIRGULE 275
#define PARENTHESE_OUVRANTE 276
#define PARENTHESE_FERMANTE 277
#define TYPE 278
#define IDF 279
#define ENTIER 280
#define REEL 281
#define BOOLEEN 282
#define CARACTERE 283
#define CHAINE 284
#define CSTE_ENTIERE 285
#define CSTE_REEL 286
#define SI 287
#define ALORS 288
#define SINON 289
#define TANT_QUE 290
#define FAIRE 291
#define OPAFF 292
#define PLUS 293
#define MOINS 294
#define MULT 295
#define DIV 296
#define OP_COMP 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
