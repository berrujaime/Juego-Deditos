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
#include <string.h>

/* Constantes define */
#define LONGITUD_NOMBRE 10

/* Prototipos de las funciones utilizadas */
void pedirNombres();
/**
* Descripcion: pide y guarda los nombres de los jugdores
* @param no recibe ningún parámetro
* @return no devuelve ningún parámetro
**/

void instrucciones();
/**
* Descripcion: muestra las instrucciones
* @param no recibe ningún parámetro
* @return nada
**/

int limpiarBuffer();
/**
* Descripcion: limpia el buffer de datos para que la siguiente inserción de datos no tenga errores
* @param no recibe ningún parámetro
* @return devuelve 1 en cada ejecución que el buffer no esté limpio
**/

void jugar();
/**
* Descripcion: desarrollo del juego
* @param no recibe ningún parámetro
* @return devuelve el jugador ganador
**/

/* Variables globales */
char Nombre1[LONGITUD_NOMBRE];
char Nombre2[LONGITUD_NOMBRE];


/* Definición de la función principal */
int main(){
	char respuesta;
	int valido=0;
	
	printf("\nBienvenidos al juego de los deditos.\n");
	pedirNombres();
	
	// Preguntar al jugador si sabe o no jugar. Si sabe, jugamos, si no le explicamos y jugamos.
	do{
		printf("\nSabes jugar al juego? y/n: ");
		respuesta=getchar();
		limpiarBuffer();
		
		if(respuesta == 'n'){
			valido=1;
			instrucciones();
			jugar();
		}
		else
		if(respuesta == 'y'){
			valido=1;
			jugar();
		}
		else
		printf("\nIntroduzca una respuesta valida.");
	}while(valido==0);
}

/* Funciones y procedimientos */
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

void instrucciones(){
	printf("\n ____________________________________________________________________________________________");
	printf("\n|                                                                                            |");
	printf("\n|INSTRUCCIONES                                                                               |");
	printf("\n|____________________________________________________________________________________________|");
	printf("\nEl juego comienza con los dos jugadores teniendo 1 dedo en cada mano.");
	printf("\nEl objetivo consiste en eliminar las dos manos del enemigo.");
	printf("\nPara eliminar la mano de un enemigo hay que hacer que sume 5 o más dedos.");
	printf("\nPara lograr este objetivo tienes 2 opciones: ");
	printf("\nSumar los dedos de una de tus manos a una del enemigo.");
	printf("\nPor ejemplo: si tienes en una de tus manos un 2 y el enemigo tiene en la mano a la que quieres sumar un 2 el enemigo se quedaria con 4.");
	printf("\nSeparar los dedos que tengas en total en tus dos manos.");
	printf("\nPor ejemplo: Si tienes una mano muerta y en tu otra mano tienes 3, puedes gastar el turno para dejar las manos en 2 y 1 y asi revivir una de tus manos.");
	printf("\nNo se puede pasar turno o realizar algun cambio en tus manos que las deje como estaban.");
	printf("\nCada movimiento de estos gasta 1 turno\n");
	printf("\nPulse enter cuando haya leído las instrucciones\n");
	limpiarBuffer();
}

void jugar(){
	int variar_jugador=0, a=1, b=1, c=1, d=1, jugada, dedos_antes, dedos_ahora, num_jugador, correcto;
	char jugador[LONGITUD_NOMBRE], mano_propia, mano_enemiga;
	
	printf("\nComienza el juego ^^");
	printf("\nComienza %s", Nombre1);
	
	do{
		if(variar_jugador%2==0){
			strcpy(jugador,Nombre1);
			num_jugador=1;
		}
		else{
			strcpy(jugador,Nombre2);
			num_jugador=2;
		}
		
		printf("\nManos %s: [ %i | %i ]", Nombre1,a,b);
		printf("\nManos %s: [ %i | %i ]", Nombre2,c,d);
		
		do{
		printf("\nQue jugada quieres hacer? Pulsa 1 para cambiar dedos entre las manos o 2 si deseas sumar dedos al enemigo: ");
		scanf("%i", &jugada);
			limpiarBuffer();
			
			if(jugada==1){
				if(num_jugador==1){
					dedos_antes=a+b;
				}
				else{
					dedos_antes=a+b;
				}
				printf("\nIntroduzca nueva configuración:");
				do{
					if(num_jugador==1){
						printf("Dedos mano izquierda: ");
						scanf("%i",&a);
							limpiarBuffer();
						printf("Dedos mano derecha: ");
						scanf("%i",&b);
							limpiarBuffer();
						dedos_ahora=a+b;
					}
					else{
						printf("Dedos mano izquierda: ");
						scanf("%i",&c);
							limpiarBuffer();
						printf("Dedos mano derecha: ");
						scanf("%i",&d);
							limpiarBuffer();
						dedos_ahora=c+d;
					}
				}while(dedos_antes != dedos_ahora);
			}
			else{
				if(jugada!=2){
					printf("Ha introducido una jugada incorrecta");
				}
				else{
					do{
						printf("Pulse i si deseas sumar los dedos de tu mano izquierda o d si deseas sumar los de tu mano derecha: ");
						mano_propia=getchar();
							limpiarBuffer();
						if(mano_propia=='d')
							correcto=1;
						else
							if(mano_propia=='i')
								correcto=1;
							else
								correcto=0;		
					}while(correcto!=1);
					
					
					do{
						printf("A que mano del enemigo le sumamos (i para izquierda o d para derecha)?: ");
						mano_enemiga=getchar();
							limpiarBuffer();
						if(mano_enemiga=='d')
							correcto=1;
						else
							if(mano_enemiga=='i')
								correcto=1;
							else
								correcto=0;		
					}while(correcto!=1);
				
				if(mano_propia=='i' && mano_enemiga=='i')
					c=a+c;
				if(mano_propia=='i' && mano_enemiga=='d')
					d=a+d;
				if(mano_propia=='d' && mano_enemiga=='i')
					c=b+c;
				if(mano_propia=='d' && mano_enemiga=='d')
					d=b+d;
				}
			}	
		}while(jugada!=1 && jugada!=2);
		
		variar_jugador++;
		
	}while(!((a>4 && b>4) || (c>4 && d>4))); //esta es la condicion de parada, si no funciona así poner un if delante con una variable auxiliar
	
}
