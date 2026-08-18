#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
	int intero;	//campo informazione
	struct Nodo* next;	//puntatore al prossimo nodo
}NODO;

	/* stampa elementi della lista*/

void stampaElemento (int* p){
	printf("Prossimo elemento della lista: %d\n",*p);
}

	/** visualizzazione di una lista */
void visualizzazione(NODO* testa) {
	/* lista vuota*/
	if(testa==NULL)
		printf("Mi dispiace,lista vuota!\n");
	/*ci sono elementi*/
	else
		while(testa!=NULL){
			stampaElemento(&testa->intero);
		testa = testa->next;
	}


}

int main() {
	NODO* head = malloc(sizeof(NODO));
	NODO* corrente;
 	head->intero = 1;
	head->next = malloc(sizeof(NODO));
	corrente = head->next;
	corrente->intero = 3;
	corrente->next = malloc(sizeof(NODO));
	corrente = corrente->next;
	corrente->intero = -1;
	corrente->next = NULL;
                        
	visualizzazione(head);
}