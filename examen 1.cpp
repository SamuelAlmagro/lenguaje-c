#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct tNodeAlbum{
int ID;
char Name[100];
char Artist[100];
char Song[20][100];
int Downloads;
int Reproductions;
tNodeAlbum *Next
}

typedef tNodeAlbum*tPointAlbum;
tPointAlbum Edit,Aux1,Aux2;

typedef int TopArtist[100];
Topartist A;

typedef enum NameTopArtist[100]
NameTopArtist B;

void ReproducirCancion(){
char cancion;
Int Compara;
Int ID;
printf("¿Cancion?")
scanf(" %s",cancion);

while(Finaliza!=0){

//primer Album

  for(int i=0;i<=20;i++){
    Compara=CompararCadenas(Edit->Song[i],cancion);
    if(compara==1){
    Edit->Reproductions=Edit->Reproductions+1
    Edit=Edit->Next;
    }


for(int=0;i<=99){
  for(int i=0;i<=20;i++){
    Compara=CompararCadenas(Edit->Song[i],cancion);
    if(compara==1){
    Edit->Reproductions=Edit->Reproductions+1
    }
  }
      Edit=Edit->Next;
}
}
}

void Top(){
int Id;
char Artist;
Int Suma;

for(int i=0; i<=100;i++){
  Artist=Edit->Artist;
  Id=Edit->Id
  while(Contador!=100){
    if(ComparaCadenas(Edit->Artist,Artist)==0){
    Suma=Edit->Reproductions+Suma;
    Contador++
    }
    else{
    if(ComparaCadenas(Edit->Artist,Artist)==0){
    Edit=Edit->Next;
    Contador++
    }
  A[i]=Suma
  B[i]=Edit->Artist;
  Edit=Edit->Next;
  Suma=0
  }
  }
}
//aqui Faltaria un codigo para comparar en el array los 10 que mas se han reproduciodo


}

void Numdescargas(){
int Album;
printf("Cual Album quieres saber las descargas");
scanf(" %s",Album);
while(Album!=Edit->Album){
  Edit=Edit->Next;
}
Printf("Descargas: %i",Edit->Downloads);
}

int main(){

//primer Nodo
Edit = new tNodeAlbum;
printf("Nombre Album");
scanf(" %s"Edit->Name);
//asi con todos los datos del album
Edit=Aux2;
Edit->Next=NULL;

for(i=0 ; i<=99;i++){
Aux1 = new tNodeAlbum;
printf("Nombre Album");
scanf(" %s"Aux1->Name);
//asi con todos los datos del album hasta next
Aux1->Next=Edit;
Aux1=Edit;
}
//cierra el circulo
Aux1->Next=Aux2;


//llamamos a las funciones
void ReproducirCancion()
void Numdescargas()
void Top()

}
