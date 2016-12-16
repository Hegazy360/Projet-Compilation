#include "arbre.h"



arbre creer_noeud(int nat,int valeur){
        arbre a;
        a=(noeud*)malloc(1*sizeof(noeud));
        a->fils = NULL;
        a->frere = NULL;
        a->nature=nat;
        a->valeur=valeur;
        return a;
}

arbre concat_father_son(arbre pere, arbre fils){
        pere->fils = fils;
        return pere;
}
arbre concat_father_brother(arbre pere, arbre frere){
        pere->frere = frere;
        return pere;
}

arbre insere_arbre(arbre a1, arbre a2){

        a1 = concat_father_son(creer_noeud(T_LIST,-999),concat_father_brother(a1,concat_father_son(creer_noeud(T_LIST,-999), a2)));
        return a1;
}


void affiche_element(arbre n){
        int i;
        printf("\n");
        printf("* ");
        printf("%s * %d\n", nature_arbre(n->nature),n->valeur);
}

arbre pere(arbre pere,arbre fils){
        arbre p=pere;
        while (p->fils!=fils) {
                p=p->fils;
        }
        return p;
}
arbre dernier_fils(arbre a){
        while (a->fils!=NULL)
                a=a->fils;
        return a;
}


void affiche_fils(arbre a){
        while (a->fils!=NULL)
        {
                printf("\n");
                affiche_element(a->fils);
                a=a->fils;
        }
}

void affiche_frere(arbre a){
        while(a->frere!=NULL) {
                printf("\n");
                affiche_fils(a->frere);
        }
}


int _affiche_arbre(arbre tree, int is_left, int offset, int depth, char s[20][255])
{
        char b[20];
        int width = 4;

        if (tree == NULL) return 0;
        sprintf(b, "(%03d)", tree->nature);

        int left  = _affiche_arbre(tree->fils,  1, offset, depth + 1, s);
        int right=1;
        if(tree->fils) {
                if(tree->fils->frere) {
                        right = _affiche_arbre(tree->fils->frere, 0, offset + left + width+1, depth + 1, s);
                }
        }
#define COMPACT
#ifdef COMPACT
        for (int i = 0; i < width; i++)
                s[depth][offset + left + i] = b[i];

        if (depth && is_left) {

                for (int i = 0; i < width + right; i++)
                        s[depth - 1][offset + left + width/2 + i] = '-';

                s[depth - 1][offset + left + width/2] = '.';

        } else if (depth && !is_left) {

                for (int i = 0; i < left + width; i++)
                        s[depth - 1][offset - width/2 + i] = '-';

                s[depth - 1][offset + left + width/2] = '.';
        }
#else

        for (int i = 0; i < width; i++)
                s[2 * depth][offset + left + i] = b[i];

        if (depth && is_left) {

                for (int i = 0; i < width + right; i++)
                        s[2 * depth - 1][offset + left + width/2 + i] = '-';

                s[2 * depth - 1][offset + left + width/2] = '+';
                s[2 * depth - 1][offset + left + width + right + width/2] = '+';

        } else if (depth && !is_left) {

                for (int i = 0; i < left + width; i++)
                        s[2 * depth - 1][offset - width/2 + i] = '-';

                s[2 * depth - 1][offset + left + width/2] = '+';
                s[2 * depth - 1][offset - width/2 - 1] = '+';
        }
#endif

        return left + width +right;
}

void affiche_arbre(arbre tree)
{
        char s[20][255];
        for (int i = 0; i < 20; i++)
                sprintf(s[i], "%80s", " ");

        _affiche_arbre(tree, 0, 0, 0, s);

        for (int i = 0; i < 20; i++)
                printf("%s\n", s[i]);
}
char* nature_arbre (int nature){
        switch (nature) {
        case 0:
                return "T_INT"; break;
        case 1:
                return "T_FLOAT"; break;
        case 2:
                return "T_BOOL"; break;
        case 3:
                return "T_CHAR"; break;
        case 4:
                return "T_STRING"; break;
        case 5:
                return "T_PLUS"; break;
        case 6:
                return "T_MOINS"; break;
        case 7:
                return "T_DIV"; break;
        case 8:
                return "T_MULT"; break;
        case 9:
                return "T_SUP"; break;
        case 10:
                return "T_INF"; break;
        case 11:
                return "T_EG"; break;
        case 12:
                return "T_DIF"; break;
        case 13:
                return "T_SUPEG"; break;
        case 14:
                return "T_INFEG"; break;
        case 15:
                return "T_OPAFF"; break;
        case 16:
                return "T_IDF"; break;
        case 17:
                return "T_IF"; break;
        case 18:
                return "T_THEN"; break;
        case 19:
                return "T_ELSE"; break;
        case 20:
                return "T_FOR"; break;
        case 21:
                return "T_WHILE"; break;
        case 22:
                return "T_FONC"; break;
        case 23:
                return "T_PROCE"; break;
        case 24:
                return "T_ET"; break;
        case 25:
                return "T_OU"; break;
        case 26:
                return "T_LIST"; break;
        case 27:
                return "T_CSTE"; break;
        case 28:
                return "T_REEL"; break;
        case 29:
                return "T_APPEL_FONC"; break;
        case 30:
                return "T_APPEL_PROC"; break;
        case 31:
                return "T_VIDE"; break;
        case 32:
                return "T_OP"; break;
        case 33:
                return "T_RETOURNE"; break;

        default:
                return "INCONNU";
        }
}
