#include "pile.h"



ElementPile create_ElementPile(int i,float s,char a,char b[]){
        ElementPile e;
        e.entier = i;
        e.real = s;
        e.chare =a;
        e.monstring= b;
        return e;
}



void empiler(ElementPile a){
        MaPile.tab[MaPile.sommet] = a;
        MaPile.sommet += 1;
}


// void affiche_pile(Pile p){
//         int i;
//         printf("%d",0);
//         printf("      _ \n");
//         printf(" |          | \n ");
//         printf("|  %d      | \n", -1);
//         printf(" |          | \n");
//         printf(" |          | " );
//         printf("\n");
//
//
//
//         for(i=0; i<10; i++) {
//                 printf("%d",i);
//                 printf("      _ \n");
//                 printf(" | %d         | \n ", MaPile.tab[i].entier);
//                 printf("|  %f | \n", MaPile.tab[i].real);
//                 printf(" | %c         | \n", MaPile.tab[i].chare);
//                 printf(" | %s       |\n", MaPile.tab[i].monstring);
//                 printf("\n");
//
//         }
//
// }

//
// int main(){
//         MaPile.sommet = 0;
//
//
//         empiler(create_ElementPile(5,FLOAT,CHAR,""));
//         empiler(create_ElementPile(8,FLOAT,CHAR," ggs"));
//         empiler(create_ElementPile(-1,FLOAT,'A',"ueo"));
//         affiche_pile(MaPile);
//         return 0;
// }
