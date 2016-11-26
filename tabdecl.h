#include <stdio.h>
#include <stdlib.h>

#define MAXDECL 5000
#define STRUCT 1
#define TAB 2
#define VAR 3
#define PROC 4
#define FUNCTION 5

struct element
{
        int nature;
        int suivant;
        int region;
        int description;
        int execution;
};
struct element tabdecl[MAXDECL];
