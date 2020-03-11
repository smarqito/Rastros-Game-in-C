#include "modules/data.h"
#include "modules/interface/interpretador.h"

int main() {
    ESTADO *e = initState();
    interpretador(e);
    return 0;
}