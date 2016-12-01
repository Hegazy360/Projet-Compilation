#include "pileRegion.h"
int MAXSIZE = 60;
int pileRegion[60];
int top = -1;

int estVide() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int estPlein() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int valeurTop() {
   return pileRegion[top];
}
int getValeur(int i){
  return pileRegion[i];
}

int depile() {
   int valeur;

   if(!estVide()) {
      valeur = pileRegion[top];
      top = top - 1;
      return valeur;
   } else {
      printf("PileRegion est vide\n");
   }
}
int taillePileRegion(){
  return top+1;
}

int empile(int valeur) {

   if(!estPlein()) {
      top = top + 1;
      pileRegion[top] = valeur;
   } else {
      printf("PileRegion est plein\n");
   }
}
void affichePileRegion(){
for(int i=top;i>=0;i--){
  printf("REGION %d\n",pileRegion[i]);
}
}
// int main() {
//    // empile items on to the stack
//    empile(1);
//    affichePileRegion();
//    empile(13);
//    printf("%d\n",depile() );
//    return 0;
// }
