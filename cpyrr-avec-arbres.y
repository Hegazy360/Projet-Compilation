%{
#include <stdio.h>
#include <stdlib.h>
#include "tablex.h"
#include "tabrep.h"
#include "tabdecl.h"
#include "assnom.h"
#include "tabregion.h"
#include "arbre.h"
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
char flag = 0;
%};
%token PROG DEBUT FIN STRUCT FSTRUCT TABLEAU DE VARIABLE PROCEDURE FONCTION
%token RETOURNE VIDE
%token POINT_VIRGULE DEUX_POINTS POINT POINT_2 CROCHET_OUVRANT CROCHET_FERMANT VIRGULE
%token PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
%token TYPE IDF
%token EG DIFF INFEG SUPEG INF SUP
 /*Ajouté le 15 Octobre 2016*/
%token ENTIER REEL BOOLEEN CARACTERE CHAINE CSTE_ENTIERE CSTE_REEL
%token SI ALORS SINON TANT_QUE FAIRE OPAFF
%token PLUS MOINS MULT DIV OP_COMP BOOL

%%
programme:PROG {empile(num_region);}corps
;

corps: liste_declarations liste_instructions
| liste_instructions
;

liste_declarations: declaration
| liste_declarations declaration //On ne met plus le point-virgule parce qu'après la déclaration d'une fonction ou d'une procédure, il n'y en a pas
;

liste_instructions: DEBUT suite_liste_inst FIN {depile();}
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
| TABLEAU {flag = 1;first_representation = indice_representation;indice_representation+=2;} dimension DEUX_POINTS nom_type {inserer_tab(num_region,first_representation,num_lexico);num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_tabrep(first_representation,association_nom());inserer_tabrep(first_representation+1,dimension);dimension = 0;flag=0;}
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

un_champ: IDF {inserer_tabrep(indice_representation,indice($1));indice_representation++;}DEUX_POINTS nom_type{num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_tabrep(indice_representation,association_nom());indice_representation++;}
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

declaration_variable: VARIABLE IDF {num_lexico = indice(yytext);} DEUX_POINTS nom_type {num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_var(num_region,num_lexico,association_nom(),region_declaration());}
;

declaration_procedure: PROCEDURE {num_region++;empile(num_region);NIS=taillePileRegion()-1;first_representation = indice_representation;indice_representation++;}IDF {num_lexico = indice($3);} liste_parametres {inserer_procedure(getValeur(taillePileRegion()-2),num_region,first_representation,num_lexico);inserer_tabrep(first_representation,num_parametres);num_parametres = 0;} corps
;

declaration_fonction: FONCTION {num_region++;empile(num_region);NIS=taillePileRegion()-1;first_representation = indice_representation;indice_representation+=2;}IDF {num_lexico = indice($3);} liste_parametres RETOURNE type_simple {inserer_fonction(getValeur(taillePileRegion()-2),num_region,first_representation,num_lexico);inserer_tabrep(first_representation,indice(yytext));inserer_tabrep(first_representation+1,num_parametres);num_parametres = 0;} corps
;

liste_parametres:
| PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
;

liste_param: un_param {num_parametres++;}
| liste_param POINT_VIRGULE un_param {num_parametres++;}
;

un_param: IDF {num_lexico = indice(yytext);inserer_tabrep(indice_representation,indice($1));indice_representation++;}DEUX_POINTS type_simple{num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_var(num_region,num_lexico,association_nom(),region_declaration());inserer_tabrep(indice_representation,indice(yytext));indice_representation++;}
|CSTE_ENTIERE
;

instruction: instruction_point_virgule POINT_VIRGULE
| instruction_cond
| declaration_variable
| declaration_procedure
| declaration_fonction
| declaration_type
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

appel: IDF liste_arguments {num_association_nom = indice($1);$$=concat_father_son(creer_noeud(T_APPEL_FONC,association_nom()),$2);}
;

liste_arguments: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=creer_noeud(T_VIDE,0);}
| PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE {$$=$2;}
;

liste_args: un_arg {$$=$1;}
| liste_args VIRGULE un_arg {$$=concat_father_brother($1,$3);}
;

un_arg: exparith {$$=$1;}
;

condition: SI exprel ALORS liste_instructions
| SI exprel ALORS liste_instructions SINON liste_instructions
;

tant_que: TANT_QUE PARENTHESE_OUVRANTE exprel PARENTHESE_FERMANTE FAIRE liste_instructions
;

affectation:variable{num_association_nom = indice($1);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d :Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,$1); return -1;}} OPAFF  exparith {num_association_nom = indice($1);$$=concat_father_son(creer_noeud(T_OPAFF,-999),concat_father_brother($1,$4));}
;

expression: exparith {$$=$1;}
| exprel {$$=$1;}/*Relations de comparaison (Ex. x < y, a = b, 60 > 30...)*/
;

variable: IDF {num_association_nom = indice($1);$$=creer_noeud(T_IDF,association_nom());}
| IDF indices {num_association_nom = indice($1);$$=concat_father_son(creer_noeud(T_IDF,association_nom()),$2);}
|	variable POINT IDF {num_association_nom = indice($3); $$=concat_father_son($1,creer_noeud(T_IDF,association_nom()));}
| variable POINT IDF indices {num_association_nom = indice($3);$$=concat_father_son($1,concat_father_son($3,$4));}
;

indices: CROCHET_OUVRANT exparith CROCHET_FERMANT {$$=$2;}
| indices CROCHET_OUVRANT exparith CROCHET_FERMANT {$$=concat_father_brother($1,$3);}
;

exparith: e1 {$$=$1;}
;

e1: e1 PLUS e2 {$$=concat_father_son(creer_noeud(T_PLUS,-999),concat_father_brother($1,$3));}
| e1 MOINS e2 {$$=concat_father_son(creer_noeud(T_MOINS,-999),concat_father_brother($1,$3));}
| e2  {$$=$1;}
;

e2: e2 MULT e3 {$$=$1*$3;}
| e2 DIV e3 {$$=concat_father_son(creer_noeud(T_DIV,-999),concat_father_brother($1,$3));}
| e3 {$$=$1;}
;

e3: PARENTHESE_OUVRANTE e1 PARENTHESE_FERMANTE {$$=$2;}
| CSTE_ENTIERE {if(!flag){$$ = creer_noeud(T_CSTE,$1);}}
| CSTE_REEL {$$=creer_noeud(T_REEL,$1);}
| variable {$$=$1;}//Pour le moment, pas de meilleure idée pour résoudre les conflits
| appel {$$=$1;}
;

exprel: exparith operateur exparith {$$=concat_father_son($2,concat_father_brother($1,$3));}
| PARENTHESE_OUVRANTE exparith operateur exparith PARENTHESE_FERMANTE {$$=concat_father_son($3,concat_father_brother($2,$4));}
| PARENTHESE_OUVRANTE BOOL PARENTHESE_FERMANTE {if(strcmp(yytext,"true") == 0){$$=creer_noeud(T_BOOL,1);}else {$$=creer_noeud(T_BOOL,0);}}
//| PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
;
operateur : INFEG {$$=creer_noeud(T_INFEG,-999);}
          | SUPEG {$$=creer_noeud(T_SUPEG,-999);}
          | INF {$$=creer_noeud(T_INF,-999);}
          | SUP {$$=creer_noeud(T_SUP,-999);}
          | DIFF {$$=creer_noeud(T_DIF,-999);}
          | EG {$$=creer_noeud(T_EG,-999);}
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
cree_tabrep();
yyparse();
if(erreur!=1){
fprintf(stdout,"*****************************\n");
fprintf(stdout,"FICHIER COMPILER AVEC SUCCES\n");
fprintf(stdout,"*****************************\n");

affichage_tab_lex();
affiche_decla();
affiche_rep();
}


}

