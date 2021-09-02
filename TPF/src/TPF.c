/*
 ============================================================================
 Name        : TPF.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int MatrizTablero();
int CerarTablero();
int moverJ1();
int moverPC();
int MovimientoValido();
int HizoCuadradito();
int ImprimirTablero();
int LlenarTablero();
char Nombre[50];


int main(void) {
	int M=0; int i; int j; int f; int c; int menu=0;
	do{
		printf("Bienveni3\nElija la opcion a realizar\n1.Jugar\n2.Instrucciones\n3.Salir\nSe recomienda leer las instrucciones antes de jugar.\n");
		scanf("%d", menu);
		if(menu==1){
			printf("Escribe la dimension de la matriz: \n");
			printf("%d", M);

		}
	}while(menu!=3);

	return EXIT_SUCCESS;
}
