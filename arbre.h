#ifndef TEST_A_INCLUDED
#define TEST_A_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T_INT 0
#define T_FLOAT 1
#define T_BOOL 2
#define T_CHAR 3
#define T_STRUCT 4
#define T_TAB 5
#define T_VAR 6
#define T_PROC 7
#define T_FONCTION 8
#define T_STRING 9
#define T_PLUS 10
#define T_MOINS 11
#define T_DIV 12
#define T_MULT 13
#define T_SUP 14
#define T_INF 15
#define T_EG 16
#define T_DIF 17
#define T_SUPEG 18
#define T_INFEG 19
#define T_OPAFF 20
#define T_IDF 21
#define T_IF 22
#define T_THEN 23
#define T_ELSE 24
#define T_FOR 25
#define T_WHILE 26
#define T_FONC 27
#define T_PROCE 28
#define T_ET 29
#define T_OU 30
#define T_LIST 31
#define T_CSTE 32
#define T_REEL 33
#define T_APPEL_FONC 34
#define T_APPEL_PROC 35
#define T_VIDE 36
#define T_OP 37
#define T_RETOURNE 38
#define T_PARAM 39
#define T_DIMENSION 40
#define T_CHAMP 41
#define T_DECL 42



typedef struct noeud
{
        int nature;
        int valeur;
        char string[50];
        int indice;
        struct noeud* fils;
        struct noeud* frere;
}noeud;

typedef struct noeud* arbre;
arbre creer_noeud(int nat,int valeur);
arbre insere_arbre(arbre a1, arbre a2);
arbre dernier_fils(arbre a);
arbre concat_father_son(arbre pere, arbre fils1);
arbre concat_father_brother(arbre pere, arbre frere1);
void affiche_element(arbre n);
void affiche_arbre(arbre a1);
char* nature_arbre(int nature);

#endif
