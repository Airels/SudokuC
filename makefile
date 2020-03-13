CC = gcc
PARAMS = -W
NAME = sudokuc

$(NAME): main.o resolver.o
	$(CC) -o $(NAME) main.o resolver.o $(PARAMS)

main.o: main.c
	$(CC) -c main.c $(PARAMS)

resolver.o: resolver.c
	$(CC) -c resolver.c $(PARAMS)