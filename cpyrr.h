#include <stdio.h>
#include <stdlib.h>


typedef struct noeud_struct
{
	int valeur;
	struct noeud_struct *pere;
	struct noeud_struct *filsgauche;
	struct noeud_struct *filsdroite;
}noeud;
typedef noeud * arbre;
