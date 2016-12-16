#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablex.h"

int compter;
int num_lex;
void creertablexico(){
								tablexico[0].longueur=3;
								strcpy(tablexico[0].lexeme,"int");
								tablexico[0].suivant=-1;

								tablexico[1].longueur=5;
								strcpy(tablexico[1].lexeme,"float");
								tablexico[1].suivant=-1;

								tablexico[2].longueur=4;
								strcpy(tablexico[2].lexeme,"bool");
								tablexico[2].suivant=-1;

								tablexico[3].longueur=4;
								strcpy(tablexico[3].lexeme,"char");
								tablexico[3].suivant=-1;
								compter=3;
}
void insererlex(char* lexeme){
								int i=0; //printf("ok\n");
								int ok = 1;

								for(i=0; i<=compter; i++) {
																if((strcmp(tablexico[i].lexeme,lexeme)==0)) {
																								ok=0;
																								// printf("PAS POSSIBLE\n");
																}
								}
								if(ok == 1) {
																strcpy(tablexico[i].lexeme, lexeme);
																tablexico[i].longueur=strlen(lexeme);
																tablexico[i].suivant=-1;
																compter+=1;
																//  printf("INSERTION SUCCESS %s %d\n",tablexico[i].lexeme,compter);
								}
								num_lex=compter;
}
int indice(char*lexeme){
								int i;
								for(i=0; i<=num_lex; i++) {
																if((strcmp(tablexico[i].lexeme,lexeme)==0)) {
																								return i;
																}
								}
								return -1;
}
void affichage_tab_lex(){
								int i=0;
								printf("	LONGUEUR             LEXEME              SUIVANT\n");
								printf("*********************\n");
								printf("TABLE LEXICOGRAPHIQUE\n");
								printf("*********************\n");


								fprintf(stdout,"\tlongueur\tlexeme\tsuivant\n");
								for(i=0; i<=compter; i++) {
									fprintf(stdout,"%d\t%d\t\t%s\t%d\n", i,tablexico[i].longueur, tablexico[i].lexeme, tablexico[i].suivant);
								}
}

/*int main(){
   // //tablexico tab;//=(tablexico)molloc(Max*sizeof(tablex));
        insererlex("OK1");
       insererlex("OK2");
       insererlex("OK3");
        for(int i=0;i<=compter;i++){
          printf("%s\n",tablexico[i].lexeme);
        }
        return 0;
   }*/
