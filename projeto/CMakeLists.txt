cmake_minimum_required(VERSION 3.15)
project(rastros C)

set(CMAKE_C_STANDARD 99)

add_executable(rastros main.c modules/interface/ficheiros.c modules/interface/ficheiros.h modules/data.c modules/data.h modules/interface/interpretador.c modules/interface/interpretador.h modules/logica/logica.c modules/logica/logica.h modules/interface/interface.c modules/interface/interface.h ../bot/bot.c ../bot/bot.h modules/interface/auxiliaresInterface.c modules/interface/auxiliaresInterface.h globals/cores.c globals/cores.h globals/globals.h globals/globals.c "modules/listas /listas .c" "modules/listas /listas .h")