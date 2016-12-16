#include "tabdecl.h"

// Champ NATURE. Ce champ peut prendre l'une des 4 valeurs :
// NATURE=1 : l'enregistrement corrrespond à une déclaration de type T_STRUCTure.
// NATURE=2 : l'enregistrement corrrespond à une déclaration de type tableau.
// NATURE=3 : l'enregistrement corrrespond à une déclaration de T_T_VARiable.
// NATURE=4 : l'enregistrement corrrespond à une déclaration de procédure.
// NATURE=5 : l'enregistrement corrrespond à une déclaration de T_FONCTION.
// Chainage sur les autres déclarations de même nom, dans la zone de débordement.
// Numéro de région contenant la déclaration.
// Le quatrième champ a la signification suivante :
// si NATURE=1 ou NATURE=2 : index dans la table contenant la description du type.
// si NATURE=3 : index, dans la table des déclarations, de l'enregistrement associé à la déclaration du type. Si cette valeur vaut 1, 2, 3, ou 4, il s'agit d'un type de base (entier, réel, booléen ou caractère).
// si NATURE=4 ou NATURE=5 : index dans une table contenant la description de l'ent\^ete de la procédure ou de la T_FONCTION.
// Le cinquième champ a la signification suivante :
// si NATURE=1 ou NATURE=2 : taille à l'exécution d'une valeur de ce type (en tenant compte qu'il s'agit d'une machine C, cf ci-dessous).
// si NATURE=3 : déplacement à l'exécution, de l'emplacement associé à la T_T_VARiable dans la zone de données corrrespondante.
// si NATURE=4 ou NATURE=5 : numéro de la région associée à la procédure ou à la T_FONCTION.
// 0 == T_STRUCT
// 1 == tableau
// 2 == T_T_VARiable
// 3 == procedure
// 4 == T_FONCTION

int indice_declaration = 4;
int indice_debordement = 500;



void cree_tabdec(){
								//index = 0-entier
								//index = 1-reel
								//index = 2-booleen
								//index = 3-char

								inserer_tabdec(0, 0, -1, 0, -1, sizeof(int));
								inserer_tabdec(1, 1, -1, 0, -1, sizeof(float));
								inserer_tabdec(2, 2, -1, 0, -1, sizeof(int));
								inserer_tabdec(3, 3, -1, 0, -1, sizeof(char));
								for(int i=4; i<MAXDECL; i++) {
																inserer_tabdec(i, -1, -1, -1, -1, -1);
								}

}


void inserer_tabdec(int indice,int nature,int suivant,int region,int description,int execution){
								tabdecl[indice].nature = nature;
								tabdecl[indice].suivant = suivant;
								tabdecl[indice].region = region;
								tabdecl[indice].description = description;
								tabdecl[indice].execution = execution;
}
void inserer_fonction(int region,int execution,int description,int nombre_lexico){
	printf("NOMBRE LEXICO = %d\n",nombre_lexico );
	if(tabdecl[nombre_lexico].nature == -1) {

									inserer_tabdec(nombre_lexico, T_FONCTION, -1,region, description,execution);
									indice_declaration++;
	}
	else {
									int indice = trouver_indice_insertion(nombre_lexico);
									printf("fonction trouver! inserer dans %d\n",indice );
									inserer_tabdec(indice_debordement, T_FONCTION, -1, region, description, execution);
									tabdecl[indice].suivant = indice_debordement;
									indice_debordement++;
	}

}
void inserer_tab(int region,int indice_representation,int nombre_lexico,int taille){
	if(tabdecl[nombre_lexico].nature == -1) {
									inserer_tabdec(nombre_lexico, T_TAB, -1,region, indice_representation, taille);
									indice_declaration++;
	}
	else {
									int indice = trouver_indice_insertion(nombre_lexico);

									inserer_tabdec(indice_debordement, T_TAB, -1, region, indice_representation, 0);
									tabdecl[indice].suivant = indice_debordement;
									indice_debordement++;
	}
}
void inserer_struct(int region,int indice_representation,int nombre_lexico,int taille){


	if(tabdecl[nombre_lexico].nature == -1) {
									inserer_tabdec(nombre_lexico, T_STRUCT, -1,region, indice_representation, taille);
									indice_declaration++;
	}
	else {
									int indice = trouver_indice_insertion(nombre_lexico);

									inserer_tabdec(indice_debordement, T_STRUCT, -1, region, indice_representation, 0);
									tabdecl[indice].suivant = indice_debordement;
									indice_debordement++;
	}
}
void inserer_var(int region,int nombre_lexico,int type,int execution){
								if(tabdecl[nombre_lexico].nature == -1) {
																inserer_tabdec(nombre_lexico, T_VAR, -1,region, type, execution);
																indice_declaration++;
								}
								else {
																int indice = trouver_indice_insertion(nombre_lexico);
																inserer_tabdec(indice_debordement, T_VAR, -1, region, type,execution);
																tabdecl[indice].suivant = indice_debordement;
																indice_debordement++;
								}
}
void inserer_procedure(int region,int execution,int indice_representation,int nombre_lexico){
	if(tabdecl[nombre_lexico].nature == -1) {
									inserer_tabdec(nombre_lexico, T_PROC, -1,region, indice_representation, execution);
									indice_declaration++;
	}
	else {
									int indice = trouver_indice_insertion(nombre_lexico);

									inserer_tabdec(indice_debordement, T_PROC, -1, region, indice_representation, execution);
									tabdecl[indice].suivant = indice_debordement;
									indice_debordement++;
	}
}
int trouver_indice_insertion(int indice){
								if(tabdecl[indice].suivant == -1)
																return indice;
								else
																trouver_indice_insertion(tabdecl[indice].suivant);
}

void affiche_decla()
{

								int i;
								printf("******************************\n");
								printf("TABLE DE DECLARATION DES TYPES\n");
								printf("******************************\n");


								fprintf(stdout,"\tnature\tsuivant\tregion\tdescription\texecution\n");
								for(i=0; i<=compter; i++)
								{
																fprintf(stdout,"%d\t%d\t%d\t%d\t%d\t\t%d\n", i,tabdecl[i].nature, tabdecl[i].suivant,  tabdecl[i].region, tabdecl[i].description, tabdecl[i].execution );



								}



								printf("*******************\n");
								printf("ZONE DE DEBORDEMENT\n");
								printf("*******************\n");

								fprintf(stdout,"\tnature\tsuivant\tregion\tdescription\texecution\n");
								if(indice_debordement>500) {
																for(i=500; i<indice_debordement; i++)
																{
																								fprintf(stdout,"%d\t%d\t%d\t%d\t%d\t\t%d\n",i, tabdecl[i].nature, tabdecl[i].suivant,  tabdecl[i].region, tabdecl[i].description, tabdecl[i].execution );
																}
								}








}



// int main(int argc, char const *argv[])
// {
// 								cree_tabdec();
// 								// inserer_T_T_VAR(1, 0);
// 								// affiche_decla();
// 								// inserer_T_T_VAR(2,0);
// 								// affiche_decla();
// 								// inserer_T_FONCTION(1, 0, 3);
// 								// affiche_decla();
// 								inserer_T_T_VAR(0, 4);
// 								affiche_decla();
//
// 								return 0;
// }
