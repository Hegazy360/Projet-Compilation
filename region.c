#include <stdio.h>
#include <stdlib.h>
#include "region.h"
#include "tabdecl.h"
#include "pileRegion.h"

extern int pileRegion[60];
extern int num_region;

void inserer_table_region(int NIS){
	if (num_region < MAXREG - 1){ //On ne peut pas inserer si la table de region est pleine
		//tabreg[num_region].taille = taille;
		tabreg[num_region].NIS = NIS;
		//tabreg[num_region].linkedT = linkedT;
	}
	else{
		fprintf(stderr, "Erreur : la table de region est pleine!\n");
		exit(-1);
	}
}

void setTailleRegion(int numregion, int taille){
	tabreg[numregion] = taille;
}

void setArbre(int numregion, arbre* linkedT){
	tabreg[numregion] = linkedT;
}


/*Fonction de calcul de la taille d'une zone de donnees*/
int calcul_taille_region(int numregion){
	int taille = 0; //Taille de la region
	
	for (int i = 0; i < MAXDECL; i++){
		if (tabdecl[i].region == numregion && tabdecl[i].nature == VAR){
			taille += taille_type(tabdecl[i].description);
		}
	}
	
	return taille;
}


/*Retourne la taille du type de numero de declaration numdecl*/
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
			 	int i = tabdecl[numdecl].description;
			 	int taille_s = tabrep[i];
			 	int taille = 0;
			 	int j = i;
			 	
			 	while (j <= i + 2*taille_s){
			 		taille += taille_type(tabrep[j+2]);
			 		j += 2;
			 	}
				
				return taille;
			 }
			 else if (tabdecl[numdecl].nature == TAB){
			 	int nb_cases = 0;
			 	int i = tabdecl[numdecl].description;
			 	int taille_t = taille_type(tabrep[i]); //taille du type du tableau
			 	
			 	for (int j = i + 2; j <= i + 2*tabrep[i+1]; j+=2){
			 		nb_cases = tabrep[j+1] - tabrep[j] + 1;
			 	}
			 	
			 	return taille_t * nb_cases;
			 }
			 break;
		}
		 
		return 0; /*On renvoie parce qu'il peut plus s'agir d'un type*/
}


/*Retourne le niveau d'imbrication statique*/
int calcul_nis(){
	return valeurTop();
}


/*Incremente le nombre de region courant
void incremente_region(){
	num_region++;
}
*/

void affiche_table_region(){
	printf("  taille\tNIS\n");
	
	for (int i = 0; i<num_region; i++){
		printf("%d %d\t%d\n",i, tabreg[i].taille, tabreg[i].NIS);
	}
}

/*
int main(int argc, char* argv[]){
	printf("%d\n", taille_type(atoi(argv[1])));
	
	
	
	return EXIT_SUCCESS;
*/
}
