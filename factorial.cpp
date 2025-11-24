#include <stdio.h>
#include <stdlib.h>

int contador(int n){
  if (n<10){
    //si solo hay digito digamos 9 entonces solo tenemos un dijito asi que no hace falta operar
    return 1;
    }
    else{
      //recordemos que esto es recursividad la funcion contador se llamara a si misma por ejemplo:
      //en el caso de numero=100 tendriamos contador(100/10)+1 es decir contador (10)+1 luego el contador (10) es 10/10 +1 es decir contador(10)=contador(1)+1
      //entonces tenemos que contador(10)=contador(1)+1 contador(100)=contador(10)+1 y contador(1)=1
      //el resultado seria contador(100)=1+1+1 siendo un 1 perteneciente a contador(10) otro a contador(100) y el ultimo a contador (1)
      return contador(n/10)+1;
      }
  }


int main(){
  int numero;
  do{
    //pedimos el numero al que queremos hallar los digitos
    printf("escribe un numero para hallar sus digitos\n");
    scanf("%i",&numero);
    }
    //siempre que no sea cero tendremos algun digito este sera el resultado de contador(numero) con esto llamamos a la funcion contador
    //enviando el dato numero qu es el numero que buscamos hallar los digitos
    while(numero<0);
      printf("el numero de digitos es: %i\n",contador(numero));

  }
//fijate que el numero que metas da igual por que lo que haces al final es convertir el numero que te quede en un 1
//por ejemplo 4234 pasaremos a 423 luego 42 y a 4 este ultimo sera 1 al ser menor a 10
