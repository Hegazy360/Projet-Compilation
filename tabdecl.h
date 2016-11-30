#include <stdio.h>
#include <stdlib.h>

#define MAXDECL 5000
#define STRUCT 1
#define TAB 2
#define VAR 3
#define PROC 4
#define FONCTION 5

struct element
{
        int nature;
        int suivant;
        int region;
        int description;
        int execution;
};
struct element tabdecl[MAXDECL];
int tabrep[1000];
int debordement=500;
void cree_tabdec();
void inserer_fonction(int region,int description,int nombre_lexico);
void inserer_tab(int region,int nombre_lexico,int dimension);
void inserer_struct();
void inserer_var(int region,int nombre_lexico);
void inserer_tabdec(int indice,int nature,int suivant,int region,int description,int execution);
int trouver_indice_insertion(int indice);
