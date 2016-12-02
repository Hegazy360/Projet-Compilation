/**Creation le 26/11/2016 par Eric DASSE
 *Fichier contenant la signature des fonctions de manipulation de tables de region
 *Il contient egalement la definition de la structure d'une table de region
 */

#include <stdio.h>
#include <stdlib.h>
#include "cpyrr.h"

#define MAXREG 5000

struct record_region{
	int taille;
	int NIS;
	arbre* linkedT; //Arbre abstrait associe
};

struct record_region tabreg[MAXREG]; //table de region

tabreg[0].NIS = 0; /*Initialisation de la table de region*/

int region_courante = 0;

int nb_regions = 0; //Nombre de regions utilisees jusqu'a present dans le programme

void inserer_table_region(int taille, int NIS, arbre* linkedT); /*Insere dans la table de region
																																	et met a jour le nombre de regions*/
int calcul_taille_region(int numregion);/*Retourne la taille de la region de numero <numregion>*/
int taille_type(int numdecl); /*Retourne la taille au type de numero de declaration <numdecl>*/
int calcul_nis(); /*Retourne le niveau d'imbrication statique (region englobante)*/
void affiche_table_region();
