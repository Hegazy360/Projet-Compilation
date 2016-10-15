%{
#include "y.tab.h"
int numligne=1;
%}
%%
\;	{return (POINT_VIRGULE);}
\{	{return (DEBUT);}
\}	{return (FIN);}
0|[1-9][0-9]*\.[0-9]* {yylval = atof(yytext);return (REEL);}
0|[1-9][0-9]* {yylval = atoi(yytext);return (ENTIER);}
prog {return (PROG);}
type {return (TYPE);}
struct  {return (STRUCT);}
endstruct  {return (FSTRUCT);}
array {return (TABLEAU);}
var {return (VARIABLE);}
procedure {return (PROCEDURE);}
function {return (FONCTION);}
return {return (RETOURNE);}
if {return (SI);}
then {return (ALORS);}
else {return (SINON);}
while {return (TANT_QUE);}
do {return (FAIRE);}
(true|false) {return (BOOLEEN);}
"" {return (VIDE);}
[A-Z]* {return (CSTE_ENTIERE);}
[a-zA-Z] {return (CARACTERE);}
[a-zA-Z][a-zA-Z0-9]* {return (IDF);printf("OK");}
[a-zA-Z0-9]* {return (CHAINE);}
\:	{return (DEUX_POINTS);}
\[ {return (CROCHET_OUVRANT);}
\] {return (CROCHET_FERMANT);}
\, {return (VIRGULE);}
\. {return (POINT);}
\( {return (PARENTHESE_OUVRANTE);}
\) {return (PARENTHESE_FERMANTE);}
:= {return (OPAFF);}
[ \t]+ ;
\n {numligne++;}
. {printf("Attention %s!\n",yytext);}
%%


