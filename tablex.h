#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 500
//int compter=-1;
struct tablex {
        int longueur;
        char lexeme[50];
        int suivant;
};
struct tablex tablexico[Max];
void creertablexico();
int indice(char*lexeme);
void insererlex(char *lexeme);
void affichage_tab_lex();
