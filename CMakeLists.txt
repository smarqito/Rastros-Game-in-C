cmake_minimum_required(VERSION 3.15)
project(rastros C)

set(CMAKE_C_STANDARD 99)

add_executable(rastros main.c globals/globals.h modules/logica/ficheiros.c modules/logica/ficheiros.h modules/data.c modules/data.h modules/interface/interpretador.c modules/interface/interpretador.h modules/logica/logica.c modules/logica/logica.h modules/interface/interface.c modules/interface/interface.h modules/logica/bot.c modules/logica/bot.h globals/globals.c modules/interface/auxiliaresInterface.c modules/interface/auxiliaresInterface.h globals/cores.c globals/cores.h)