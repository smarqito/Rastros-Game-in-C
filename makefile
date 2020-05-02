#Targets

TARGET1=rastros.exe
TARGET2=li2pl6g05_bot

#Compilador

CC=gcc

#Flags a usar

CFLAGS=-std=gnu11 -Wall -Wextra -pedantic-errors -Wformat -O -g
INCLUDE=-I.

#Diretorias dos módulos

#raiz
DIRPROJETO=./projeto
DIRBOT=./bot
DIROBJETOS=./objetos

DIRMODULES=$(DIRPROJETO)/modules

DIRLOGICA=$(DIRMODULES)/logica
DIRINTERFACE=$(DIRMODULES)/interface
DIRLISTAS=$(DIRMODULES)/listas
DIRGLOBALS=$(DIRPROJETO)/globals

#Módulos do programa

MAIN=$(DIROBJETOS)/main.o
LOGICA=$(DIROBJETOS)/logica.o
INTERFACE=$(DIROBJETOS)/auxiliaresInterface.o $(DIROBJETOS)/interface.o $(DIROBJETOS)/ficheiros.o $(DIROBJETOS)/interpretador.o
DADOS=$(DIROBJETOS)/globals.o $(DIROBJETOS)/data.o $(DIROBJETOS)/cores.o
LISTAS=$(DIROBJETOS)/listas.o
BOT=$(DIROBJETOS)/bot.o $(DIROBJETOS)/auxiliaresBot.o

#Define que o makefile constroi os dois targets só chamando makefile
all: prepare $(TARGET1) $(TARGET2)

prepare:
	mkdir -p objetos

$(TARGET1): $(MAIN) $(DIROBJETOS)/auxiliaresBot.o $(LOGICA) $(INTERFACE) $(DADOS) $(LISTAS)
	$(CC) $(CFLAGS) $(INCLUDE) $(MAIN) $(DIROBJETOS)/auxiliaresBot.o $(LOGICA) $(INTERFACE) $(DADOS) $(LISTAS) \
	-o $(TARGET1) -lm

$(TARGET2): $(BOT) $(LOGICA) $(DADOS) $(LISTAS) $(DIROBJETOS)/ficheiros.o $(DIROBJETOS)/interface.o $(DIROBJETOS)/auxiliaresInterface.o
	$(CC) $(CFLAGS) $(INPUT) $(BOT) $(LOGICA) $(DADOS) $(LISTAS) $(DIROBJETOS)/ficheiros.o $(DIROBJETOS)/interface.o $(DIROBJETOS)/auxiliaresInterface.o -o ./bot/$(TARGET2) -lm

$(DIROBJETOS)/main.o: $(DIRPROJETO)/main.c
	$(CC) $(CFLAGS) -c $(DIRPROJETO)/main.c -o $@

$(DIROBJETOS)/globals.o: $(DIRGLOBALS)/globals.c $(DIRGLOBALS)/globals.h
	$(CC) $(CFLAGS) -c $(DIRGLOBALS)/globals.c -o $@

$(DIROBJETOS)/cores.o: $(DIRGLOBALS)/cores.c $(DIRGLOBALS)/cores.h
	$(CC) $(CFLAGS) -c $(DIRGLOBALS)/cores.c -o $@

$(DIROBJETOS)/interpretador.o: $(DIRINTERFACE)/interpretador.c $(DIRINTERFACE)/interpretador.h
	$(CC) $(CFLAGS) -c $(DIRINTERFACE)/interpretador.c -o $@

$(DIROBJETOS)/auxiliaresBot.o: $(DIRBOT)/auxiliaresBot.c $(DIRBOT)/auxiliaresBot.h
	$(CC) $(CFLAGS) -c $(DIRBOT)/auxiliaresBot.c -lm -o $@

$(DIROBJETOS)/bot.o: $(DIRBOT)/bot.c $(DIRBOT)/bot.h
	$(CC) $(CFLAGS) -c $(DIRBOT)/bot.c -o $@

$(DIROBJETOS)/data.o: $(DIRMODULES)/data.c $(DIRMODULES)/data.h
	$(CC) $(CFLAGS) -c $(DIRMODULES)/data.c -o $@

$(DIROBJETOS)/interface.o: $(DIRINTERFACE)/interface.c $(DIRINTERFACE)/interface.h
	$(CC) $(CFLAGS) -c $(DIRINTERFACE)/interface.c -o $@

$(DIROBJETOS)/ficheiros.o: $(DIRINTERFACE)/ficheiros.c $(DIRINTERFACE)/ficheiros.h
	$(CC) $(CFLAGS) -c $(DIRINTERFACE)/ficheiros.c -o $@

$(DIROBJETOS)/logica.o: $(DIRLOGICA)/logica.c $(DIRLOGICA)/logica.h
	$(CC) $(CFLAGS) -c $(DIRLOGICA)/logica.c -o $@

$(DIROBJETOS)/auxiliaresInterface.o: $(DIRINTERFACE)/auxiliaresInterface.c  $(DIRINTERFACE)/auxiliaresInterface.h
	$(CC) $(CFLAGS) -c $(DIRINTERFACE)/auxiliaresInterface.c -o $@

$(DIROBJETOS)/listas.o: $(DIRLISTAS)/listas.c $(DIRLISTAS)/listas.h
	$(CC) $(CFLAGS) -c $(DIRLISTAS)/listas.c -o $@

clean:
	rm -r $(TARGET1) $(DIRBOT)/$(TARGET2) objetos