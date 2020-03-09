cmake_minimum_required(VERSION 3.15)
project(rastros C)

set(CMAKE_C_STANDARD 99)

add_executable(rastros main.c globals.c globals.h mainLogica.c mainLogica.h ficheiros.c modules/coordenada.c modules/coordenada.h ficheiros.h modules/data.c modules/data.h modules/interpretador.c modules/interpretador.h modules/logica/logica.c modules/logica/logica.h modules/interface/interface.c modules/interface/interface.h)