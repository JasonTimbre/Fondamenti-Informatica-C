#include<stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodo {
	int numero;
	struct nodo* next;
	struct nodo* prev;
}NODO;

typedef struct Doppia {
	NODO* head;
	NODO* tail;
}DOPPIA;

/* Visualizzazione*/
void visualizzaLista(DOPPIA* lista) {
	NODO* nodo = lista->head;
	/*lista vuota */
	if(nodo==NULL)
		printf("Lista vuota, niente da visalizzare\n");
	else  {
		printf("ecco i numeri in lista");
		while(nodo!=NULL) {
			printf("%d ",nodo->numero);
			nodo = nodo->next;
		}
		printf("\nFine lista\n\n");
	}
}
void inserimentoTesta(DOPPIA* lista) {
	NODO* nuovo = malloc(sizeof(NODO));	//creo il nodo
	printf("Che numero vuoi inserire in lista? ");
	scanf_s("%d", &(nuovo->numero));	//alloco l'info

	/* Campi collegamento nuovo nodo*/
	nuovo->prev = NULL;
	nuovo->next = lista->head;
	/* se lista è vuota, cambia tail */
	if(lista->head == NULL)
		lista->tail = nuovo;
	/* se lista non è vuota, cambia il prev del primo*/ 
	else {
		lista->head->prev = nuovo;
	}
	/*Modifica testa della lista */
	lista->head = nuovo;
	printf("Inserimento effettuato\n\n");

}
void inserimentoCoda(DOPPIA* lista) {
	NODO* nuovo = malloc(sizeof(NODO));	//creo il nodo
	printf("Che numero vuoi inserire in lista? ");
	scanf_s("%d", &(nuovo->numero));	//alloco l'info

	/* Campi collegamento nuovo nodo*/
	nuovo->prev = lista->tail;
	nuovo->next = NULL;
	/* se lista è vuota, cambia tail */
	if(lista->head == NULL)
		lista->head = nuovo;
	/* se lista non è vuota, cambia il next dell'ultimo */ 
	else {
		lista->tail->next = nuovo;
	}
	/*Modifica  della coda lista */
	lista->tail = nuovo;
	printf("Inserimento effettuato\n\n");

}

int main() {
	DOPPIA* lista = malloc(sizeof(DOPPIA));
	lista->head = NULL;
	lista->tail = NULL;
	int scelta = -1;
	while(scelta!=0) {
		printf("Digita 1 per visualizzare la lista: ");
		printf("Digita 2 per inserire un nuovo numero in testa:  ");
		printf("Digita 3 per inserire un numero in coda alla lista: ");
		printf("Digita 4 per calcolare e stampare la distanza minima tra deu punti della lista: ");		
		printf("Digita 5 per visualizzare punti con colore che vuoi: ");
		scanf_s("%d",&scelta);
		if(scelta==1)
			visualizzaLista(lista);
		if(scelta==2)
			inserimentoTesta(lista);
		if(scelta==3)
			inserimentoCoda(lista);
}
}