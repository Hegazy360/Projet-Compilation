CC= gcc -c
CCO= gcc -o
COMPIL= bison

#ifeq ($(COMPIL), bison) #Selon vous utilisiez LEX et YACC, ou FLEX et Bison
	#YACC= bison -d -v
	#LEX= flex
#else
	YACC= yacc -d -v
	LEX= lex
#endif

cpyrr: y.tab.c lex.yy.o tablex.o tabdecl.o pile.o pileRegion.o assnom.o tabrep.o tabregion.o arbre.o
	$(CCO) $@ lex.yy.o y.tab.c tablex.o tabdecl.o pile.o pileRegion.o assnom.o tabrep.o tabregion.o arbre.o -ly -ll -w
y.tab.c y.tab.h: cpyrr.y
	$(YACC) cpyrr.y
lex.yy.o: lex.yy.c
	$(CC) lex.yy.c
lex.yy.c: cpyrr.l
	$(LEX) cpyrr.l
tablex.o: tablex.c
	$(CC) tablex.c
tabdecl.o: tabdecl.c
	$(CC) tabdecl.c
pile.o: pile.c
	$(CC) pile.c
pileRegion.o: pileRegion.c
	$(CC) pileRegion.c
assnom.o: assnom.c
	$(CC) assnom.c
tabrep.o: tabrep.c
	$(CC) tabrep.c
tabregion.o: tabregion.c
	$(CC) tabregion.c
arbre.o: arbre.c
	$(CC) arbre.c

clean:
	rm *.o cpyrr.output y.output
