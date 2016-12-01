#include <stdio.h>
#include <stdlib.h>
#include <string.h>





typedef struct ElementPile{
	int entier ;
	float real;
	char chare;
	bool boolean;
}ElementPile ;

typedef struct Pile{
	ElementPile tab[800];
	int sommet;
	int tab_BC[300].
	int indice_BC ;

}Pile ;

ElementPile create_ElementPile(int i,char a,bool b,float s);
void empiler( ElementPile a, Pile p);
void depiler_Element(Pile p, int i);
void End_function();
