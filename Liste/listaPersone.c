#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nascita {
	int giorno;
	int mese;
	int anno;
}Nascita;

typedef struct persona {
	char nome[20];
	char cognome[20];
	Nascita nascita ;
}Persona;

typedef struct nodo {
	Persona pers;
	struct nodo* next;
}Nodo;
/* Funzione per l'aquisizione dei dati*/
void leggiDati(Persona* pers) {
	printf("Dimmi il tuo nome: ");
	fgets(pers->nome, 20, stdin);
	(pers->nome)[strlen(pers->nome)-1] ='\0';

	printf("Dimmi il tuo cognome: ");
	fgets(pers->cognome, 20, stdin);
	(pers->cognome)[strlen(pers->cognome)-1] ='\0';

	printf("Dammi la tua data di nascita(giorno): ");
	scanf_s("%d%*c", &(pers->nascita.giorno));
	

	printf("Dammi la tua data di nascita(mese): ");
	scanf_s("%d%*c", &(pers->nascita.mese));


	printf("Dammi la tua data di nascita(anno): ");
	scanf_s("%d%*c", &(pers->nascita.anno));

}
 
/*funzione per stampare persona*/
void stampaPersona(Persona p) {
	printf("%s ",p.nome);
	printf("%s ",p.cognome);
	printf("%d/", p.nascita.giorno);
	printf("%d/", p.nascita.mese);
	printf("%d\n", p.nascita.anno);		
}

/* Funzione per visualizzare la lista*/
void visualizzaLista(Nodo* head) {
	/* Se lista vuota*/
	if(head == NULL)
		printf("Lista vuota, niente da visualizzare.\n\n");
	else {
		printf("Ecco la lista:\n");
		while(head != NULL) {
			stampaPersona(head->pers);
			head = head->next;

		}
		printf("Fine lista.\n\n");
	}
}
/*Funzione per inserire in coda alla lista*/
Nodo* inserimentoInCoda(Nodo* head) {
	Nodo* nuovo = malloc(sizeof(Nodo));
	if(nuovo == NULL){
		printf("Errore di allocazione\n\n");
		return head;
	}
	leggiDati(&(nuovo->pers));
	nuovo->next = NULL;	//dichiaro che sara l'ultimo

	/*se lista vuota*/
	if(head == NULL) {
		printf("Inserimento effettuato\n\n");
		return nuovo;
	}
	else {
		Nodo* temp = head;
		while(temp->next != NULL) {	//scorro fino all'ultimo
			temp = temp->next;
		}
		temp->next = nuovo;	//aggancio l'ultimo nodo
		printf("Inserimento effettuato\n\n");
	}
	return head;
}
/* Fuznione per eliminare elemento in testa*/
Nodo* cancellaInTesta(Nodo* head) {
	Nodo* primoNodo = malloc(sizeof(Nodo));
	/*se lista vuota*/
	if(head == NULL) {
		printf("Lista vuota, Niente da cancellare\n\n");
		return head;
	}
	else {
		primoNodo = head->next;
		free(head);
		printf("Cancellazione effettuata\n\n");
	}
	return	primoNodo;
}
int main() {
	Nodo* head = NULL;
	int scelta = -1;
	while(scelta !=0){
	printf("Premi 1 per visualizzare lista\n");
	printf("Premi 2 per inserire in coda\n");
	printf("Premi 3 per eliminare testa\n");
	printf("Premi 0 per terminare il programma\n");
	scanf_s("%d%*c",&scelta);

	if(scelta == 1)
		visualizzaLista(head);

	if(scelta == 2)
		head = inserimentoInCoda(head);
	if(scelta == 3)
		head = cancellaInTesta(head);
	}
}