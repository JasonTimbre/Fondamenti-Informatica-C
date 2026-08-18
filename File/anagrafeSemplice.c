#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct nascita {
	int giorno;
	int mese;
	int anno;
}NASCITA;

typedef struct persona {
	char nome[20];
	char cognome[20];
	NASCITA nascita;
}PERSONA;

typedef struct nodo {
	PERSONA p;
	struct nodo* next;
}NODO;

void visualizzaLista(NODO* head) {
	/*se lista vuota*/
	if(head==NULL)
		printf("Mi dispiace lista vuota\n\n");
	/* altrimenti*/
	else {
		printf("Ecco la lista:\n");
		while(head!=NULL) {
			printf("%s %s\n",head->p.nome,head->p.cognome);
			head = head->next;
		}
		printf("Fine lista\n\n");
	}
}
/*funzione che legge i dati in input*/
void leggiDati(PERSONA* p) {
	printf("Dammi il nome: ");
	scanf_s("%s",&(p->nome),20);
	printf("Dammi il cognome: ");
	scanf_s("%s",&(p->cognome),20);
}
/*Funzione per inserire persona rispettando l'ordine
	lessicografico*/
NODO* inserimentoTesta(NODO* head) {
	NODO* nuovo = malloc(sizeof(NODO));
	leggiDati(&(nuovo->p));
	/*se lista vuota*/
	if(head==NULL){
		nuovo->next=NULL;
		head = nuovo;
	}
	else{
		nuovo->next = head;
		head = nuovo;
		}

		printf("Persona inserita!\n\n");
return head;
}		
int main() {
	NODO* head = NULL;
	int scegli = -1;
	printf("Benventuto nell'anagrafe!!\n");
	while(scegli!=0) {
		printf("Digita 1 per visualizzare la lista\n");
		printf("Digita 2 per inserire una persona in lista mantenendo ordine lessicografico \n");
		printf("Digita 3 per stampare dati di una persona\n");
		printf("Digita 4 per cancellare i dati di una persona\n");

		scanf_s("%d",&scegli);


		if(scegli==1)
			visualizzaLista(head);

		if(scegli==2)
			head = inserimentoTesta(head);
	

}
}


