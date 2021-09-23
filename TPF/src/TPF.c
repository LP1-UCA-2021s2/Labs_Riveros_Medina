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
void MovimientoJ(int aux, int D, int Matriz_Tab[][D]);
void MovimientoC(int aux, int D, int Matriz_Tab[][D]);
int scoreJ=0,scoreC=0;
int aux35;

int main(void) {
	int aux1=0; int menu; int a; int b;
	while(aux1!=1){
		printf("\n***Bienvenido al Juego dots and boxes***\n\n");
		printf("\tMenu\n1. Jugar\n2. Reglas\n3. Controles\n4. Creditos\n5. Salir\n");
		scanf("%d", &menu);
		while(getchar()!='\n');
		if(menu==2){
			printf("\nEn cada turno, el jugador puede conectar dos puntos adyacentes no conectados con una única raya (vertical u horizontal). \n"
					"Cada raya dibujada corresponde a una pared de un cuadrado, cuando uno de los jugadores logra conectar la cuarta pared de un cuadrado, \n"
					"se dice que el jugador ha ganado dicho cuadrado y éste se vuelve del color del jugador. Cuando un jugador completa un cuadrado tras dibujar una raya, \n"
					"sumará 10 puntos y deberá jugar de nuevo. El juego termina cuando no hay más puntos para conectar. \n"
					"En ese caso, el vencedor será el jugador que haya logrado una mayor puntuación. Es posible que se produzcan empates\n\nPresione Enter para volver.\n");
			char c;
			while ((c = getchar()) != '\n' && c != EOF) { };
		}else{
			if(menu==3){
				printf("Controles\nLos puntos se unen especificando el punto A que desea unir, ingresar por teclado primero la fila, un salto de linea y luego la columna. \n"
						"Con el punto B, ingresar por teclado primero la fila, un salto de linea y luego la columna. \n\nPresione Enter para volver.\n");
				char c;
				while ((c = getchar()) != '\n' && c != EOF) { };
			}else{
				if(menu==5){
					printf("Nos vemos c:\n");
						aux1=1;
				}else{
					if(menu==4){
						printf("Los integrantes en la creacion de este codigo son\nIvan Riveros\nMiguel Medina\n\nPresione Enter para volver.\n");
						char c;
						while ((c = getchar()) != '\n' && c != EOF) { };
					}else{
						if((menu!=1)&&(menu!=2)&&(menu!=3)&&(menu!=4)&&(menu!=5)){
							printf("Elija una opcion correcta entre el numero 1 al 5.\n");
						}else{
							if(menu==1){
								int band;
								printf("\nElija quien empieza\n1.Jugador\n2.Computadora\n3.Random\n");
								scanf("%d", &band);
								while(getchar()!='\n');
								if(band==1){
									int ale;
									printf("\n*Empieza el Jugador*\n");
									printf("\nTamanho de matriz random\n1.Si\n2.No\n");
									scanf("%d", &ale);
									while(getchar()!='\n');
									if(ale==1){
										int aux;
										aux=rand()%12+3;
										int D=aux*2-1;
										int Matriz_Tab[D][D];
										llenarTablero(aux, D, Matriz_Tab);
										aux35=0;
										do{
											imprimirTablero(aux, D, Matriz_Tab);
											MovimientoJ(aux, D, Matriz_Tab);
											a=scoreC+scoreJ;
											b=(aux-1)*(aux-1);
											if(a==b){
												aux35++;
												break;
											}
											MovimientoC(aux, D, Matriz_Tab);
											a=scoreC+scoreJ;
											b=(aux-1)*(aux-1);
											if(a==b){
												aux35++;
											}
											printf("\nEl puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
										}while(aux35==0);
										imprimirTablero(aux, D, Matriz_Tab);
										if(scoreJ>scoreC){
											printf("\n**Gano el jugador con %d puntos, felicidades**\n\n", scoreJ*10);
										}else{
											if(scoreJ==scoreC){
												printf("\n*Empataron, ambos con %d puntos*\n\n", scoreC*10);
											}else{
												printf("\n*Gano la computadora con %d puntos*\n\n", scoreC*10);
											}
										}
										scoreJ=0,scoreC=0;
										char c;
										while ((c = getchar()) != '\n' && c != EOF) { };
									}else{
										int aux;
										printf("\nTamanho de la matriz: ");
										scanf("%d", &aux);
										while(aux<3||aux>15){
											while((getchar()!='\n'))
											continue;
											printf("\nTamanho de la matriz incorrecto ingrese de new: ");
											scanf("%d", &aux);
										}
										int D=aux*2-1;
										int Matriz_Tab[D][D];
										llenarTablero(aux, D, Matriz_Tab);
										aux35=0;
										do{
											imprimirTablero(aux, D, Matriz_Tab);
											MovimientoJ(aux, D, Matriz_Tab);
											a=scoreC+scoreJ;
											b=(aux-1)*(aux-1);
											if(a==b){
												aux35++;
												break;
											}
											MovimientoC(aux, D, Matriz_Tab);
											a=scoreC+scoreJ;
											b=(aux-1)*(aux-1);
											if(a==b){
												aux35++;
											}
											printf("\nEl puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
										}while(aux35==0);
										imprimirTablero(aux, D, Matriz_Tab);
										if(scoreJ>scoreC){
											printf("\n**Gano el jugador con %d puntos, felicidades**\n\n", scoreJ*10);
										}else{
											if(scoreJ==scoreC){
												printf("\n*Empataron, ambos con %d puntos*\n\n", scoreC*10);
											}else{
												printf("\n*Gano la computadora con %d puntos*\n\n", scoreC*10);
											}
										}
										scoreJ=0,scoreC=0;
										char c;
										while ((c = getchar()) != '\n' && c != EOF) { };
									}
								}else{
									if(band==2){
										int ale;
										printf("\n*Empieza Computadora*\n");
										printf("\nTamanho de matriz random\n1.Si\n2.No\n");
										scanf("%d", &ale);
										while(getchar()!='\n');
										if(ale==1){
											int aux;
											aux=rand()%12+3;
											int D=aux*2-1;
											int Matriz_Tab[D][D];
											llenarTablero(aux, D, Matriz_Tab);
											aux35=0;
											do{
												MovimientoC(aux, D, Matriz_Tab);
												imprimirTablero(aux, D, Matriz_Tab);
												a=scoreC+scoreJ;
												b=(aux-1)*(aux-1);
												if(a==b){
													aux35++;
													break;
												}
												MovimientoJ(aux, D, Matriz_Tab);
												a=scoreC+scoreJ;
												b=(aux-1)*(aux-1);
												if(a==b){
													aux35++;
												}
												printf("\nEl puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
											}while(aux35==0);
											imprimirTablero(aux, D, Matriz_Tab);
											if(scoreJ>scoreC){
												printf("\n**Gano el jugador con %d puntos, felicidades**\n\n", scoreJ*10);
											}else{
												if(scoreJ==scoreC){
													printf("\n*Empataron, ambos con %d puntos*\n\n", scoreC*10);
												}else{
													printf("\n*Gano la computadora con %d puntos*\n\n", scoreC*10);
												}
											}
											scoreJ=0,scoreC=0;
											char c;
											while ((c = getchar()) != '\n' && c != EOF) { };
										}else{
											int aux;
											printf("\nTamanho de la matriz: ");
											scanf("%d", &aux);
											while(aux<3||aux>15){
												while((getchar()!='\n'))
													continue;
												printf("\nTamanho de la matriz incorrecto ingrese de new: ");
												scanf("%d", &aux);
											}
											int D=aux*2-1;
											int Matriz_Tab[D][D];
											llenarTablero(aux, D, Matriz_Tab);
											aux35=0;
											do{
												MovimientoC(aux, D, Matriz_Tab);
												imprimirTablero(aux, D, Matriz_Tab);
												a=scoreC+scoreJ;
												b=(aux-1)*(aux-1);
												if(a==b){
													aux35++;
													break;
												}
												MovimientoJ(aux, D, Matriz_Tab);
												a=scoreC+scoreJ;
												b=(aux-1)*(aux-1);
												if(a==b){
													aux35++;
												}
												printf("\nEl puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
											}while(aux35==0);
											imprimirTablero(aux, D, Matriz_Tab);
											if(scoreJ>scoreC){
												printf("\n**Gano el jugador con %d puntos, felicidades**\n\n", scoreJ*10);
											}else{
												if(scoreJ==scoreC){
													printf("\n*Empataron, ambos con %d puntos*\n\n", scoreC*10);
												}else{
													printf("\n*Gano la computadora con %d puntos*\n\n", scoreC*10);
												}
											}
											scoreJ=0,scoreC=0;
											char c;
											while ((c = getchar()) != '\n' && c != EOF) { };
										}
									}else{
										if(band==3){
											int ranT;
											ranT=rand()%2;
											if(ranT==0){
												int ale;
												printf("\n*Empieza Computadora*\n");
												printf("\nTamanho de matriz random\n1.Si\n2.No\n");
												scanf("%d", &ale);
												while(getchar()!='\n');
												if(ale==1){
													int aux;
													aux=rand()%12+3;
													int D=aux*2-1;
													int Matriz_Tab[D][D];
													llenarTablero(aux, D, Matriz_Tab);
													aux35=0;
													do{
														MovimientoC(aux, D, Matriz_Tab);
														imprimirTablero(aux, D, Matriz_Tab);
														a=scoreC+scoreJ;
														b=(aux-1)*(aux-1);
														if(a==b){
															aux35++;
															break;
														}
														MovimientoJ(aux, D, Matriz_Tab);
														a=scoreC+scoreJ;
														b=(aux-1)*(aux-1);
														if(a==b){
															aux35++;
														}
														printf("\nEl puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
													}while(aux35==0);
													imprimirTablero(aux, D, Matriz_Tab);
													if(scoreJ>scoreC){
														printf("\n**Gano el jugador con %d puntos, felicidades**\n\n", scoreJ*10);
													}else{
														if(scoreJ==scoreC){
															printf("\n*Empataron, ambos con %d puntos*\n\n", scoreC*10);
														}else{
															printf("\n*Gano la computadora con %d puntos*\n\n", scoreC*10);
														}
													}
													scoreJ=0,scoreC=0;
													char c;
													while ((c = getchar()) != '\n' && c != EOF) { };
												}else{
													int aux;
													printf("\nTamanho de la matriz: ");
													scanf("%d", &aux);
													while(aux<3||aux>15){
														while((getchar()!='\n'))
															continue;
														printf("\nTamanho de la matriz incorrecto ingrese de new: ");
														scanf("%d", &aux);
													};
													int D=aux*2-1;
													int Matriz_Tab[D][D];
													llenarTablero(aux, D, Matriz_Tab);
													aux35=0;
													do{
														MovimientoC(aux, D, Matriz_Tab);
														imprimirTablero(aux, D, Matriz_Tab);
														a=scoreC+scoreJ;
														b=(aux-1)*(aux-1);
														if(a==b){
															aux35++;
															break;
														}
														MovimientoJ(aux, D, Matriz_Tab);
														a=scoreC+scoreJ;
														b=(aux-1)*(aux-1);
														if(a==b){
															aux35++;
														}
														printf("\nEl puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
													}while(aux35==0);
													imprimirTablero(aux, D, Matriz_Tab);
													if(scoreJ>scoreC){
														printf("\n**Gano el jugador con %d puntos, felicidades**\n\n", scoreJ*10);
													}else{
														if(scoreJ==scoreC){
															printf("\n*Empataron, ambos con %d puntos*\n\n", scoreC*10);
														}else{
															printf("\n*Gano la computadora con %d puntos*\n\n", scoreC*10);
														}
													}
													scoreJ=0,scoreC=0;
													char c;
													while ((c = getchar()) != '\n' && c != EOF) { };
												}
											}else{
												int ale;
												printf("\n*Empieza Jugador*\n");
												printf("\nTamanho de matriz random\n1.Si\n2.No\n");
												scanf("%d", &ale);
												while(getchar()!='\n');
												if(ale==1){
													int aux;
													aux=rand()%12+3;
													int D=aux*2-1;
													int Matriz_Tab[D][D];
													llenarTablero(aux, D, Matriz_Tab);
													aux35=0;
													do{
														imprimirTablero(aux, D, Matriz_Tab);
														MovimientoJ(aux, D, Matriz_Tab);
														a=scoreC+scoreJ;
														b=(aux-1)*(aux-1);
														if(a==b){
															aux35++;
															break;
														}
														MovimientoC(aux, D, Matriz_Tab);
														a=scoreC+scoreJ;
														b=(aux-1)*(aux-1);
														if(a==b){
															aux35++;
														}
														printf("\nEl puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
													}while(aux35==0);
													imprimirTablero(aux, D, Matriz_Tab);
													if(scoreJ>scoreC){
														printf("\n**Gano el jugador con %d puntos, felicidades**\n\n", scoreJ*10);
													}else{
														if(scoreJ==scoreC){
															printf("\n*Empataron, ambos con %d puntos*\n\n", scoreC*10);
														}else{
															printf("\n*Gano la computadora con %d puntos*\n\n", scoreC*10);
														}
													}
													scoreJ=0,scoreC=0;
													char c;
													while ((c = getchar()) != '\n' && c != EOF) { };
												}else{
													int aux;
													printf("\nTamanho de la matriz: ");
													scanf("%d", &aux);
													while(aux<3||aux>15){
														while((getchar()!='\n'))
															continue;
														printf("\nTamanho de la matriz incorrecto ingrese de new: ");
														scanf("%d", &aux);
													}
													int D=aux*2-1;
													int Matriz_Tab[D][D];
													llenarTablero(aux, D, Matriz_Tab);
													aux35=0;
													do{
														imprimirTablero(aux, D, Matriz_Tab);
														MovimientoJ(aux, D, Matriz_Tab);
														a=scoreC+scoreJ;
														b=(aux-1)*(aux-1);
														if(a==b){
															aux35++;
															break;
														}
														MovimientoC(aux, D, Matriz_Tab);
														a=scoreC+scoreJ;
														b=(aux-1)*(aux-1);
														if(a==b){
															aux35++;
														}
														printf("\nEl puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
													}while(aux35==0);
													imprimirTablero(aux, D, Matriz_Tab);
													if(scoreJ>scoreC){
														printf("\n**Gano el jugador con %d puntos, felicidades**\n\n", scoreJ*10);
													}else{
														if(scoreJ==scoreC){
															printf("\n*Empataron, ambos con %d puntos*\n\n", scoreC*10);
														}else{
															printf("\n*Gano la computadora con %d puntos*\n\n", scoreC*10);
														}
													}
													scoreJ=0,scoreC=0;
													char c;
													while ((c = getchar()) != '\n' && c != EOF) { };
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}



void imprimirTablero(int aux, int D, int Matriz_Tab[][D]){
	int n=1;
	printf(" ");
	for(int l=0; l<aux; l++){
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
				printf("  ");
			}
		}
		for(int j=0; j<D; j++){
			printf("%c", Matriz_Tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
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

void MovimientoJ(int aux,int D, int Matriz_Tab[][D]){
	int x, y, f, c, p, q, a, b;
	int band2=0;
	while(band2==0){
		printf("Seleccione las fichas que desee unir...\n");
		printf("\tPunto A (Introduzca primero la fila, luego un salto de linea y la columna)\n");
		scanf("%d %d",&f,&c);
		while(getchar()!='\n');
		printf("\tPunto B (Introduzca primero la fila, luego un salto de linea y la columna)\n");
		scanf("%d %d",&x,&y);
		while(getchar()!='\n');
		if(f<=aux+1&&c<=aux+1&&x<=aux+1&&y<=aux+1&&f>0&&c>0&&x>0&&y>0){				///verifica q los valores esten en rango
			f=(f-1)*2;
			c=(c-1)*2;
			x=(x-1)*2;
			y=(y-1)*2;
			if(f==x){
				if((c==y-2)||(c==y+2)){
					p=c<y?c:y;														///p guarda el valor menor
					if(Matriz_Tab[f][p+1]==' '){
						Matriz_Tab[f][p+1]='-';
						band2++;
						if(Matriz_Tab[f+1][p]=='|' && Matriz_Tab[f+1][p+2]=='|' && Matriz_Tab[f+2][p+1]=='-'){	///el encerrado arriba
							if(Matriz_Tab[f+1][p+1]==' '){
								Matriz_Tab[f+1][p+1]='J';
								scoreJ++;
								band2=0;
								imprimirTablero(aux, D, Matriz_Tab);
								printf("El puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
								a=scoreC+scoreJ;
								b=(aux-1)*(aux-1);
								if(a==b){
									aux35++;
									band2++;
								}
							}
						}
						if(Matriz_Tab[f-1][p]=='|' && Matriz_Tab[f-1][p+2]=='|' && Matriz_Tab[f-2][p+1]=='-'){	///el encerrado abajo
							if(Matriz_Tab[f-1][p+1]==' '){
								Matriz_Tab[f-1][p+1]='J';
								scoreJ++;
								band2=0;
								imprimirTablero(aux, D, Matriz_Tab);
								printf("El puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
								a=scoreC+scoreJ;
								b=(aux-1)*(aux-1);
								if(a==b){
									aux35++;
									band2++;
								}
							}
						}
					}else{
						printf("Jugada no valida\n\n");
					}

				}else{
					printf("Jugada no valida\n\n");
				}
			}else{
				if(c==y){
					if((f==x-2)||(f==x+2)){
						q=f<x?f:x;														///q guarda el valor menor
						if(Matriz_Tab[q+1][c]==' '){
							Matriz_Tab[q+1][c]='|';
							band2++;
							if(Matriz_Tab[q+1][c-2]=='|'&&Matriz_Tab[q][c-1]=='-'&&Matriz_Tab[q+2][c-1]=='-'){	///el encerrado a la dereccha
								if(Matriz_Tab[q+1][c-1]==' '){
									Matriz_Tab[q+1][c-1]='J';
									scoreJ++;
									band2=0;
									imprimirTablero(aux, D, Matriz_Tab);
									printf("El puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
									a=scoreC+scoreJ;
									b=(aux-1)*(aux-1);
									if(a==b){
										aux35++;
										band2++;
									}
								}
							}
							if(Matriz_Tab[q+1][c+2]=='|'&&Matriz_Tab[q][c+1]=='-'&&Matriz_Tab[q+2][c+1]=='-'){	///el encerrado a la izquierda
								if(Matriz_Tab[q+1][c+1]==' '){
									Matriz_Tab[q+1][c+1]='J';
									scoreJ++;
									band2=0;
									imprimirTablero(aux, D, Matriz_Tab);
									printf("El puntaje del Jugador es %d\nEl puntaje de la maquina es %d\n\n", scoreJ*10, scoreC*10);
									a=scoreC+scoreJ;
									b=(aux-1)*(aux-1);
									if(a==b){
										aux35++;
										band2++;
									}
								}
							}
						}else{
							printf("Jugada no valida\n\n");
						}
					}else{
						printf("Jugada no valida\n\n");
					}
				}else{
					printf("Jugada no valida\n\n");
				}
			}
		}else{
			printf("Jugada no valida\n\n");
		}
	}
}

void MovimientoC(int aux,int D, int Matriz_Tab[][D]){
	int x, y, f, c, p, q, a, b;
	int band1=0;
	while(band1==0){
		f=rand()%aux+1;
		c=rand()%aux+1;
		x=rand()%aux+1;
		y=rand()%aux+1;
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
						band1++;
						printf("\n*La computadora unio el %d %d con %d %d *\n\n", ((f+1)/2)+1, ((c+1)/2)+1, ((x+1)/2)+1, ((y+1)/2)+1 );
						if(Matriz_Tab[f+1][p]=='|' && Matriz_Tab[f+1][p+2]=='|' && Matriz_Tab[f+2][p+1]=='-'){	///el encerrado arriba
							if(Matriz_Tab[f+1][p+1]==' '){
								Matriz_Tab[f+1][p+1]='C';
								scoreC++;
								band1=0;
								a=scoreC+scoreJ;
								b=(aux-1)*(aux-1);
								if(a==b){
									aux35++;
									band1++;
								}
							}
						}
						if(Matriz_Tab[f-1][p]=='|' && Matriz_Tab[f-1][p+2]=='|' && Matriz_Tab[f-2][p+1]=='-'){	///el encerrado abajo
							if(Matriz_Tab[f-1][p+1]==' '){
								Matriz_Tab[f-1][p+1]='C';
								scoreC++;
								band1=0;
								a=scoreC+scoreJ;
								b=(aux-1)*(aux-1);
								if(a==b){
									aux35++;
									band1++;
								}
							}
						}
					}
				}
			}else{
				if(c==y){
					if((f==x-2)||(f==x+2)){
						q=f<x?f:x;														///q guarda el valor menor
						if(Matriz_Tab[q+1][c]==' '){
							Matriz_Tab[q+1][c]='|';
							band1++;
							printf("\n*La computadora unio el %d %d con %d %d *\n\n", ((f+1)/2)+1, ((c+1)/2)+1, ((x+1)/2)+1, ((y+1)/2)+1);
							if(Matriz_Tab[q+1][c-2]=='|'&&Matriz_Tab[q][c-1]=='-'&&Matriz_Tab[q+2][c-1]=='-'){	///el encerrado a la dereccha
								if(Matriz_Tab[q+1][c-1]==' '){
									Matriz_Tab[q+1][c-1]='C';
									scoreC++;
									band1=0;
									a=scoreC+scoreJ;
									b=(aux-1)*(aux-1);
									if(a==b){
										aux35++;
										band1++;
									}
								}
							}
							if(Matriz_Tab[q+1][c+2]=='|'&&Matriz_Tab[q][c+1]=='-'&&Matriz_Tab[q+2][c+1]=='-'){	///el encerrado a la izquierda
								if(Matriz_Tab[q+1][c+1]==' '){
									Matriz_Tab[q+1][c+1]='C';
									scoreC++;
									band1=0;
									a=scoreC+scoreJ;
									b=(aux-1)*(aux-1);
									if(a==b){
										aux35++;
										band1++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


