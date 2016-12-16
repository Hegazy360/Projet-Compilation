#ifndef TEST_D_INCLUDED
#define TEST_D_INCLUDED


#include <stdio.h>
#include <stdlib.h>
extern int compter;
#define MAXDECL 1000
#define T_STRUCT 4
#define T_TAB 5
#define T_VAR 6
#define T_PROC 7
#define T_FONCTION 8
struct element
{
        int nature;
        int suivant;
        int region;
        int description;
        int execution;
};
struct element tabdecl[MAXDECL];


void cree_tabdec();
void inserer_fonction(int region,int execution,int indice_representation,int nombre_lexico);
void inserer_procedure(int region,int execution,int indice_representation,int nombre_lexico);
void inserer_tab(int region,int indice_representation,int nombre_lexico,int taille);
void inserer_struct(int region,int indice_representation,int nombre_lexico,int taille);
void inserer_var(int region,int nombre_lexico,int type,int execution);
void inserer_tabdec(int indice,int nature,int suivant,int region,int description,int execution);
void affiche_decla();
int trouver_indice_insertion(int indice);
#endif
