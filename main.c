#include "modules/data.h"
#include "modules/interpretador.h"
#include "modules/logica/logica.h"

int main() {
    ESTADO *e = initState();
    interpretador(e);
    COORDENADA cord = {1,1};
    jogar(e,cord);
    return 0;
}