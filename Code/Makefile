p1: FootballAnalyzer.o
	gcc -o p1 FootballAnalyzer.o -std=c99 

FootballAnalyzer.o: football.h bsort.c bfind.c orderPackage.c
	gcc -c FootballAnalyzer.c -std=c99

clean: 
	rm p1 FootballAnalyzer.o
