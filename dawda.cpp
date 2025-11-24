#include <stdio.h>

int diaInicio(int year, int mes) {
    int j = year / 100;
    int k = year % 100;

    // Ajustar el mes para la fórmula de Zeller
    if (mes < 2) {
        mes = mes + 12;
        year = year - 1;
    }

    // Fórmula de Zeller mejorada para que 0 sea sábado
    return (1 + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 - 2 * j + 6) % 7;
}
int main() {
    int year, mes;
    int diaSemana = diaInicio(year, mes);
    // Pedimos mes
    printf("¿Mes (1-12)? ");
    scanf("%i", &mes);

    // Pedimos año
    printf("¿Año (1601-3000)? ");
    scanf("%i", &year);

    if (!(1601 <= year && year <= 3000)) {
        printf("Error: introduce un año válido.\n");
        return 0;
    }

    // Llamamos a la función diaInicio


    printf("El 1 de enero de %i es ", year);

    switch (diaSemana) {
        case 0: printf("Sábado\n"); break;
        case 1: printf("Domingo\n"); break;
        case 2: printf("Lunes\n"); break;
        case 3: printf("Martes\n"); break;
        case 4: printf("Miércoles\n"); break;
        case 5: printf("Jueves\n"); break;
        case 6: printf("Viernes\n"); break;
        default: printf("Error\n");
    }

    return 0;
}
