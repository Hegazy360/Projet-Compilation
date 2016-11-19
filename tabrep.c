#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablex.c"


int TabRepresentation[1000];
int indice = 0;



void remplir(int champ){
        if(champ >= 0) {
                TabRepresentation[indice]=champ;
                indice++;
        }
}


void inserer_nbchamps(int nbchamp){
        TabRepresentation[indice]=nbchamp;
}


int inserer_champ(char *lexeme){
        int i;
        for(i=0; i <= COMPTEUR; i++) {
                if(strcmp(tablexico[i].lexeme,lexeme) == 0) {
                        printf("OK\n" );
                        remplir(i);
                        return 1;
                }
        }
        return -1;
}

int main(int argc, char const *argv[])
{
        // insererlex("OK1");
        // insererlex("OK2");
        // insererlex("OK3");
        // inserer_champ("OK3");
        // inserer_champ("OK2");
        // inserer_champ("NO");
        // printf("%d\n",TabRepresentation[0]);
        // printf("%d\n",TabRepresentation[1]);
        return 0;
}
