#include<stdio.h>
//Ejemplo de funcion con parametros
//importante los int de int resta tienen que ser distintos de los de int main
int resta(int datop,int datos){
return(datop-datos);
}
//imprescindible que para la funcion con parametros pongas los valores(valor1,valor2)
//para que estos se manden a int resta



int main(){
  int dato1,dato2;
  dato1=11;
  dato2=9;
//imprescindible que para la funcion con parametros pongas los valores(valor1,valor2)
//para que estos se manden a int resta
printf ("%d\n",resta(dato1,dato2));
}
