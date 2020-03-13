CC = gcc
PARAMS = -W

sudokuc: main.o resolver.o
	$(CC) -o sudokuc main.o resolver.o $(PARAMS)

main.o: main.c
	$(CC) -c main.c $(PARAMS)

resolver.o: resolver.c
	$(CC) -c resolver.c $(PARAMS)