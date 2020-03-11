#include "modules/data.h"
#include "modules/interpretador.h"

int main() {
    ESTADO *e = initState();
    interpretador(e);
    return 0;
}