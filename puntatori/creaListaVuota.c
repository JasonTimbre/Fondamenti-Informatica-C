#include <stdio.h>
#include<stdlib.h>

typedef struct nodo {
int numeri;
struct nodo* next;
}Nodo;


	void visualizzaLista(Nodo* head) {
	if(head == NULL)
		printf("Lista vuota,niente da visualizzare\n");
	else{
		printf("ecco la lista\n");
		while(head!=NULL){
			printf("%d",head->numeri);
			head = head->next;
		}
	}
}
int main() {
		//dichiaro lista vuota
	Nodo* head = NULL;
		//creo un nuovo nodo
	Nodo* nuovo = malloc(sizeof(Nodo));
	if(nuovo==NULL) {
		printf("Spiacente lista vuota");
	return 1;
	}

	nuovo->numeri = 10;	//valore esempio
	nuovo->next = head;	//punta alla vecchia testa (NULL)
	head = nuovo;

	printf("Nodo inserito in testa: %d ",head->numeri);
	return 0; 

	visualizzaLista(head);
}
