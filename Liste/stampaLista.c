#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
	int n;
	struct nodo* next;
}nodo;

	/* Funzione che stampa la lista */

void stampaLista(nodo* head) {
	if(head==NULL)
		printf("Mi dispiace, Lista vuota");
	else {
	while(head!=NULL) {
		printf("%d ", head->n);
		head = head->next;
		}
	}
}

int main() {
	nodo* head = malloc(sizeof(nodo));
	nodo* corrente;
	head->n = 10;
	head->next = malloc(sizeof(nodo));
	corrente = head->next;
	corrente->n = 2;
	corrente->next = malloc(sizeof(nodo));
	corrente = corrente->next;
	corrente->n = -1;
	corrente->next = NULL;

	stampaLista(head);

}