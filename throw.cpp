#include <stdio.h>
#include <string>

int main() {

char algo[] = "errorDEprueba: Parametro Invalido";


  char algo[] = "errorDEprueba: Parametro Invalido";
    try {
        printf("Punto de inicio. Mensaje: ");
        throw algo;
        printf("Este mensaje nunca se imprimirá despues del throw.\n");
    } catch (char* e) {
        printf("--- Excepción capturada ---\n");
        printf("Indicación de error: %s\n", e);
    }

    printf("Programa finalizado correctamente (Terminación controlada).\n");

    return 0;
}
