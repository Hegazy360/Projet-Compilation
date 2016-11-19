#include <stdio.h>
#include <stdlib.h>
#include "tabdecl.h"


void inserer_nature(int indice,int nature){
	tabdecl[indice].nature = nature;
}
void inserer_suivant(int indice,int suivant)
{
	tabdecl[indice].suivant = suivant;

}
void inserer_region(int indice,int region){
	tabdecl[indice].region = region;
}
void inserer_description(int indice,int suivant){
	tabdecl[indice].suivant = suivant;
}
void inserer_execution(int indice,int execution){
	tabdecl[indice].execution = execution;
}
int trouver_indice_insertion(int num){
	int indice = 0;
	while(tabdecl[indice].nature != '\0'){
		indice++;
	}
	indice++;
	tabdecl[num].suivant = indice;
	return indice;
}

// int main(int argc, char const *argv[])
// {
// 	inserer_nature(0,1);
// 	printf("%d\n",tabdecl[0].nature);
// 	inserer_nature(1,1);
// 	printf("%d\n", trouver_indice_insertion(0));
// 	printf("%d\n",tabdecl[0].suivant);
// 	return 0;
// }
