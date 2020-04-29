#Targets

TARGET1=rastros.exe
TARGET2=bot

#Compilador

CC=gcc

#Flags a usar

CFLAGS=-Wall -Wextra -pedantic -O2 -g
INCLUDE=-I.

#Módulos do programa

LOGICA=logica.o
INTERFACE=auxiliaresInterface.o interface.o ficheiros.o interpretador.o
DADOS=globals.o data.o cores.o
LISTAS=listas.o
BOT=bot.o auxiliaresBot.o

#Define que o makefile constroi os dois targets só chamando makefile

all: $(TARGET1) $(TARGET2)

$(TARGET1): main.o auxiliaresBot.o $(LOGICA) $(INTERFACE) $(DADOS) $(LISTAS)
	$(CC) $(CFLAGS) $(INCLUDE) main.o auxiliaresBot.o $(LOGICA) $(INTERFACE) $(DADOS) $(LISTAS) \
	-o $(TARGET1) -lm

$(TARGET2): $(BOT) $(LOGICA) $(DADOS) $(LISTAS) ficheiros.o interface.o auxiliaresInterface.o
	$(CC) $(CFLAGS) $(INPUT) $(BOT) $(LOGICA) $(DADOS) $(LISTAS) ficheiros.o interface.o auxiliaresInterface.o -o ./bot/$(TARGET2) -lm

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

globals.o: ./globals/globals.c ./globals/globals.h
	$(CC) $(CFLAGS) -c ./globals/globals.c

interpretador.o: ./modules/interface/interpretador.c ./modules/interface/interpretador.h
	$(CC) $(CFLAGS) -c ./modules/interface/interpretador.c

auxiliaresBot.o: ./bot/auxiliaresBot.c ./bot/auxiliaresBot.h
	$(CC) $(CFLAGS) -c ./bot/auxiliaresBot.c -lm

bot.o: ./bot/bot.c ./bot/bot.h
	$(CC) $(CFLAGS) -c ./bot/bot.c

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
	auxiliaresInterface.o auxiliaresBot.o data.o ficheiros.o logica.o \
	bot.o cores.o listas.o bot