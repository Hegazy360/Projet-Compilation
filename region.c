#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include "region.h"
#include "tabdecl.h"
#include "pileRegion.h"


extern int pileRegion[60];
extern int num_region;

TableRegion tabreg = NULL;

int vide(TableRegion t) {
	if (t == NULL)
		return 1;
	return 0;
}


int pleine(TableRegion t) {
	if (nb_regions(t) == MAXREG)
		return 1;
	return 0;
}


int nb_regions(TableRegion t) {
	int i = 0;
	TableRegion p = t; /*Variable qui parcourt la table*/
	
	while (p != NULL) {
		p = p->suivant;
		i++;
	}
	
	return i;
}


/*Initialise le premier enregistrement de la table t*/
void initialiser_table_region(TableRegion t) {
		t->taille = 0;
		t->NIS = 0;
		t->linkedT = NULL;
		t->suivant = NULL;
}


TableRegion ieme(int i, TableRegion t) {
	
	if (i < 0 || i >= nb_regions(t)) { /* ">=" parce que i est le numero de region (commence a 0...)*/
		fprintf(stderr, "Erreur : numero de region invalide!\n");
		
		 return NULL;
	}
	
	
	if (vide(t)) {
		fprintf(stderr, "Erreur : table de regions vide!\n");
		
		return NULL;
	}
	
	
	TableRegion p = t;
	int inc = 0;
	
	while (inc != i) {
		p = p->suivant;
		inc++;
	}
	
	return p;
}



void inserer_table_region(TableRegion t, int taille, int NIS, arbre* linkedT) {
	if (pleine(t))
		fprintf(stderr, "Erreur : la table de region est deja pleine!");
	else {
		TableRegion tabIns = (TableRegion) malloc (sizeof(record_region));
		
		assert(tabIns != NULL);
		
		TableRegion dernier = ieme(nb_regions(t) - 1, t);
		
		tabIns->taille = taille;
		tabIns->NIS = NIS;
		tabIns->linkedT = linkedT;
		tabIns->suivant = NULL;
		
		dernier->suivant = tabIns;
		
		free(tabIns);
	}
}



/*Fonction de calcul de la taille d'une zone de donnees*/
int calcul_taille_region(int numregion){
	int taille = 0;
	
	for (int i = 4; i < MAXDECL && tabdecl[i].region != -1; i++) {
		if (tabdecl[i].region == numregion && tabdecl[i].nature == VAR)
			taille += taille_type(tabdecl[i].description);
	}
	
	return taille;
}



/*Retourne la taille du type de numero de declaration numdecl*/
int taille_type(int numdecl){
	if (numdecl == 0 || numdecl == 1 || numdecl == 2 || numdecl == 3)
		return 1;
	else if (tabdecl[numdecl].nature == TAB || tabdecl[numdecl].nature == STRUCT)
		/*Le type concerne sera soit un tableau, 
		*soit une structure de donnees
		*Le champ execution contient la taille a l'execution de ces types
		*/
		
		return tabdecl[numdecl].execution;
		
	return 0; /* <numdecl> n'indexe pas un type */
		
}


/*Retourne le niveau d'imbrication statique
int calcul_nis(){
	return valeurTop();
}*/


/*Incremente le nombre de region courant
void incremente_region(){
	num_region++;
}
*/

void affiche_tableRegion(TableRegion t) {
	if (vide(t))
		fprintf(stderr, "VIDE!\n");
	
	printf ("\t*****TABLE DE REGIONS*****\t\n");
	
	TableRegion p = t;
	
	for (int i = 0; i < nb_regions(t); i++) {
		fprintf(stdout, "%d | %d | %d | %p\n", i, p->taille, p->NIS, p->linkedT);
		p = p->suivant;
	}
	
}


int main(int argc, char* argv[]){
	cree_tabdec();
	
	printf("Vide ? : %d\n", vide(tabreg));
	
	
	
	return EXIT_SUCCESS;
}
