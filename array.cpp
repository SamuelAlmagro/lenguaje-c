#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// declaracion del array con vectores de tamaño 3 (0, 1, 2)
typedef int vectores[3];

// ajustar el array a tener dos vectores a=(0, 1, 2) b=(0, 1, 2)
vectores a, b;

// escribir los valores del vector a
void sacavectorA(vectores a) {
    for (int index = 0; index < 3; index++) {
        printf("Escribe el valor de la componente %i de a:\n ", index);
        scanf("%i", &a[index]);
    }
}

// Escribir los valores del vector b
void sacavectorB(vectores b) {
    for (int index = 0; index < 3; index++) {
        printf("Escribe el valor de la componente %i de b:\n ", index);
        scanf("%i", &b[index]);
    }
}

// Calcular la distancia entre a y b
float distancia(vectores a, vectores b) {
    float suma = 0;
    for (int calc = 0; calc < 3; calc++) {
        suma = suma + powf(a[calc] - b[calc], 2);
    }
    return sqrtf(suma);
}

int main() {
    float dist;
    sacavectorA(a);
    sacavectorB(b);
    dist = distancia(a, b);

    printf("La distancia entre los vectores es: %f\n", dist);

    return 0;
}
