#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define FALSE false
#define CHAR '1'
#define INT NULL
#define FLOAT 1.0




typedef struct ElementPile {

								int entier;
								float real;
								char chare;
								char *monstring;

}ElementPile;



typedef struct Pile {
								ElementPile tab[20];
								int sommet;

}Pile;
Pile MaPile;

ElementPile create_ElementPile(int i,float s,char a,char b[]);
void empiler(ElementPile a);
void affiche_pile(Pile p);
