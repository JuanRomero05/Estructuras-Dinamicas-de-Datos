//URU - Juan Romero - C.I: 29.955.629 - Estructuras dinámicas de datos

/*

Problema libre: Hacer un programa en C que contenga arrays dinamicos el cual, va a pedir la cantidad
de familiares, digitar las edades de estos y por último muestre la media de edades digitadas.

*/

//Librerias
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int main(){

    //Variables
    int cantidadFamiliares, contador = 0;
    int *arrayDinamico;
    float media = 0;

    //Pedir la cantidad de familiares
    printf("Introduzca la cantidad de familiares: ");
    scanf("%d", &cantidadFamiliares);

    //Reserva de memoria para la cantidad X de familiares que contendrá el array
    arrayDinamico = (int *) malloc (cantidadFamiliares* sizeof(int));

    //Bucle for para llenar el array
    for(int i= 0 ; i < cantidadFamiliares; i++){

        printf("\nIntroduzca la edad del familiar #%d: ", i+1 );
        scanf("%d", &arrayDinamico[i]);
        media += arrayDinamico[i]; //Esta formula sumará la media inicializada en 0 más las edades que se digiten en el array

    }

    media /= cantidadFamiliares; //Formula para calcular la media de edades


    //Bucle for necesario para recorrer el array
    for(int i= 0 ; i < cantidadFamiliares; i++ ){

        if(arrayDinamico[i] > media){ //Condicional if para verificar si las edades guardadas son mayores que la media ya calculada
            contador++;               //Y la variable contador inicializada en 0 se irá aumentando para saber cuantos familiares
        }                             // están por encima de la media de edades digitadas.
    }

    printf("\nLa media de edad de los familiares es de: %.2f\n", media);
    printf("\nHay %d familiar/es sobre la media de edades\n", contador);

    free(arrayDinamico); //Por último se liberará la memoria reservada.

    getch();
    return 0 ;
}
