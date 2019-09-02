#supress warnings so that we can debug them!
CC = gcc -w -g -std=c99

gameOfLife: gameUtils.o gameOfLife.c
	$(CC) gameOfLife.c gameUtils.o -o gameOfLife.x -lncurses

gameFunctions.o: gameUtils.c gameUtils.h
	$(CC) -c -o gameUtils.o gameUtils.c

clean:
	rm -f *.o *~ gameOfLife.x
