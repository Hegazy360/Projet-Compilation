%{
#include "y.tab.h"
int numligne=1;
const int UNKNOWN=999;
/*enum {POINT_VIRGULE=1, DEBUT, FIN, REEL, ENTIER, PROG, TYPE, STRUCT, FSTRUCT, TABLEAU, VARIABLE, PROCEDURE, FONCTION,
RETOURNE, SI, ALORS, SINON, TANT_QUE, FAIRE, BOOLEEN, VIDE, CSTE_DECIMALE, CSTE_ENTIERE, CARACTERE, CHAINE, IDF, DEUX_POINTS, CROCHET_OUVRANT, CROCHET_FERMANT,
VIRGULE, POINT, PARENTHESE_OUVRANTE, PARENTHESE_FERMANTE, OPAFF, MOINS, MULT, DIV, PLUS, OP_COMP, UNKNOWN}*/
%}

lettre [a-zA-Z]
chiffre [0-9]
signe <(=)?|>(=)?|={2}|!=

%%
\;	{return (POINT_VIRGULE);}
\{	{return (DEBUT);}
\}	{return (FIN);}
float {yylval = atof(yytext);return (REEL);}
int {return (ENTIER);}
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
bool {return (BOOLEEN);}
vide {return (VIDE);}
true|false {return (BOOL);}
({chiffre})+\.({chiffre})+ {return (CSTE_REEL);}
({chiffre})+ {return (CSTE_ENTIERE);}
char {return (CARACTERE);}
string {return (CHAINE);}
{lettre}({lettre}|{chiffre})* {return (IDF);}
\:	{return (DEUX_POINTS);}
\[ {return (CROCHET_OUVRANT);}
\] {return (CROCHET_FERMANT);}
\, {return (VIRGULE);} 
\.{2} {return (POINT_2);}
\. {return (POINT);}
\( {return (PARENTHESE_OUVRANTE);}
\) {return (PARENTHESE_FERMANTE);}
:= {return (OPAFF);}
-	{return (MOINS);}
\*	{return (MULT);}
\/	{return (DIV);}
\+      {return (PLUS);}
{signe} {return (OP_COMP);}
[ \t]+   ;
\n {numligne++;}
. {return (UNKNOWN);}
%%

