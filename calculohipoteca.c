#include <stdio.h>

typedef struct cuota {
    int mes;
    int anno;
    float intereses;
} Cuota;

const float Euribor = 1.0;

Cuota tablaHipoteca[59] = {
    {3, 2020, 0.750}, {4, 2020, 0.750}, {5, 2020, 0.750},
    {6, 2020, 0.875}, {7, 2020, 0.875}, {8, 2020, 0.875},
    {9, 2020, 0.875}, {10, 2020, 0.875}, {11, 2020, 0.875},
    {12, 2020, 0.875}, {1, 2021, 0.500}, {2, 2021, 0.500},
    {3, 2021, 0.500}, {4, 2021, 0.500}, {5, 2021, 0.500},
    {6, 2021, 0.500}, {7, 2021, 0.500}, {8, 2021, 0.500},
    {9, 2021, 0.500}, {10, 2021, 0.500}, {11, 2021, 0.500},
    {12, 2021, 0.500}, {1, 2022, 0.500}, {2, 2022, 0.500},
    {3, 2022, 0.500}, {4, 2022, 0.500}, {5, 2022, 0.500},
    {6, 2022, 0.500}, {7, 2022, 1.250}, {8, 2022, 1.250},
    {9, 2022, 1.250}, {10, 2022, 1.250}, {11, 2022, 1.250},
    {12, 2022, 1.250}, {1, 2023, 3.857}, {2, 2023, 3.857},
    {3, 2023, 3.857}, {4, 2023, 3.857}, {5, 2023, 3.857},
    {6, 2023, 3.857}, {7, 2023, 4.857}, {8, 2023, 4.857},
    {11, 2023, 4.857}, {12, 2023, 4.857}, {1, 2024, 4.857},
    {2, 2024, 4.857}, {3, 2024, 5.000}, {4, 2024, 5.000},
    {5, 2024, 5.000}, {6, 2024, 5.000}, {7, 2024, 5.000},
    {10, 2024, 5.000}, {11, 2024, 4.625}, {12, 2024, 4.625},
    {2, 2025, 4.625}, {4, 2025, 4.625}, {5, 2025, 4.625},
    {7, 2025, 4.625}, {8, 2025, 4.500}
};

Cuota tablaEUROBOR[72] = {
    {1,  2020, -0.253+Euribor}, {2,  2020, -0.288+Euribor}, {3,  2020, -0.266+Euribor},
    {4,  2020, -0.108+Euribor}, {5,  2020, -0.081+Euribor}, {6,  2020, -0.147+Euribor},
    {7,  2020, -0.279+Euribor}, {8,  2020, -0.359+Euribor}, {9,  2020, -0.415+Euribor},
    {10, 2020, -0.466+Euribor}, {11, 2020, -0.481+Euribor}, {12, 2020, -0.497+Euribor},
    {1,  2021, -0.505+Euribor}, {2,  2021, -0.501+Euribor}, {3,  2021, -0.487+Euribor},
    {4,  2021, -0.484+Euribor}, {5,  2021, -0.481+Euribor}, {6,  2021, -0.484+Euribor},
    {7,  2021, -0.491+Euribor}, {8,  2021, -0.498+Euribor}, {9,  2021, -0.492+Euribor},
    {10, 2021, -0.477+Euribor}, {11, 2021, -0.487+Euribor}, {12, 2021, -0.502+Euribor},
    {1,  2022, -0.477+Euribor}, {2,  2022, -0.335+Euribor}, {3,  2022, -0.237+Euribor},
    {4,  2022,  0.013+Euribor}, {5,  2022,  0.287+Euribor}, {6,  2022,  0.852+Euribor},
    {7,  2022,  0.992+Euribor}, {8,  2022,  1.249+Euribor}, {9,  2022,  2.233+Euribor},
    {10, 2022,  2.629+Euribor}, {11, 2022,  2.828+Euribor}, {12, 2022,  3.018+Euribor},
    {1,  2023,  3.337+Euribor}, {2,  2023,  3.534+Euribor}, {3,  2023,  3.647+Euribor},
    {4,  2023,  3.757+Euribor}, {5,  2023,  3.862+Euribor}, {6,  2023,  4.007+Euribor},
    {7,  2023,  4.149+Euribor}, {8,  2023,  4.073+Euribor}, {9,  2023,  4.149+Euribor},
    {10, 2023,  4.160+Euribor}, {11, 2023,  4.022+Euribor}, {12, 2023,  3.679+Euribor},
    {1,  2024,  3.609+Euribor}, {2,  2024,  3.671+Euribor}, {3,  2024,  3.716+Euribor},
    {4,  2024,  3.702+Euribor}, {5,  2024,  3.680+Euribor}, {6,  2024,  3.650+Euribor},
    {7,  2024,  3.526+Euribor}, {8,  2024,  3.169+Euribor}, {9,  2024,  2.940+Euribor},
    {10, 2024,  2.686+Euribor}, {11, 2024,  2.506+Euribor}, {12, 2024,  2.433+Euribor},
    {1,  2025,  2.526+Euribor}, {2,  2025,  2.402+Euribor}, {3,  2025,  2.398+Euribor},
    {4,  2025,  2.143+Euribor}, {5,  2025,  2.081+Euribor}, {6,  2025,  2.081+Euribor},
    {7,  2025,  2.079+Euribor}, {8,  2025,  2.112+Euribor}, {9,  2025,  2.172+Euribor},
    {10, 2025,  2.185+Euribor}
};

// Función para buscar intereses por mes y año
void buscarIntereses(int mes, int anno, float pagoTotal) {
    int tamHip = 59;
    int tamEur = 72;
    int encontradoHip = 0;
    int encontradoEur = 0;

    for (int i = 0; i < tamHip; i++) {
        if (tablaHipoteca[i].mes == mes && tablaHipoteca[i].anno == anno) {
            float interesesHip = pagoTotal * (tablaHipoteca[i].intereses / 100.0);
            printf("Hipoteca: %.3f%% -> Intereses a pagar: %.2f de %.2f\n",
                   tablaHipoteca[i].intereses, interesesHip, pagoTotal);
            encontradoHip = 1;
            break;
        }
    }

    for (int j = 0; j < tamEur; j++) {
        if (tablaEUROBOR[j].mes == mes && tablaEUROBOR[j].anno == anno) {
            float interesesEur = pagoTotal * (tablaEUROBOR[j].intereses / 100.0);
            printf("Euribor: %.3f%% -> Intereses a pagar: %.2f de %.2f\n",
                   tablaEUROBOR[j].intereses, interesesEur, pagoTotal);
            encontradoEur = 1;
            break;
        }
    }

    if (!encontradoHip) printf("No se encontró la fecha en la tabla de hipoteca.\n");
    if (!encontradoEur) printf("No se encontró la fecha en la tabla de Euribor.\n");
}

// Función para mostrar meses donde hipoteca > Euribor
void mostrarHipotecaMayor() {
    int tamHip = 59;
    int tamEur = 72;

    printf("Meses donde la Hipoteca es mayor que el Euribor:\n");

    for (int i = 0; i < tamHip; i++) {
        for (int j = 0; j < tamEur; j++) {
            if (tablaHipoteca[i].mes == tablaEUROBOR[j].mes &&
                tablaHipoteca[i].anno == tablaEUROBOR[j].anno) {
                
                if (tablaHipoteca[i].intereses > tablaEUROBOR[j].intereses) {
                    printf("Mes: %d, Año: %d -> Hipoteca: %.3f, Euribor: %.3f\n",
                           tablaHipoteca[i].mes, tablaHipoteca[i].anno,
                           tablaHipoteca[i].intereses, tablaEUROBOR[j].intereses);
                }
            }
        }
    }
}

int main() {
    char opcion;

    do {
        printf("\n=== MENÚ PRINCIPAL ===\n");
        printf("1. Buscar intereses por mes, año y pago\n");
        printf("2. Mostrar meses donde Hipoteca > Euribor\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1': {
                int mes, anno;
                float pago;
                printf("Ingrese mes (1-12): ");
                scanf("%d", &mes);
                printf("Ingrese año: ");
                scanf("%d", &anno);
                printf("Ingrese pago: ");
                scanf("%f", &pago);
                buscarIntereses(mes, anno, pago);
                break;
            }
            case '2':
                mostrarHipotecaMayor();
                break;
            case '3':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida, intente de nuevo.\n");
        }
    } while (opcion != '3');

    return 0;
}
