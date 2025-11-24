#include <stdio.h>

void puebaSinAmpersan(int numero){
const int suma=3;
printf("la funcion recibe= %i\n",numero);
printf("el numero pasado es = %i\n",numero);
numero=numero+suma;
printf("despues de sumar 3 es = %i\n",numero);
}

void puebaConAmpersan(int &numero){
const int suma=3;
printf("la funcion recibe= %i\n",numero);
printf("el numero pasado es = %i\n",numero);
numero=numero+suma;
printf("despues de sumar 3 es = %i\n",numero);
}

int main(){
  int numero;
  int numeroCopia;
  printf("inserta int\n");
  scanf("%i",&numero);
  numeroCopia=numero;

  printf("===Numero con & en la funcion(referencia)====\n");
  puebaConAmpersan(numero);
  printf("el original es = %i\n",numeroCopia);
  printf("el valor (Numero) que tenemos es = %i\n",numero);
  numero=numeroCopia;

  printf("\n");

  printf("===Numero sin & en la funcion (copia)====\n");
  puebaSinAmpersan(numero);
  printf("el original es = %i\n",numeroCopia);
  printf("el valor (Numero) que tenemos es = %i\n",numero);
  numero=numeroCopia;
  }
