YACC= yacc -d -v
CC= gcc -c
CCO= gcc -o
LEX= lex


cpyrr: lex.yy.o y.tab.c
	$(CCO) $@ lex.yy.o y.tab.c -ly -ll
lex.yy.o: lex.yy.c
	$(CC) lex.yy.c
lex.yy.c: cpyrr.l
	$(LEX) cpyrr.l
y.tab.c: cpyrr.y
	$(YACC) cpyrr.y

