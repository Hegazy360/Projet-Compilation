%{
#include <stdio.h>
extern char* yytext;
extern int yylex();
extern int yyerror();
extern int numligne;
%};
%token PROG DEBUT FIN STRUCT FSTRUCT TABLEAU DE VARIABLE PROCEDURE FONCTION
%token RETOURNE VIDE
%token POINT_VIRGULE DEUX_POINTS POINT CROCHET_OUVRANT CROCHET_FERMANT VIRGULE
%token PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
%token TYPE IDF
 /*Ajouté le 15 Octobre 2016*/
%token ENTIER REEL BOOLEEN CARACTERE CHAINE CSTE_ENTIERE CSTE_REEL
%token SI ALORS SINON TANT_QUE FAIRE OPAFF
%token PLUS MOINS MULT DIV OP_COMP EXP_BOOL

%%
programme:PROG corps
; 

corps: liste_declarations liste_instructions
| liste_instructions
;

liste_declarations: declaration
| liste_declarations declaration //On ne met plus le point-virgule parce qu'après la déclaration d'une fonction ou d'une procédure, il n'y en a pas
;

liste_instructions: DEBUT suite_liste_inst FIN
;

suite_liste_inst: instruction
| suite_liste_inst instruction //On mettra le point-virgule uniquement sur les instructions concernees
;


declaration: declaration_type POINT_VIRGULE //On précise le point-virgule directement à la déclaration concerné
| declaration_variable POINT_VIRGULE
| declaration_procedure
| declaration_fonction
;

declaration_type: TYPE IDF DEUX_POINTS suite_declaration_type
;

suite_declaration_type: STRUCT liste_champs POINT_VIRGULE FSTRUCT
| TABLEAU dimension DEUX_POINTS nom_type
; 

dimension: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT
;

liste_dimensions: une_dimension
| liste_dimensions VIRGULE une_dimension
;

une_dimension: exparith POINT POINT exparith
;

liste_champs: un_champ
| liste_champs POINT_VIRGULE un_champ
;

un_champ: IDF DEUX_POINTS nom_type
;

nom_type: type_simple
| IDF
;

type_simple: ENTIER
| REEL
| BOOLEEN
| CARACTERE
|CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT
;

declaration_variable: VARIABLE IDF DEUX_POINTS nom_type
;

declaration_procedure: PROCEDURE IDF liste_parametres corps
;

declaration_fonction: FONCTION IDF liste_parametres RETOURNE type_simple corps
;

liste_parametres:
| PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
;

liste_param: un_param
| liste_param POINT_VIRGULE un_param
;

un_param: IDF DEUX_POINTS type_simple
|CSTE_ENTIERE
;

instruction: instruction_point_virgule POINT_VIRGULE
| instruction_cond
;

instruction_point_virgule: affectation
| appel
|	VIDE
| RETOURNE resultat_retourne
;

instruction_cond: condition
| tant_que
;

resultat_retourne:
| expression
;

appel: IDF liste_arguments
;

liste_arguments: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
| PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
;

liste_args: un_arg
| liste_args VIRGULE un_arg
;

<<<<<<< HEAD
un_arg: exparith
=======
un_arg: variable
|expression
>>>>>>> 049a2cd2e0390cb6356a14df4c62d6b44e654232
;

condition: SI PARENTHESE_OUVRANTE exprel PARENTHESE_FERMANTE ALORS liste_instructions
| SI PARENTHESE_OUVRANTE exprel PARENTHESE_FERMANTE ALORS liste_instructions SINON liste_instructions 
;

tant_que: TANT_QUE PARENTHESE_OUVRANTE exprel PARENTHESE_FERMANTE FAIRE liste_instructions
;

affectation: variable OPAFF exparith
;

expression: exparith
| exprel /*Relations de comparaison (Ex. x < y, a = b, 60 > 30...)*/
| variable
;

variable: IDF
<<<<<<< HEAD
| IDF indices
|	variable POINT IDF
| variable POINT IDF indices 
;

indices: CROCHET_OUVRANT exparith CROCHET_FERMANT
| indices CROCHET_OUVRANT exparith CROCHET_FERMANT
=======
| IDF CROCHET_OUVRANT exparith CROCHET_FERMANT
| IDF CROCHET_OUVRANT exparith CROCHET_FERMANT POINT variable
| IDF CROCHET_OUVRANT IDF CROCHET_FERMANT
| IDF CROCHET_OUVRANT IDF CROCHET_FERMANT POINT variable
| IDF POINT variable
| appel POINT variable
| appel
>>>>>>> 049a2cd2e0390cb6356a14df4c62d6b44e654232
;

exparith: e1
<<<<<<< HEAD
=======
| IDF MULT e1
| IDF DIV e1
| IDF MOINS e1
| IDF PLUS e1
>>>>>>> 049a2cd2e0390cb6356a14df4c62d6b44e654232
;

e1: e1 PLUS e2
| e1 MOINS e2
| e2
;

e2: e2 MULT e3
| e2 DIV e3
| e3
;

e3: PARENTHESE_OUVRANTE e1 PARENTHESE_FERMANTE
| CSTE_ENTIERE
| CSTE_REEL
<<<<<<< HEAD
| variable POINT //Pour le moment, pas de meilleure idée pour résoudre les conflits
| appel
=======
| variable
>>>>>>> 049a2cd2e0390cb6356a14df4c62d6b44e654232
;

exprel: exparith OP_COMP exparith
;

;
%%

int yyerror(){
	printf("Erreur en ligne %d\n", numligne);
	
	return -1;
}
