rastros.exe: main.o globals.o data.o interpretador.o interface.o logica.o bot.o ficheiros.o auxiliaresInterface.o cores.o listas.o
	gcc -o rastros.exe main.o globals.o data.o interpretador.o interface.o logica.o bot.o ficheiros.o auxiliaresInterface.o cores.o listas.o

main.o: main.c
	gcc -c main.c

globals.o: ./globals/globals.c ./globals/globals.h
	gcc -c ./globals/globals.c

interpretador.o: ./modules/interface/interpretador.c ./modules/interface/interpretador.h
	gcc -c ./modules/interface/interpretador.c

bot.o: ./modules/logica/bot.c ./modules/logica/bot.h
	gcc -c ./modules/logica/bot.c

data.o: ./modules/data.c ./modules/data.h
	gcc -c ./modules/data.c

interface.o: ./modules/interface/interface.c ./modules/interface/interface.h
	gcc -c ./modules/interface/interface.c

ficheiros.o: ./modules/interface/ficheiros.c ./modules/interface/ficheiros.h
	gcc -c ./modules/interface/ficheiros.c

logica.o: ./modules/logica/logica.c ./modules/logica/logica.h
	gcc -c ./modules/logica/logica.c

auxiliaresInterface.o: ./modules/interface/auxiliaresInterface.c ./modules/interface/auxiliaresInterface.h
	gcc -c ./modules/interface/auxiliaresInterface.c

cores.o: ./globals/cores.c ./globals/cores.h
	gcc -c ./globals/cores.c

listas.o: ./modules/listas/listas.c ./modules/listas/listas.h
	gcc -c ./modules/listas/listas.c