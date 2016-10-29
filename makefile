CC= gcc -c
CCO= gcc -o
COMPIL= bison

ifeq ($(COMPIL), bison) #Selon vous utilisiez LEX et YACC, ou FLEX et Bison
	YACC= bison -d -v
	LEX= flex
else
	YACC= yacc -d -v
	LEX= lex
endif

cpyrr: lex.yy.o y.tab.c
	$(CCO) $@ lex.yy.o y.tab.c -ly -ll
lex.yy.o: lex.yy.c
	$(CC) lex.yy.c
lex.yy.c: cpyrr.l
	$(LEX) cpyrr.l
y.tab.c: cpyrr.y
	$(YACC) cpyrr.y

