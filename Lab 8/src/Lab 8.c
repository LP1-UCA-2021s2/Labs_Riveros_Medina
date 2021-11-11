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

struct Nodo {
  int dato;
  struct Nodo* otro;
};

void insertarAlFondo(struct Nodo** cabeza, int nuevo_dato) {
  struct Nodo* nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
  struct Nodo* ultimo = *cabeza;

  nuevo_nodo->dato = nuevo_dato;
  nuevo_nodo->otro = NULL;

  if (*cabeza == NULL) {
  *cabeza = nuevo_nodo;
  return;
  }

  while (ultimo->otro != NULL) ultimo = ultimo->otro;

  ultimo->otro = nuevo_nodo;
  return;
}

void Borrar(struct Nodo** cabeza, int k) {
  struct Nodo *temp = *cabeza, *atras;

  if (temp != NULL && temp->dato == k) {
  *cabeza = temp->otro;
  free(temp);
  return;
  }

  while (temp != NULL && temp->dato != k) {
  atras = temp;
  temp = temp->otro;
  }
  if (temp == NULL) return;
  atras->otro = temp->otro;
  free(temp);
}

void Ordenar(struct Nodo** cabeza) {
  struct Nodo *actual = *cabeza, *index = NULL;
  int temp;

  if (cabeza == NULL) {
  return;
  } else {
  while (actual != NULL) {

    index = actual->otro;

    while (index != NULL) {
    if (actual->dato > index->dato) {
      temp = actual->dato;
      actual->dato = index->dato;
      index->dato = temp;
    }
    index = index->otro;
    }
    actual = actual->otro;
  }
  }
}
void Imprimir(struct Nodo* nodo) {
  while (nodo != NULL) {
  printf(" %d ", nodo->dato);
  nodo = nodo->otro;
  }
}
int main() {
	int aux=99;
	struct Nodo* C = NULL;
	int Ingresar,Eliminar,i,sn;
	while(aux!=0){
		printf("Ingresar el valor a la lista de uno en uno(-1 para salir): ");
		scanf ("%d",&Ingresar);
		if(Ingresar==-1){
			aux=0;
		}else{
		insertarAlFondo(&C, Ingresar);
		}
	}
	printf("\nLa Lista ingresada: ");
	Imprimir(C);
	Ordenar(&C);
	printf("\nOrdenar Lista: ");
	Imprimir(C);
	printf("\nDesea borrar un valor? \n1.Si\n2.No\n");
	scanf("%d", &sn);
	if(sn==1){
		printf("\nIngresar Valor a Borrar : ");
		scanf ("%d",&Eliminar);
		for(i=0;i<100;i++){
			Borrar(&C,Eliminar);
		}
		printf("\nLista Borrada : ");
		Imprimir(C);
		Ordenar(&C);
		printf("\nOrdenar Lista Borrada : ");
		Imprimir(C);
	}else{
		return 0;
	}
}
