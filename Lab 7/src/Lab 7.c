/*
 ============================================================================
 Name        : Lab.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *a;
	FILE *b;
	int fila, columna, turno;
	char Nombre1[20];
	char Nombre2[20];
	printf("Ingresa el nombre del Jugador 1(PC Local)\n");
	scanf("%s", Nombre1);
	printf("Ingresa el nombre del Jugador 2(PC Oponente)\n");
	scanf("%s", Nombre2);
	printf("Elegir quien comineza:\n1. PC Local\n2. PC Oponente\n");
	scanf("%d", &turno);
	if(turno==1){
		for(int i=1; i<=4; i++){							//hago que se repita 4 veces y no sabia si era random o no las coordenadas
			if(turno==1){									//rivales asi que hice que te pida
				a=fopen(Nombre1,"w");
				if(a==NULL){
					printf("El archivo no pudo ser creado");
				}
				printf("J1 Ingrese las coordenadas A(Fila Columna): \n");
				scanf("%d %d", &fila, &columna);
				putw(fila,a);
				putw(columna, a);
				printf("J1 Ingrese las coordenadas B(Fila Columna): \n");
				scanf("%d %d", &fila, &columna);
				putw(fila,a);
				putw(columna, a);
				fclose(a);
				turno=2;
			}else{
				a=fopen(Nombre1,"r");
				if(a==NULL){
					printf("No se pudo leer\n");
				}else{
					printf("J1 unio de ");
					printf("(%d ", getw(a));
					printf("%d)", getw(a));
					printf(" a ");
					printf("(%d ", getw(a));
					printf("%d)\n", getw(a));
					fclose(a);
					remove(Nombre1);
					b=fopen(Nombre2,"w");
					if(b==NULL){
						printf("El archivo no pudo ser creado");
					}
					printf("J2 Ingrese las coordenadas A(Fila Columna): \n");
					scanf("%d %d", &fila, &columna);
					putw(fila,b);
					putw(columna, b);
					printf("J2 Ingrese las coordenadas B(Fila Columna): \n");
					scanf("%d %d", &fila, &columna);
					putw(fila,b);
					putw(columna, b);
					fclose(b);
					b=fopen(Nombre2,"r");
					if(b==NULL){
						printf("No se puede abrir\n");
					}
					printf("J2 unio de ");
					printf("(%d ", getw(b));
					printf("%d)", getw(b));
					printf(" a ");
					printf("(%d ", getw(b));
					printf("%d)\n", getw(b));
					fclose(b);
					remove(Nombre2);
					turno=1;
				}
			}
		}
	}else{
		for(int i=1; i<=4; i++){
			if(turno==2){
				b=fopen(Nombre2,"w");
				if(b==NULL){
					printf("El archivo no pudo ser creado");
				}
				printf("J2 Ingrese las coordenadas A(Fila Columna): \n");
				scanf("%d %d", &fila, &columna);
				putw(fila,b);
				putw(columna, b);
				printf("J2 Ingrese las coordenadas B(Fila Columna): \n");
				scanf("%d %d", &fila, &columna);
				putw(fila,b);
				putw(columna, b);
				fclose(b);
				turno=1;
			}else{
				b=fopen(Nombre2,"r");
				if(b==NULL){
					printf("No se pudo leer\n");
				}else{
					printf("J2 unio de ");
					printf("(%d ", getw(b));
					printf("%d)", getw(b));
					printf(" a ");
					printf("(%d ", getw(b));
					printf("%d)\n", getw(b));
					fclose(b);
					remove(Nombre2);
					a=fopen(Nombre1,"w");
					if(a==NULL){
						printf("El archivo no pudo ser creado");
					}
					printf("J1 Ingrese las coordenadas A(Fila Columna): \n");
					scanf("%d %d", &fila, &columna);
					putw(fila,a);
					putw(columna, a);
					printf("J1 Ingrese las coordenadas B(Fila Columna): \n");
					scanf("%d %d", &fila, &columna);
					putw(fila,a);
					putw(columna, a);
					fclose(a);
					a=fopen(Nombre1,"r");
					if(a==NULL){
						printf("No se puede abrir\n");
					}
					printf("J1 unio de ");
					printf("(%d ", getw(a));
					printf("%d)", getw(a));
					printf(" a ");
					printf("(%d ", getw(a));
					printf("%d)\n", getw(a));
					fclose(b);
					remove(Nombre1);
					turno=2;
				}
			}
		}
	}
}

