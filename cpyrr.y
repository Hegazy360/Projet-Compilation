%{
#include <stdio.h>
#include <stdlib.h>
#include "tablex.h"
#include "tabrep.h"
#include "tabdecl.h"
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
int type_retourne;
int num_region=0;
int num_parametres=0;
int num_lexico;
int num_champ;
int num_lex_champ;
int dimension;
int borne_sup[15];
int borne_inf[15];
int NIS;
int first_representation;
%};
%token PROG DEBUT FIN STRUCT FSTRUCT TABLEAU DE VARIABLE PROCEDURE FONCTION
%token RETOURNE VIDE
%token POINT_VIRGULE DEUX_POINTS POINT POINT_2 CROCHET_OUVRANT CROCHET_FERMANT VIRGULE
%token PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
%token TYPE IDF
 /*Ajouté le 15 Octobre 2016*/
%token ENTIER REEL BOOLEEN CARACTERE CHAINE CSTE_ENTIERE CSTE_REEL
%token SI ALORS SINON TANT_QUE FAIRE OPAFF
%token PLUS MOINS MULT DIV OP_COMP BOOL

%%
programme:PROG {empile(num_region);affichePileRegion();}corps
;

corps: liste_declarations liste_instructions
| liste_instructions
;

liste_declarations: declaration
| liste_declarations declaration //On ne met plus le point-virgule parce qu'après la déclaration d'une fonction ou d'une procédure, il n'y en a pas
;

liste_instructions: DEBUT suite_liste_inst FIN {depile();printf("Taille pile region %d\n",taillePileRegion());}
;

suite_liste_inst: instruction
| suite_liste_inst instruction //On mettra le point-virgule uniquement sur les instructions concernees
;


declaration: declaration_type POINT_VIRGULE //On précise le point-virgule directement à la déclaration concerné
| declaration_variable POINT_VIRGULE
| declaration_procedure
| declaration_fonction
;

declaration_type: TYPE IDF {num_lexico = indice($2);} DEUX_POINTS suite_declaration_type
;

suite_declaration_type: STRUCT {first_representation = indice_representation;indice_representation++;} liste_champs POINT_VIRGULE FSTRUCT {inserer_struct(num_region,first_representation,num_lexico);inserer_tabrep(first_representation,num_champ);num_champ=0;}
| TABLEAU {first_representation = indice_representation;indice_representation+=2;} dimension DEUX_POINTS nom_type {inserer_tab(num_region,first_representation,num_lexico);inserer_tabrep(first_representation,indice(yytext));inserer_tabrep(first_representation+1,dimension);dimension = 0;}
;

dimension: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT
;

liste_dimensions: une_dimension {dimension++;}
| liste_dimensions VIRGULE une_dimension {dimension++;}
;

une_dimension: exparith{inserer_tabrep(indice_representation,$1);indice_representation++;} POINT_2 exparith {inserer_tabrep(indice_representation,$4);indice_representation++;}
;

liste_champs: un_champ {num_champ++;}
|  liste_champs POINT_VIRGULE un_champ {num_champ++;}
;

un_champ: IDF {inserer_tabrep(indice_representation,indice($1));indice_representation++;}DEUX_POINTS nom_type{inserer_tabrep(indice_representation,indice(yytext));indice_representation++;}
;

nom_type: type_simple {$$=yytext;}
| IDF {$$=yytext;}
;

type_simple: ENTIER {$$=yytext;}
| REEL {$$=yytext;}
| BOOLEEN {$$=yytext;}
| CARACTERE {$$=yytext;}
|CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT
;

declaration_variable: VARIABLE IDF {num_lexico = indice(yytext);} DEUX_POINTS nom_type {inserer_var(num_region,num_lexico,indice($4));}
;

declaration_procedure: PROCEDURE {num_region++;empile(num_region);NIS=taillePileRegion();}IDF {num_lexico = indice($3);} liste_parametres {inserer_procedure(num_region,indice_representation,num_lexico);num_parametres = 0;} corps
;

declaration_fonction: FONCTION {num_region++;empile(num_region);NIS=taillePileRegion();}IDF {num_lexico = indice($3);} liste_parametres {printf("Num Parametre = %d\n",num_parametres);num_parametres = 0;} RETOURNE type_simple {inserer_fonction(num_region,indice_representation,num_lexico);printf("Lexeme = %s,Indice = %d\n",$7,indice($7));} corps
;

liste_parametres:
| PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
;

liste_param: un_param {num_parametres++;}
| liste_param POINT_VIRGULE un_param {num_parametres++;}
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

un_arg: exparith
;

condition: SI exprel ALORS liste_instructions
| SI exprel ALORS liste_instructions SINON liste_instructions
;

tant_que: TANT_QUE PARENTHESE_OUVRANTE exprel PARENTHESE_FERMANTE FAIRE liste_instructions
;

affectation: variable OPAFF exparith
;

expression: exparith
| exprel /*Relations de comparaison (Ex. x < y, a = b, 60 > 30...)*/
;

variable: IDF
| IDF indices
|	variable POINT IDF
| variable POINT IDF indices
;

indices: CROCHET_OUVRANT exparith CROCHET_FERMANT
| indices CROCHET_OUVRANT exparith CROCHET_FERMANT
;

exparith: e1 {$$=$1;}
;

e1: e1 PLUS e2 {$$=$1+$3;}
| e1 MOINS e2 {$$=$1-$3;}
| e2  {$$=$1;}
;

e2: e2 MULT e3 {$$=$1*$3;}
| e2 DIV e3 {$$=$1/$3;}
| e3 {$$=$1;}
;

e3: PARENTHESE_OUVRANTE e1 PARENTHESE_FERMANTE {$$=$2;}
| CSTE_ENTIERE {$$=$1;}
| CSTE_REEL {$$=$1;}
| variable //Pour le moment, pas de meilleure idée pour résoudre les conflits
| appel
;

exprel: exparith OP_COMP exparith
| PARENTHESE_OUVRANTE exparith OP_COMP exparith PARENTHESE_FERMANTE
| PARENTHESE_OUVRANTE BOOL PARENTHESE_FERMANTE
//| PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
;

;
%%

int yyerror(){
	printf("Erreur en ligne %d\n", numligne);

	return -1;
}

int main()
{
creertablexico();
cree_tabdec();
yyparse();
affichage_tab_lex();
affiche_decla();
affiche_rep();

}
