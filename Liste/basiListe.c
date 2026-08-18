#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
	int n;
	struct nodo* next;
}nodo;

/* funzione che stampa elementi di una lista */
void stampaLista(nodo* lista) {
	printf("Inizio lista");
	while(lista!=NULL) {
		printf("->%d->",lista->n);
		lista = lista->next;
	}
	printf("Fine lista.\n");
}
/* funzione che conta quanti nodi ha una lista */
int contaElementi(nodo* lista) {
	int conta = 0; //var contatore
	while(lista!=NULL){
		lista = lista->next;
		conta++;
	}
	return conta;
}
	/* inserimento in testa */
void inserimentoTesta(nodo** lista) {
		nodo* nuovo = malloc(sizeof(nodo));
		nuovo->next = NULL;
		nuovo->n = 8;
		if(lista==NULL){
			*lista = nuovo;
		}
		else {
			nuovo->next = *lista;
			*lista = nuovo;

		}

	}


int main() {
nodo* lista = NULL;
lista = (nodo*)malloc(sizeof(nodo));
lista->next = NULL;
lista->n =2;
nodo* nuovo = (nodo*) malloc(sizeof(nodo));
lista->next = nuovo;
nuovo->next = NULL;
int cont = contaElementi(lista);
printf("ci sono %d nodi",cont);
inserimentoTesta(&lista);
stampaLista(lista);
}