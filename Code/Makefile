p1: FootballAnalyzer.o
	gcc -o p1 FootballAnalyzer.o -fopenmp -std=c99 

FootballAnalyzer.o: football.h bsort.c bfind.c orderPackage.c qsort.c qfind.c pfunc.c
	gcc -c FootballAnalyzer.c -fopenmp -std=c99

clean: 
	rm p1 FootballAnalyzer.o
