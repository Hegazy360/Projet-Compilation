/**Creation le 26/11/2016 par Eric DASSE
 *Fichier contenant la signature des fonctions de manipulation de tables de region
 *Il contient egalement la definition de la structure d'une table de region
 */

#include "cpyrr.h"

#define MAXREG 5000


/*	On verra la table de region comme une liste recursive "particuliere"	*/

typedef struct record_region {
	int taille;
	int NIS;
	arbre* linkedT; //Arbre abstrait associe
	struct record_region * suivant;
}record_region;

typedef record_region * TableRegion;


int region_courante = 0;


/*	Fonctions du TAD TableRegion	*/

int vide(TableRegion t);

int nb_regions(TableRegion t);

TableRegion ieme(int i, TableRegion t); /*Renvoie la region numero <i> region de la table de region <t>*/

int pleine(TableRegion t);

void initialiser_table_region(TableRegion t);

void inserer_table_region(TableRegion t, int taille, int NIS, arbre* linkedt);

int calcul_taille_region(int numregion);/*Retourne la taille de la region de numero <numregion>*/

int taille_type(int numdecl); /*Retourne la taille au type de numero de declaration <numdecl>*/

int calcul_nis(); /*Retourne le niveau d'imbrication statique (region englobante)*/

void affiche_tableRegion(TableRegion t);
