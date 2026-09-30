CC = gcc
CFLAGS = -Wall -Wextra -std=c11

LISTA_SEQUENCIAL = lista_sequencial
OBJETOS = main.o ListaSequencial.o

$(LISTA_SEQUENCIAL): $(OBJETOS)
	$(CC) $(CFLAGS) $(OBJETOS) -o $(LISTA_SEQUENCIAL)

main.o: main.c ListaSequencial.h
	$(CC) $(CFLAGS) -c main.c -o main.o

ListaSequencial.o: ListaSequencial.c ListaSequencial.h
	$(CC) $(CFLAGS) -c ListaSequencial.c -o ListaSequencial.o

clean:
	rm -f $(OBJETOS) $(LISTA_SEQUENCIAL)

.PHONY: clean
