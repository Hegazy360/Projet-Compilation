%{
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
programme:PROG {empile(num_region);} corps {inserer_table_region(NIS,$$);$$=concat_father_son(creer_noeud(-1,-999),$3);}
;

corps: liste_declarations liste_instructions {$$=concat_father_brother($1,$2);}
| liste_instructions {$$=$1;}
;

liste_declarations: declaration {$$=$1;}
| declaration liste_declarations {$$=insere_arbre($1,$2);}//On ne met plus le point-virgule parce qu'après la déclaration d'une fonction ou d'une procédure, il n'y en a pas
;

liste_instructions: DEBUT suite_liste_inst FIN {depile();$$=$2;}
;

suite_liste_inst: instruction {$$=$1;}
| suite_liste_inst instruction {$$=insere_arbre($1,$2);}//On mettra le point-virgule uniquement sur les instructions concernees
;


declaration: declaration_type POINT_VIRGULE {$$=$1;}//On précise le point-virgule directement à la déclaration concerné
| declaration_variable POINT_VIRGULE {$$=$1;}
| declaration_procedure {$$=$1;}
| declaration_fonction {$$=$1;}
;

declaration_type: TYPE IDF {num_lexico = indice($2);empiler(create_ElementPile(-1,FLOAT,CHAR,$2));} DEUX_POINTS suite_declaration_type {$$=concat_father_son(creer_noeud(T_DECL,-999),concat_father_brother(creer_noeud(T_IDF,-999),$5));}
;

suite_declaration_type: STRUCT {first_representation = indice_representation;indice_representation++;} liste_champs POINT_VIRGULE FSTRUCT {$$=concat_father_son(creer_noeud(T_STRUCT,-999),$3);inserer_tabrep(first_representation,num_champ);inserer_struct(num_region,first_representation,num_lexico,taille_struct(first_representation));num_champ=0;}
| TABLEAU {flag = 1;first_representation = indice_representation;indice_representation+=2;} dimension DEUX_POINTS nom_type {num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_tabrep(first_representation,association_nom());inserer_tabrep(first_representation+1,dimension);inserer_tab(num_region,first_representation,num_lexico,taille_tab(first_representation));dimension = 0;flag=0;}
;

dimension: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT {$$=$2;}
;

liste_dimensions: une_dimension {dimension++;$$=$1;}
| une_dimension VIRGULE liste_dimensions {dimension++;}
;

une_dimension: exparith{inserer_tabrep(indice_representation,$1);indice_representation++;} POINT_2 exparith {inserer_tabrep(indice_representation,$4);indice_representation++;}
;

liste_champs: un_champ {num_champ++;$$=$1;}
|  liste_champs POINT_VIRGULE un_champ {num_champ++;$$=insere_arbre($1,$3);}
;

un_champ: IDF {inserer_tabrep(indice_representation,indice($1));indice_representation++;}DEUX_POINTS nom_type{$$=concat_father_son(creer_noeud(T_CHAMP,-999),$4);num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_tabrep(indice_representation,association_nom());indice_representation++;}
;

nom_type: type_simple {$$=$1;}
| IDF {$$=creer_noeud(T_IDF,-999);}
;

type_simple: ENTIER {$$=creer_noeud(T_INT,-999);}
| REEL {$$=creer_noeud(T_FLOAT,999);}
| BOOLEEN {$$=creer_noeud(T_BOOL,-999);}
| CARACTERE {$$=creer_noeud(T_CHAR,-999);}
|CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT
;

declaration_variable: VARIABLE IDF {num_lexico = indice(yytext);empiler(create_ElementPile(-1,FLOAT,CHAR,$2));} DEUX_POINTS nom_type {$$=concat_father_son(creer_noeud(T_VAR,-999),concat_father_brother(creer_noeud(T_IDF,-999),$5));num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_var(num_region,num_lexico,association_nom(),region_declaration());}
;

declaration_procedure: PROCEDURE {num_region++;empile(num_region);NIS=taillePileRegion()-1;inserer_table_region(NIS,$$);first_representation = indice_representation;indice_representation++;}IDF {num_lexico_fp = indice($3);} liste_parametres {inserer_procedure(getValeur(taillePileRegion()-2),num_region,first_representation,num_lexico_fp);inserer_tabrep(first_representation,num_parametres);num_parametres = 0;} corps {$$=concat_father_son(creer_noeud(T_PROC,-999),concat_father_brother(creer_noeud(T_IDF,-999),concat_father_brother($5,$7)));affiche_arbre($$);inserer_table_region(NIS,$$);}
;

declaration_fonction: FONCTION {num_region++;empile(num_region);NIS=taillePileRegion()-1;inserer_table_region(NIS,$$);first_representation = indice_representation;indice_representation+=2;}IDF {num_lexico_fp = indice($3);} liste_parametres RETOURNE type_simple {$$=concat_father_son(creer_noeud(T_FONCTION,-999),concat_father_brother(creer_noeud(T_IDF,-999),concat_father_brother($5,concat_father_son(creer_noeud(T_RETOURNE,-999),$7))));inserer_fonction(getValeur(taillePileRegion()-2),num_region,first_representation,num_lexico_fp);inserer_tabrep(first_representation,indice(yytext));inserer_tabrep(first_representation+1,num_parametres);num_parametres = 0;} corps
;

liste_parametres: PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE {$$=$2;}
;

liste_param: un_param {num_parametres++;$$=$1;}
| un_param POINT_VIRGULE liste_param {num_parametres++;$$=insere_arbre($1,$3);}
|
;

un_param: IDF {num_lexico = indice(yytext);inserer_tabrep(indice_representation,indice($1));indice_representation++;}DEUX_POINTS type_simple{$$=concat_father_son(creer_noeud(T_PARAM,-999),$4);num_association_nom = indice(yytext);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d : Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,yytext); return -1;}inserer_var(num_region,num_lexico,association_nom(),region_declaration());inserer_tabrep(indice_representation,indice(yytext));indice_representation++;}
|CSTE_ENTIERE {$$=creer_noeud(T_CSTE,-999);}
;

instruction: instruction_point_virgule POINT_VIRGULE {$$=$1;}
| instruction_cond {$$=$1;}
| declaration_variable {$$=$1;}
| declaration_procedure {$$=$1;}
| declaration_fonction {$$=$1;}
| declaration_type {$$=$1;}
;

instruction_point_virgule: affectation
| appel {$$=$1;}
|	VIDE {$$=creer_noeud(T_VIDE,-999);}
| RETOURNE resultat_retourne {$$=concat_father_son(creer_noeud(T_RETOURNE,-999),$2);}
;

instruction_cond: condition {$$=$1;}
| tant_que {$$=$1;}
;

resultat_retourne:
| expression {$$=$1;}
;

appel: IDF liste_arguments {$$=concat_father_son(creer_noeud(T_APPEL_FONC,-999),$2);}
;

liste_arguments: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
| PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE {$$=$2;}
;

liste_args: un_arg {$$=$1;}
| liste_args VIRGULE un_arg {$$=insere_arbre($1,$3);}
;

un_arg: exparith {$$=$1;}
;

condition: SI exprel ALORS liste_instructions {$$=concat_father_son(creer_noeud(T_IF,-999),concat_father_brother($2,$4));}
| SI exprel ALORS liste_instructions SINON liste_instructions {$$=concat_father_son(creer_noeud(T_IF,-999),concat_father_brother($2,concat_father_brother($4,$6)));}
;

tant_que: TANT_QUE PARENTHESE_OUVRANTE exprel PARENTHESE_FERMANTE FAIRE liste_instructions {$$=concat_father_son(creer_noeud(T_WHILE,-999),concat_father_brother($3,$6));}
;

affectation:variable{num_association_nom = indice($1);if(association_nom()==-2){erreur = 1;fprintf(stderr,"!!!ERREUR COMPILATION!!! Ligne %d :Type %s pas declarer dans les regions courants,program cpyrr arrete\n",numligne,$1); return -1;}} OPAFF  exparith {num_association_nom = indice($1);$$=concat_father_son(creer_noeud(T_OPAFF,-999),concat_father_brother($1,$4));}
;

expression: exparith {$$=$1;}
| exprel {$$=$1;} /*Relations de comparaison (Ex. x < y, a = b, 60 > 30...)*/
;

variable: IDF {$$=creer_noeud(T_IDF,$1);}
| IDF indices {$$=concat_father_son(creer_noeud(T_IDF,$1),$2);}
|	variable POINT IDF {$$=concat_father_brother($1,creer_noeud(T_IDF,$3));}
| variable POINT IDF indices {$$=concat_father_brother($1,concat_father_son(creer_noeud(T_IDF,$3),$4));}
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

e2: e2 MULT e3 {$$=concat_father_son(creer_noeud(T_MULT,-999),concat_father_brother($1,$3));}
| e2 DIV e3 {$$=concat_father_son(creer_noeud(T_DIV,-999),concat_father_brother($1,$3));}
| e3 {$$=$1;}
;

e3: PARENTHESE_OUVRANTE e1 PARENTHESE_FERMANTE {$$ = $2;}
| CSTE_ENTIERE {if(!flag){$$ = creer_noeud(T_CSTE,$1);}}
| CSTE_REEL {$$=creer_noeud(T_REEL,$1);}
| variable {$$=$1;}
| appel {$$=$1;}
;

exprel: exparith OP_COMP exparith {$$=concat_father_son(creer_noeud(T_OP,-999),concat_father_brother($1,$3));}
| PARENTHESE_OUVRANTE exparith OP_COMP exparith PARENTHESE_FERMANTE {$$=concat_father_son(creer_noeud(T_OP,-999),concat_father_brother($2,$4));}
| PARENTHESE_OUVRANTE BOOL PARENTHESE_FERMANTE {$$=creer_noeud(T_BOOL,-999);}
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
