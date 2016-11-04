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
arbre creeArbreVide(){
	return NULL;
}
arbre creeArbre(int valeur){
	arbre A=malloc(sizeof(noeud));
	A->valeur = valeur;
	A->pere = NULL;
	A->filsgauche = NULL;
	A->filsdroite = NULL;
	return A;	
}
arbre concat_father_brother(arbre a1,arbre a2){
	if(a1->pere != NULL)
		a1->pere->filsdroite = a2;
	else
		printf("Erreur Concatenation : Racine pas de pere\n");
	return a1;
}
arbre concat_father_son(arbre a1,arbre a2){
	a1->filsgauche = a2;
	return a1;
}
void afficheArbre(arbre a){
	if(a != NULL){
		printf("%d\n", a->valeur);
		afficheArbre(a->filsgauche);
		afficheArbre(a->filsdroite);
	}
}
int main(int argc, char const *argv[])
{
	arbre A=creeArbre(7);
	concat_father_son(A,creeArbre(2));
	concat_father_brother(A,creeArbre(4));
	afficheArbre(A);
	return 0;
}