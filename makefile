TARGET=rastros.exe

INCLUDE=-I.

CC=gcc
CFLAGS=-Wall -O2 -ggdb


rastros.exe: main.o globals.o data.o interpretador.o interface.o logica.o bot.o ficheiros.o auxiliaresInterface.o cores.o listas.o
	$(CC) $(CFLAGS) $(INCLUDE) main.o globals.o data.o interpretador.o interface.o \
	logica.o bot.o ficheiros.o auxiliaresInterface.o cores.o listas.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

globals.o: ./globals/globals.c ./globals/globals.h
	$(CC) $(CFLAGS) -c ./globals/globals.c

interpretador.o: ./modules/interface/interpretador.c ./modules/interface/interpretador.h
	$(CC) $(CFLAGS) -c ./modules/interface/interpretador.c

bot.o: ./modules/logica/bot.c ./modules/logica/bot.h
	$(CC) $(CFLAGS) -c ./modules/logica/bot.c

data.o: ./modules/data.c ./modules/data.h
	$(CC) $(CFLAGS) -c ./modules/data.c

interface.o: ./modules/interface/interface.c ./modules/interface/interface.h
	$(CC) $(CFLAGS) -c ./modules/interface/interface.c

ficheiros.o: ./modules/interface/ficheiros.c ./modules/interface/ficheiros.h
	$(CC) $(CFLAGS) -c ./modules/interface/ficheiros.c

logica.o: ./modules/logica/logica.c ./modules/logica/logica.h
	$(CC) $(CFLAGS) -c ./modules/logica/logica.c

auxiliaresInterface.o: ./modules/interface/auxiliaresInterface.c  ./modules/interface/auxiliaresInterface.h
	$(CC) $(CFLAGS) -c ./modules/interface/auxiliaresInterface.c

cores.o: ./globals/cores.c ./globals/cores.h
	$(CC) $(CFLAGS) -c ./globals/cores.c

listas.o: ./modules/listas/listas.c ./modules/listas/listas.h
	$(CC) $(CFLAGS) -c ./modules/listas/listas.c

clean:
	rm rastros.exe main.o globals.o interface.o interpretador.o \
	auxiliaresInterface.o bot.o data.o ficheiros.o logica.o cores.o listas.o