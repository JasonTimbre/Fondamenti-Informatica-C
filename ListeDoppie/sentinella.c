#include<stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct nodo {
	int numero;
	struct nodo* next;
	struct nodo* prev;
}NODO;

typedef struct doppia {
	NODO* head;
	NODO* tail;
}DOPPIA;

/* visualizzaizione */
void visualizzaLista(NODO* lista) {
	NODO* nodo = lista->next;
	/* Lista vuota*/ 
	if(nodo==lista)
		printf("Lista vuota\n");
	else {
		printf("Ecco i numeri in lista: ");
		while(nodo!=lista) {
			printf("%d ",nodo->numero);
			nodo = nodo->next;
		}
		printf("\nFIne lista\n\n");
	}
}

void inserimentoTesta(DOPPIA* lista) {
	NODO* nuovo = malloc(sizeof(NODO));	//creo il nodo
	printf("Che numero vuoi inserire in lista? ");
	scanf_s("%d", &(nuovo->numero));	//alloco l'info

	/* Campi collegamento nuovo nodo*/
	nuovo->prev = lista;\
	nuovo->next = lista->next;
	/* se lista è vuota, cambia tail */
	if(lista->next == lista)
		lista->prev = nuovo;
	/* se lista non è vuota, cambia il prev del primo*/ 
	else {
		lista->next->prev = nuovo;
	}
	/*Modifica testa della lista */
	lista->next = nuovo;
	printf("Inserimento effettuato\n\n");

}

int main() {
	NODO* lista = malloc(sizeof(NODO));
	lista->next = lista;
	lista->prev = lista;
	
	int scelta = -1;
	while(scelta!=0) {
		printf("Digita 1 per visualizzare la lista: ");
		printf("Digita 2 per inserire un nuovo numero in testa:  ");
		printf("Digita 3 per cancellare punto con y piu piccola: ");
		printf("Digita 4 per calcolare e stampare la distanza minima tra deu punti della lista: ");		
		printf("Digita 5 per visualizzare punti con colore che vuoi: ");
		scanf_s("%d",&scelta);
		if(scelta==1)
			visualizzaLista(lista);
		if(scelta==2)
			inserimentoTesta(lista);