#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#define MAXREG 500

struct record_region {
								int taille;
								int NIS;
								arbre linkedT; //Arbre abstrait associe
};

struct record_region tabreg[MAXREG]; //table de region

/*Initialisation de la table de region*/



void inserer_table_region(int NIS,arbre linkedT); /*Insere dans la table de region
                                                                  et met a jour le nombre de regions*/
int calcul_taille_region();
int calcul_taille(int numregion); /*Retourne la taille de la region de numero <numregion>*/
int taille_type(int numdecl); /*Retourne la taille au type de numero de declaration <numdecl>*/
