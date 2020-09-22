/**
* Título del Programa: deditos.c
* Descripción del Programa: Juego de los deditos chinos
*
* @uthor: Jaime Berruete Díaz
* fecha: 22/09/2020
* versión: V1.1 - recopilación de nombres de jugadores
*/

/* Directiva para el preprocesador */
#include<stdio.h>
#define LONGITUD_NOMBRE 10
void pedirNombres();
int limpiarBuffer();

char Nombre1[LONGITUD_NOMBRE];
char Nombre2[LONGITUD_NOMBRE];

int main(){
	printf("\nBienvenidos al juego de los deditos.\n");
	pedirNombres();
}

/* Funciones y procedimientos solicitados para esta entrega */
int limpiarBuffer(){
	while(getchar() != '\n')
	return 1;
}

void pedirNombres(){
	printf("\nJugador1, introduce tu nombre (maximo 10 letras): ");
	scanf("%s",Nombre1);
	limpiarBuffer();
	printf("\nJugador2, introduce tu nombre (maximo 10 letras): ");
	scanf("%s",Nombre2);
	limpiarBuffer();
}

