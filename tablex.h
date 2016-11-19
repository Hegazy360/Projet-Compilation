#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 500
int COMPTEUR=-1;
struct tablex {
        int longueur;
        char lexeme[50];
        int suivant;
};
struct tablex tablexico[Max];
void insererlex(char *lexeme);
