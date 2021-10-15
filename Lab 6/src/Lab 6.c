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
#include <ctype.h>

int esPalindromo(char* cad)
{
    char *final, *aux;

    final = cad;

    while (*final != '\0') {
        ++final;
    }
    final=final-1;

    for (aux = cad; final >= aux;) {
        if (*final == *aux) {
            --final;
            aux++;
        }
        else
            break;
    }

    if (aux > final)
        return 1;
    else
        return 0;
}

void haceminusculas(char cadena[1000])
{
	int i;
	int lon=strlen(cadena);

	for(i=0;i<lon;i++){
		cadena[i]=tolower(cadena[i]);
	}

}

void sacaespaciosylimpia(char cadena[1000]){
	int lon=strlen(cadena)-1;
	int a=0, k=0;
	while(cadena[a]!='\n'){
		if(cadena[a]==' '){
			for(k=a;k<lon;k++){
				cadena[k]=cadena[k+1];
			}
			lon--;
		}
		a++;
	}
	cadena[lon]='\0';

}


int main()
{
    char cadena[1000];
    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, 1000, stdin);
    printf("%s", cadena);

    haceminusculas(cadena);

    sacaespaciosylimpia(cadena);

    if(esPalindromo(cadena)){
    	printf("Es Palindromo");
    }else{
    	printf("No es Palindromo");
    }

    return 0;
}


