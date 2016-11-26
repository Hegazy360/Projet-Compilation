#include "tabdecl.h"

// Champ NATURE. Ce champ peut prendre l'une des 4 valeurs :
// NATURE=1 : l'enregistrement corrrespond à une déclaration de type structure.
// NATURE=2 : l'enregistrement corrrespond à une déclaration de type tableau.
// NATURE=3 : l'enregistrement corrrespond à une déclaration de variable.
// NATURE=4 : l'enregistrement corrrespond à une déclaration de procédure.
// NATURE=5 : l'enregistrement corrrespond à une déclaration de fonction.
// Chainage sur les autres déclarations de même nom, dans la zone de débordement.
// Numéro de région contenant la déclaration.
// Le quatrième champ a la signification suivante :
// si NATURE=1 ou NATURE=2 : index dans la table contenant la description du type.
// si NATURE=3 : index, dans la table des déclarations, de l'enregistrement associé à la déclaration du type. Si cette valeur vaut 1, 2, 3, ou 4, il s'agit d'un type de base (entier, réel, booléen ou caractère).
// si NATURE=4 ou NATURE=5 : index dans une table contenant la description de l'ent\^ete de la procédure ou de la fonction.
// Le cinquième champ a la signification suivante :
// si NATURE=1 ou NATURE=2 : taille à l'exécution d'une valeur de ce type (en tenant compte qu'il s'agit d'une machine C, cf ci-dessous).
// si NATURE=3 : déplacement à l'exécution, de l'emplacement associé à la variable dans la zone de données corrrespondante.
// si NATURE=4 ou NATURE=5 : numéro de la région associée à la procédure ou à la fonction.
// 0 == struct
// 1 == tableau
// 2 == variable
// 3 == procedure
// 4 == fonction

int indice_declaration = 4;
int indice_representation = 4;
int indice_debordement = 500;
void cree_tabdec(){
								//index = 0-entier
								//index = 1-reel
								//index = 2-booleen
								//index = 3-char
								for (int i=0; i<4; i++)
								{
																inserer_tabdec(i, i, -1, 0, 0, 0);
																tabrep[i]= i;
								}
								for(int i=4; i<MAXDECL; i++) {
																inserer_tabdec(i, -1, -1, 0, -1, 0);
								}

}

void inserer_tabdec(int indice,int nature,int suivant,int region,int description,int execution){
								tabdecl[indice].nature = nature;
								tabdecl[indice].suivant = suivant;
								tabdecl[indice].region = region;
								tabdecl[indice].description = description;
								tabdecl[indice].execution = execution;
}
void inserer_fonction(int region,int description,int nombre_lexico){
	if(tabdecl[nombre_lexico].nature == -1) {
									inserer_tabdec(nombre_lexico, FONCTION, -1,region, description, 0);
									indice_declaration++;
	}
	else {
									int indice = trouver_indice_insertion(nombre_lexico);
									printf("%d\n",indice);

									inserer_tabdec(indice_debordement, FONCTION, -1, region, description, 0);
									tabdecl[indice].suivant = indice_debordement;
									indice_debordement++;
	}
}
void inserer_tab(int region,int nombre_lexico,int dimension){
	if(tabdecl[nombre_lexico].nature == -1) {
									inserer_tabdec(nombre_lexico, TAB, -1,region, indice_representation, 0);
									tabrep[indice_representation]=dimension;
									indice_representation++;
									indice_declaration++;
	}
	else {
									int indice = trouver_indice_insertion(nombre_lexico);

									inserer_tabdec(indice_debordement, TAB, -1, region, indice_representation, 0);
									tabdecl[indice].suivant = indice_debordement;
									tabrep[indice_representation]=dimension;
									indice_representation++;
									indice_debordement++;
	}
}
void inserer_struct(int region,int nombre_lexico,int nombre_elements){
	if(tabdecl[nombre_lexico].nature == -1) {
									inserer_tabdec(nombre_lexico, STRUCT, -1,region, indice_representation, 0);
									tabrep[indice_representation]=nombre_elements;
									indice_representation++;
									indice_declaration++;
	}
	else {
									int indice = trouver_indice_insertion(nombre_lexico);

									inserer_tabdec(indice_debordement, STRUCT, -1, region, indice_representation, 0);
									tabdecl[indice].suivant = indice_debordement;
									tabrep[indice_representation]=nombre_elements;
									indice_representation++;
									indice_debordement++;
	}
}
void inserer_var(int region,int nombre_lexico){
								if(tabdecl[nombre_lexico].nature == -1) {
																inserer_tabdec(nombre_lexico, VAR, -1,region, nombre_lexico, 0);
																indice_declaration++;
								}
								else {
																int indice = trouver_indice_insertion(nombre_lexico);
																inserer_tabdec(indice_debordement, VAR, -1, region, nombre_lexico, 0);
																tabdecl[indice].suivant = indice_debordement;
																indice_debordement++;
								}
}
void inserer_procedure(int region,int description,int nombre_lexico){
	if(tabdecl[nombre_lexico].nature == -1) {
									inserer_tabdec(nombre_lexico, PROC, -1,region, description, 0);
									indice_declaration++;
	}
	else {
									int indice = trouver_indice_insertion(nombre_lexico);
									printf("%d\n",indice);

									inserer_tabdec(indice_debordement, PROC, -1, region, description, 0);
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
								printf("***************           TABLE DE DECLARATION DES TYPES           ********************\n\n\n");


								fprintf(stdout,"\tnature\tsuivant\tregion\tdescription\texecution\n");
								for(i=0; i<indice_declaration; i++)
								{
																fprintf(stdout,"%d\t%d\t%d\t%d\t%d\t\t%d\n", i,tabdecl[i].nature, tabdecl[i].suivant,  tabdecl[i].region, tabdecl[i].description, tabdecl[i].execution );



								}




								printf("***************           ZONE DE DEBORDEMENT         ********************\n\n");
								fprintf(stdout,"\tnature\tsuivant\tregion\tdescription\texecution\n");
								if(indice_debordement>500) {
																for(i=500; i<indice_debordement; i++)
																{
																								fprintf(stdout,"%d\t%d\t%d\t%d\t%d\t\t%d\n",i, tabdecl[i].nature, tabdecl[i].suivant,  tabdecl[i].region, tabdecl[i].description, tabdecl[i].execution );
																}
								}








}


void affiche_represent()
{
								int i;
								printf("***************           TABLE DE REPRESENTATION DES TYPES           ********************\n\n\n");

								for(i=0; i<indice_representation; i++)
								{

																fprintf(stdout, "%d  i=  %d | ",tabrep[i],i);

								}

								printf("\n\n");


}
int main(int argc, char const *argv[])
{
								cree_tabdec();
								affiche_decla();
								inserer_var(1, 0);
								affiche_decla();
								inserer_var(2,0);
								affiche_decla();

								return 0;
}
