#Targets

TARGET1=rastros.exe
TARGET2=li2pl6g05_bot

#Compilador

CC=gcc

#Flags a usar

CFLAGS=-std=gnu11 -Wall -Wextra -pedantic-errors -Wformat -O -g
INCLUDE=-I.

#Diretorias dos módulos

DIRMODULES=./modules
DIRLOGICA=$(DIRMODULES)/logica
DIRINTERFACE=$(DIRMODULES)/interface
DIRLISTAS=$(DIRMODULES)/listas
DIRGLOBALS=./globals
DIRBOT=./bot

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

globals.o: $(DIRGLOBALS)/globals.c $(DIRGLOBALS)/globals.h
	$(CC) $(CFLAGS) -c $(DIRGLOBALS)/globals.c

cores.o: $(DIRGLOBALS)/cores.c $(DIRGLOBALS)/cores.h
	$(CC) $(CFLAGS) -c $(DIRGLOBALS)/cores.c

interpretador.o: $(DIRINTERFACE)/interpretador.c $(DIRINTERFACE)/interpretador.h
	$(CC) $(CFLAGS) -c $(DIRINTERFACE)/interpretador.c

auxiliaresBot.o: $(DIRBOT)/auxiliaresBot.c $(DIRBOT)/auxiliaresBot.h
	$(CC) $(CFLAGS) -c $(DIRBOT)/auxiliaresBot.c -lm

bot.o: $(DIRBOT)/bot.c $(DIRBOT)/bot.h
	$(CC) $(CFLAGS) -c $(DIRBOT)/bot.c

data.o: $(DIRMODULES)/data.c $(DIRMODULES)/data.h
	$(CC) $(CFLAGS) -c $(DIRMODULES)/data.c

interface.o: $(DIRINTERFACE)/interface.c $(DIRINTERFACE)/interface.h
	$(CC) $(CFLAGS) -c $(DIRINTERFACE)/interface.c

ficheiros.o: $(DIRINTERFACE)/ficheiros.c $(DIRINTERFACE)/ficheiros.h
	$(CC) $(CFLAGS) -c $(DIRINTERFACE)/ficheiros.c

logica.o: $(DIRLOGICA)/logica.c $(DIRLOGICA)/logica.h
	$(CC) $(CFLAGS) -c $(DIRLOGICA)/logica.c

auxiliaresInterface.o: $(DIRINTERFACE)/auxiliaresInterface.c  $(DIRINTERFACE)/auxiliaresInterface.h
	$(CC) $(CFLAGS) -c $(DIRINTERFACE)/auxiliaresInterface.c

listas.o: $(DIRLISTAS)/listas.c $(DIRLISTAS)/listas.h
	$(CC) $(CFLAGS) -c $(DIRLISTAS)/listas.c

clean:
	rm $(TARGET1) $(DIRBOT)/$(TARGET2) $(LOGICA) $(INTERFACE) $(DADOS) $(LISTAS) $(BOT)