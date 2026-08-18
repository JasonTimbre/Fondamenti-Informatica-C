#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int val;
	struct nodo* next;
}Nodo;

/*funzione per la creazione della  lista*/
Nodo* creaLista() {
	Nodo* head = NULL;
	int x;
	printf("Inserisci un numero(0 per terminare)");
	scanf_s("%d",&x);
	while(x!=0) {
		Nodo* nuovo=malloc(sizeof(Nodo)); //alloco nuovo nodo
		if(nuovo == NULL) {
			printf("Errore di allocazione.\n");
			return head;
		}
		nuovo->val = x;		//salvo il valor
		nuovo->next = head;	//aggiorno il nuovo alla vecchia testa
		head = nuovo;	//aggiorno la testa

		printf("Inserisci un numero(0 per terminare)");
		scanf_s("%d",&x);
	}
	return head;
}




int main() {

}