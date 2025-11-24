#include <stdio.h>
#include <stdlib.h>
//este es un ejercicio en el cual haremos la operacion factiorial
//aplicando la recursibidad y subprogramacion
//podemos definir el factioal de un numero como n!=n(n-1)

int factorial(int n){
  //tanto el factorial de 0 como el de 1 es igual a 1
  if(n==0 || n==1){
    return 1;}
    else{
      //aqui la funcion se llamara a si misma multiples veces digamos que numero=10 seria 9*factorial(9)
      //para hacer el factorial(9) vuelve ha ejecutar la funcion factorial en la cual tendremos 8*factorial(8)
      //asi hasta que llegemos a factorial(1) donde el if nos retorna un 1 tras esto las demas llamadas se autocompletaran
      //gracias a que con el factoral(1) podemos hacer factoral(2) ya que este es 2*factorial(2-1)
      return n*factorial(n-1);}
  }




int main(){
  int numero;
  printf("dime el numero al que quiere hacer la operacion factorial\n");
  scanf("%i",&numero);
  if(numero<0){
    printf("no existen factoriales negativos\n");}
    else{
  printf("el factorial de %i es:%i\n",numero,factorial(numero));}
  }



