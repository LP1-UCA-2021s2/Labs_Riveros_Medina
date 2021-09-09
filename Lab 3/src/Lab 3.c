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
#include <string.h>

int esPrimo(int num);
void convierte(int arrayaux[], char array[]);

int main(void) {
	int arrayaux[50];
	char array[50];
	int i; int num; int contp=0;
	printf("Escribe un array de entros: ");
	scanf("%s", array);
	convierte(arrayaux, array);
	int j=strlen(array)-1;													/// apunta al ultimo numero del array
	int lon=(j/2);
	for(i=0; i<lon+1; i++){													/// convierte los numeros y guarda en num
		if(i!=j && i<j){
			num=arrayaux[i]*10;
			num=num+arrayaux[j];
			j--;
		}else{
			num=arrayaux[i];
		}
		if(esPrimo(num)){													/// compara si es primo en la funcion y suma al contador
			printf("%d Es primo.\n", num);
			contp++;
		} else {
		    printf("%d No es primo.\n", num);
		}
	}
	if((lon+1)==contp){														/// comprueba que sean primos todos los numeros
		printf("El array es especial.\n");
	}else{
		printf("El array no es especial.\n");
	}
}

int esPrimo(int num) {
	if (num == 0 || num == 1) return 0;
	if (num == 4) return 0;
	for (int x = 2; x < num / 2; x++) {
		if (num % x == 0) return 0;
	}
	return 1;
}

void convierte(int arrayaux[], char array[]){								/// convierte el array de char a un array de int
	int i;
	for(i=0; i<50; i++){
		arrayaux[i]=array[i]-48;
	}
}
