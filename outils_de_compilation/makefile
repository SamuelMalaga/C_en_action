CC=gcc
CFLAGS=-Wall -DOS_LINUX="\"$(shell uname -s)\""
DEPS= hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.o hellofunc.o
	$(CC) -o hellomake hellomake.o hellofunc.o
