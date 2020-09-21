mymat: mymat.o mat.o helpermat.o mat.h
	gcc -g -Wall -ansi -pedantic mymat.o mat.o helpermat.o mat.h -o mymat

mymat.o: mymat.c
	gcc -c -Wall -ansi -pedantic mymat.c -o mymat.o

mat.o: mat.c
	gcc -c -Wall -ansi -pedantic mat.c -o mat.o

helpermat.o: helpermat.c
	gcc -c -Wall -ansi -pedantic helpermat.c -o helpermat.o
