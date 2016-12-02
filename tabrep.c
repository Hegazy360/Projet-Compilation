#include "tabrep.h"

int tabrep[1000];
int indice_representation = 0;


void inserer_tabrep(int indice,int valeur){
  tabrep[indice] = valeur;
}
void affiche_rep()
{

  int i;
  printf("***************           TABLE DE REPRESENTATION DES TYPES           ********************\n\n\n");

  for(i=0; i<indice_representation; i++)
  {

                  fprintf(stdout, "%d->%d | ",i,tabrep[i]);

  }

  printf("\n\n");

}
