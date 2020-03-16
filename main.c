#include "modules/data.h"
#include "modules/interface/interpretador.h"
#include <stdio.h>

int main() {
    FILE *temp;
    temp=fopen("temp","w+");
    fclose(temp);
    ESTADO *e = initState();
    interpretador(e);
    return 0;
}