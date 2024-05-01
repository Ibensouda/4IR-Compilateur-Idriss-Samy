all: html

html.tab.c html.tab.h:	html.y
	bison -t -v -d html.y

lex.yy.c: html.l html.tab.h
	flex html.l

html: lex.yy.c html.tab.c html.tab.h tds.h tdi.h
	gcc -o html html.tab.c lex.yy.c tds.c tdi.c

clean:
	rm html html.tab.c lex.yy.c html.tab.h html.output

test: all
	cat test.c | ./html
