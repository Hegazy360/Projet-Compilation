#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablex.h"

void insererlex(char* lexeme){
        int i=0; //printf("ok\n");
        int ok = 1;
        for(i=0;i<=COMPTEUR;i++){
          if((strcmp(tablexico[i].lexeme,lexeme)==0)){
            ok=0;
            printf("PAS POSSIBLE\n");
          }
        }
        if(ok == 1){
                  strcpy(tablexico[i].lexeme, lexeme);
                  tablexico[i].longueur=strlen(lexeme);
                  tablexico[i].suivant=0;
                  COMPTEUR++;
                  printf("INSERTION SUCCESS\n");
        }

}

// int main(){
// //tablexico tab;//=(tablexico)molloc(Max*sizeof(tablex));
//         insererlex("OK1");
//         insererlex("OK2");
//         insererlex("OK3");
//         for(int i=0;i<=COMPTEUR;i++){
//           printf("%s\n",tablexico[i].lexeme);
//         }
//         return 0;
// }
