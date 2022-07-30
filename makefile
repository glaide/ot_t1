CC=gcc
#flags para warning, depuração e biblioteca de matematica
CFLAGS=-g -Wall 

#regras de ligação
mod = modelagem.o



%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) 

#variavel geral
all: despacho
#regras de compilação
despacho: $(mod)
	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY:	clean
#remove os arquivos temporarios e executaveis
clean: 

	rm *.o despacho

