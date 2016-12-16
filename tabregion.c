#include <stdio.h>
#include <stdlib.h>
#include "tabregion.h"
#include "tabdecl.h"

extern int num_region;

void creer_tabregion(){
	for(int i=0;i<MAXREG;i++){
		tabreg[i].taille = -1;
		tabreg[i].NIS = -1;
		tabreg[i].linkedT = (arbre) -1;
	}
}

void inserer_table_region(int NIS,arbre linkedT){
	if (num_region < MAXREG - 1){ //On ne peut pas inserer si la table de region est pleine
		tabreg[num_region].taille = calcul_taille_region();
		tabreg[num_region].NIS = NIS;
		tabreg[num_region].linkedT = linkedT;
	}
	else{
		fprintf(stderr, "Erreur : la table de region est pleine!\n");
		exit(-1);
	}
}


/*Fonction de calcul de la taille d'une zone de donnees*/
int calcul_taille_region(){
	int taille = 0;

	for (int i = 4; i < MAXDECL && tabdecl[i].region != -1; i++) {
		if (tabdecl[i].region == num_region)
			taille += taille_type(tabdecl[i].description);
	}

	return taille;
}



/*Retourne la taille du type de numero de declaration numdecl*/
int taille_type(int numdecl){
	if (numdecl == 0 || numdecl == 1 || numdecl == 2 || numdecl == 3)
		return tabdecl[numdecl].execution;
	else if (tabdecl[numdecl].nature == T_TAB || tabdecl[numdecl].nature == T_STRUCT)
		/*Le type concerne sera soit un tableau,
		*soit une structure de donnees
		*Le champ execution contient la taille a l'execution de ces types
		*/

		return tabdecl[numdecl].execution;

	return 0; /* <numdecl> n'indexe pas un type */

}
void affiche_region()
{

								int i;
								printf("******************************\n");
								printf("TABLE DE REGIONS\n");
								printf("******************************\n");


								fprintf(stdout,"\ttaille\tNIS\tarbre\n");
								for(i=0; i<=num_region; i++)
								{
																fprintf(stdout,"%d\t%d\t%d\t%d\n", i,tabreg[i].taille, tabreg[i].NIS,  tabreg[i].linkedT);
								}






}

// int main(int argc, char* argv[]){
// 	printf("%d\n", taille_type(atoi(argv[1])));
//
//
//
// 	return EXIT_SUCCESS;
// }
