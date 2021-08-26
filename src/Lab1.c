/*
 ============================================================================
 Name        : Lab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	int array[100];int array2[100];int i;int num;int n; int array1[100];int z;int j=0;int k;int aux=0;
	for(i=0;i<=100;i++){
		array[i]=0;
		array1[i]=0;
		array2[i]=0;
	}
	printf("Ingrese el numero de enteros a ingresar: ");
	scanf("%d", &n);
	printf("Ingrese el numero entero: ");
	for(i=0;i<n;i++){
		scanf("%d", &num);
		array[i]=abs(num);
	}
	for(i=0; i<=n; i++){
			int cont=0;
			num=array[i];
			array1[j]=num;
			j++;
			for (k=0;k<10;k++){
				if ( array1[k] == num ){
					cont++;
				}

		}
		if(cont==1){
			array2[z]=num;
			z++;
		    aux++;
		}
	}
	for(i=0;i<aux;i++){
		num=array2[i];
		printf("%d \t",num);
	}
	printf("Los valores absolutos encontrados son %d", aux);
	return EXIT_SUCCESS;
}
