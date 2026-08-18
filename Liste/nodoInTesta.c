#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
	int n;
	struct nodo* next;
}nodo;

int main() {
	nodo* testa = NULL;	// lista vuota

	nodo* nuovo = malloc(sizeof(nodo));	//creo il primo nodo
	nuovo->n = 67;	// inizializzo il campo informazione
	nuovo->next = testa;	//punta alla vecchia testa
	testa = nuovo;	//aggiorno la testa

	printf("Nodo inserito in testa: %d\n",testa->n);



	


}