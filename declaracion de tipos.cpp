#include <stdio.h>
#include <stdlib.h>

void declaraciondetipos(){
//declaracion de tipos
//primero que nada se puede poner el el int main, en un subprograma/funcion o en global
//la declaracion de tipos asigna un alias a los tipos de datos por ejemplo los datos tipo int se pueden
//se les puede llamar dias. de esta forma si tengo que declarar un dato tipo int dentro de mi programa
//no tendria que poner int lunes; si no que dias lunes;
typedef int dias;
dias lunes;
lunes=1;
printf("lunes es:%i\n",lunes);
  }



void tipoenumerado() {
  //tipo enumerado
  //hace lo mismo que una declaracion de tipos pero esta vez puede expecificar que datos puede tener dentro
  //es decir en lugar de ser un int que tiene numeros enteros sera un nuevo tipo de dato que tiene una lista de variables
  //por ejemplo coche=ford,mercedes... ojo no es un string es decir ford no es igual a "ford" y hay que tener en cuenta que
  //siempre se empieza a contar desde el 0 es decir coche=(0=ford,1=mercedes...)
  typedef enum diasem {Lunes, Martes, Miercoles, Jueves, Viernes};
  //diasem diaSeleccionado; es la declaracion de el dato es como int numero;
    diasem diaSeleccionado;

    printf("Selecciona un día de la semana:\n");
    //recuerda que la lista va de (0,1,2,3...) en el scan tienes que usar numeros para sacar datos de la lista pero una vez sacados
    //ya sale como lunes o martes es decir si selecionas 3 en la memoria se guarda jueves y no 3
    printf("Lunes=0, Martes=1, Miercoles=2, Jueves=3, Viernes=4\n");
    scanf("%d", &diaSeleccionado);
    //el hecho de haver pasado de poner numero a tener lunes en la memoria no hace que puedas imprimir lunes si no que lunes ahora equivale
    //a lo que antes era un 1 esto afecta cuando hacemos el switsch por ejemplo que lo que miramos en los case son los dias (Lunes, Martes...)

    switch (diaSeleccionado) {
        case Lunes:
            printf("Es lunes. ¡Ánimo!\n");
            break;
        case Martes:
            printf("Martes, sigue adelante.\n");
            break;
        case Miercoles:
            printf("Mitad de semana, ya casi.\n");
            break;
        case Jueves:
            printf("Ya casi.\n");
            break;
        case Viernes:
            printf("¡Último día!\n");
            break;
        default:
            printf("Día no válido.\n");
    }


  }




int main(){
  declaraciondetipos();
  tipoenumerado();
  }
