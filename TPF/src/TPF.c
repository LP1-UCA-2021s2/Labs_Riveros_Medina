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
#include <string.h>

void imprimirTablero(int aux, int D, int Matriz_Tab[][D]);
void llenarTablero(int aux, int D, int Matriz_Tab[][D]);
int validarMovimiento(int aux, int D, int Matriz_Tab[][D]);

int main(void) {
	int aux;
	printf("Tamanho de la matriz: ");
	scanf("%d", &aux);
	int D=aux*2+1;
	int Matriz_Tab[D][D];
	llenarTablero(aux, D, Matriz_Tab);
	imprimirTablero(aux, D, Matriz_Tab);
	if(validarMovimiento(aux, D, Matriz_Tab)){
		imprimirTablero(aux, D, Matriz_Tab);
	}
}

void imprimirTablero(int aux, int D, int Matriz_Tab[][D]){
	int n=1;
	printf(" ");
	for(int l=0; l<=aux; l++){
		printf(" %d", n++);
	}
	printf("\n");
	n=1;
	for(int i=0; i<D; i++){
		if(i%2==0&&n<10){
			printf("%d ", n++);
		}else{
			if(i%2==0){
				printf("%d", n++);
			}else{
				printf(" ");
			}
		}
		for(int j=0; j<D; j++){
			printf("%c", Matriz_Tab[i][j]);
		}
		printf("\n");
	}
}

void llenarTablero(int aux, int D, int Matriz_Tab[][D]){
	int i, j;
		for(i=0; i<D; i++){
			for(j=0; j<D; j++){
				if(((i%2)==0)&&((j%2)==0)){
					Matriz_Tab[i][j]='+';
				}else{
					Matriz_Tab[i][j]=' ';
				}
			}
		}
}

int validarMovimiento(int aux,int D, int Matriz_Tab[][D]){
	int x, y, f, c, p, q;
	printf("Seleccione la ficha que desee unir...\n");
	printf("\tIntroduzca primero la fila luego un salto de linea y la columna\n");
	scanf("%d %d",&f,&c);
	printf("\tIntroduzca primero la fila luego un salto de linea y la columna donde desee mover\n");
	scanf("%d %d",&x,&y);
	if(f<=aux+1&&c<=aux+1&&x<=aux+1&&y<=aux+1&&f>0&&c>0&&x>0&&y>0){					///verifica q los valores esten en rango
		f=(f-1)*2;
		c=(c-1)*2;
		x=(x-1)*2;
		y=(y-1)*2;
		if(f==x){
			if((c==y-2)||(c==y+2)){
					p=c<y?c:y;														///p guarda el valor menor
					if(Matriz_Tab[f][p+1]==' '){
						Matriz_Tab[f][p+1]='-';

						if(Matriz_Tab[f+1][p]=='|' && Matriz_Tab[f+1][p+2]=='|' && Matriz_Tab[f+2][p+1]=='-'){	///el encerrado q todavia no esta
							if(Matriz_Tab[f+1][c+1]==' '){
								Matriz_Tab[f+1][p+1]='A';
								return 1;
							}
						}

						return 1;
					}else{
						return 0;
					}

			}
		}else{
			if(c==y){
				if((f==x-2)||(f==x+2)){
					q=f<x?f:x;														///q guarda el valor menor
					if(Matriz_Tab[q+1][c]==' '){
						Matriz_Tab[q+1][c]='|';
						return 1;
					}else{
						return 0;
					}

				}
			}
		}
	}return 0;
}

