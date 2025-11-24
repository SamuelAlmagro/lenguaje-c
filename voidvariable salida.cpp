#include<stdio.h>
//el int resul es una variable de salida como vemos en int main a datos y datop le asignamos valores
//estos pasan de int main a void donde los calculamos y fijamos el valor a la variable resul ojo con
//un & siempre y lo devolvemos a int main donde asume que suma=resul
void parametro(int dato1,int dato2,int &resul){
    resul=dato1+dato2;
  }
  int main(){
    int suma;
    int datos=12;
    int datop=10;
    parametro(datos,datop,suma);
    printf("%d\n",suma);
    }
