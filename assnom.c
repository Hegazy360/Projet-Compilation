#include "assnom.h"

int region=-1;
int association_nom(){
  int trouver = 0;
  int indice_tabdecl = num_association_nom;
  int i = top;
  while(trouver == 0 && i>-1){
   if(tabdecl[indice_tabdecl].nature != -1){

    if(tabdecl[indice_tabdecl].region == getValeur(i)){
      region=getValeur(i);
      trouver = 1;
    }
    else {
      if(tabdecl[indice_tabdecl].suivant!=-1){
        indice_tabdecl = tabdecl[indice_tabdecl].suivant;
      }
      else {
        indice_tabdecl = num_association_nom;
        i--;
      }
    }
  }
  else {
    return -2;
  }
  }
  if(trouver==0){
    return -2;
  }
if(indice_tabdecl == 0){
  taille+=4;
}
else if (indice_tabdecl == 1){
  taille+=4;
}
else if(indice_tabdecl == 2){
  taille+=1;
}
else {
  taille+=1;
}
return indice_tabdecl;
}
int region_declaration(){
  return region;
}
// int main(int argc, char const *argv[]) {
//   printf("%d\n",valeurTop() );
//   return 0;
// }
