#include <stdio.h>
#include <stdlib.h>
#include "region.h"
#include "tabdecl.h"


void inserer_table_region(int taille, int NIS, arbre* linkedT){
	if (nb_regions < MAXREG - 1){ //Pour inserer, il faut au moins une case
		tabreg[nb_regions].taille = calcul_taille(nb_regions);
		//tabreg[nb_regions].NIS = calcul_nis();
		tabreg[nb_regions].linkedT = linkedT;
		
		nb_regions++;
	}
	else{
		fprintf(stderr, "Erreur : la table de region est pleine!\n");
		exit(-1);
	}
}


/*Fonction de calcul de la taille d'une zone de donnees*/
int calcul_taille(int numregion){
	int taille = 0; //Taille de la region
	
	for (int i = 0; i < MAXDECL; i++){
		if (tabdecl[i].region == numregion && tabdecl[i].nature == VAR){
			taille += taille_type(tabdecl[i].description);
		}
	}
	
	return taille;
}


/*Retourne la taille du type de numero de declaration*/
int taille_type(int numdecl){
	switch (numdecl){
		case 0: //type int
			return (int) sizeof(int);
			break;
		case 1: //type float
			return (int) sizeof(float);
			break;
		case 2: //type boolean
			return 1;
			break;
		case 3: //type char
			return (int) sizeof(char);
			break;
		default:
			/*Le type concerne sera soit un tableau, soit une structure de donnees donc
			 *il faudra consulter la table de representation
			 */
			 if (tabdecl[numdecl].nature == STRUCT){
			 }
			 else if (tabdecl[numdecl].nature == TAB){
			 }
			 break;
		}
		 
		return 0; /*On renvoie parce qu'il peut plus s'agit d'un type*/
}


/*Retourne le niveau d'imbrication statique
int calcul_nis(){
	int NIS = 0;
	
	
}*/

int main(int argc, char* argv[]){
	printf("%d\n", taille_type(atoi(argv[1])));
	
	return EXIT_SUCCESS;
}
