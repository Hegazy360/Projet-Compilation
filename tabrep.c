#include "tabrep.h"
extern struct element tabdecl[1000];
int tabrep[1000];
int indice_representation = 0;

int taille_struct(int indice){
  int taille=0;
  printf("INDICE = %d\n",indice);
  printf("contenu = %d\n",tabrep[indice]);
  for(int i=indice+2;i<=indice+tabrep[indice]*2;i+=2){
    if(tabrep[i]==0){
      taille+=sizeof(int);
    }
    else if(tabrep[i]==1){
      taille+=sizeof(float);
    }
    else if(tabrep[i]==2){
      taille+=sizeof(int);
    }
    else if(tabrep[i]==3){
      taille+=sizeof(char);
    }
    else if(tabdecl[tabrep[i]].nature == T_STRUCT){
      taille+=tabdecl[tabrep[i]].execution;
    }
    else if(tabdecl[tabrep[i]].nature == T_TAB){
       taille+=tabdecl[tabrep[i]].execution;
    }
  }
  printf("%d\n",taille);
  return taille;
}
int taille_tab(int indice){
  int taille_type = tabdecl[tabrep[indice]].execution;
  int dimension =1;
  int counter = 0;
  int taille=0;
  for(int i=indice+1;i<indice+1+tabrep[indice+1]*2;i+=2){
    for(int j=tabrep[i+1];j<=tabrep[i+2];j++){
      counter++;
    }
    dimension *=counter;
    counter=0;
  }
  taille = taille_type*dimension;
  printf("taille tableau = %d\n",taille);
  return taille;
}
void inserer_tabrep(int indice,int valeur){
  tabrep[indice] = valeur;
}
void affiche_rep()
{

  int i;
  printf("*********************************\n");
  printf("TABLE DE REPRESENTATION DES TYPES\n");
  printf("*********************************\n");

  for(i=0; i<indice_representation; i++)
  {

                  fprintf(stdout, "%d->%d | ",i,tabrep[i]);

  }

  printf("\n\n");

}
void cree_tabrep(){
  for(int i=0; i<1000; i++) {
                  tabrep[i]= 0;
  }
}
