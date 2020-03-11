rastros.exe: main.o globals.o data.o interpretador.o interface.o logica.o bot.o
	gcc -o rastros.exe main.o globals.o data.o interpretador.o interface.o logica.o bot.o

main.o: main.c
	gcc -c main.c

globals.o: globals.c
	gcc -c globals.c

interpretador.o: ./modules/interpretador.c
	gcc -c ./modules/interpretador.c

bot.o: ./modules/logica/bot.c
	gcc -c ./modules/logica/bot.c

data.o: ./modules/data.c
	gcc -c ./modules/data.c

interface.o: ./modules/interface/interface.c
	gcc -c ./modules/interface/interface.c

logica.o: ./modules/logica/logica.c
	gcc -c ./modules/logica/logica.c