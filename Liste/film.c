#include <stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct film {
	char nomeFilm[20];
	char nomeRegista[20];
	int annoDiUscita;
	char vietato;
}Film;

typedef struct nodo {
	Film f;
	struct nodo* next;
}Nodo;
/*funzione che cancella l'ultimo film dell'elenco*/
Nodo* cancellaUltimoFilm(Nodo* head) {
/*se lista vuota*/
	if(head == NULL){
		printf("Niente da cancellare\n\n");
		return head;
	}
	/*se 1 solo nodo*/
	if(head->next == NULL){
		free(head);
		printf("Cancellazione effettutata\n\n");
		return NULL;
	}
	/*se 2 o piu nodi*/
	Nodo* temp = head;
	Nodo* prev = NULL;
	while(temp->next != NULL){
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	free(temp);
	printf("Cancellazione effettuata\n\n");
	return head;


}

/*Funzione per acquisire dati in input*/
void leggiDati(Film* f){
	printf("Dammi il nome del film: ");
	fgets(f->nomeFilm,20,stdin);
	f->nomeFilm[strlen(f->nomeFilm)-1] = '\0';

	printf("Dammi il nome del regista: ");
	fgets(f->nomeRegista,20,stdin);
	f->nomeRegista[strlen(f->nomeRegista)-1] = '\0';

	printf("Dammi data di uscita: ");
	scanf_s("%d",&(f->annoDiUscita));
	while(getchar() != '\n');


	printf("E' vietato ai Minori? (risopondi con S se si o N se NO): ");
	scanf_s(" %c", &(f->vietato), 1);
	while(getchar() != '\n');
}

/*funzione che inserisce film in testa*/
Nodo* inserimentoTesta(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	if(nuovo == NULL){
		printf("Errore di allocazione\n\n");
		return head;
	}
	else{
		leggiDati(&(nuovo->f));
		nuovo->next = head;
		head = nuovo;
		printf("Inserimento effettuato\n\n");
		return head;
	}
}
/*funzione per stampare film*/
void stampaFilm(Film f) {
	printf("Nome film:%s\n", f.nomeFilm);
	printf("Nome regista: %s\n", f.nomeRegista);
	printf("Anno di uscita : %d\n", f.annoDiUscita);
	printf("per 18?(S o N): %c\n\n", f.vietato);
}
/*funzione per visualizzare la lista*/
void visualizzaLista(Nodo* head){
	/*se lista vuota*/
	if(head==NULL){
		printf("Lista vuota\n\n");
	}
	else{
		printf("Ecco la lista:\n");
		while(head !=NULL){
			stampaFilm(head->f);
			head=head->next;
		}
	printf("Fine lista\n\n");
	}
}
int main() {
Nodo* head = NULL;
int scelta = -1;
while(scelta!=0) {
	printf("1 per visualizzare lista\n");
	printf("2 per inserire in testa un film\n");
	printf("3 per cancellare ultimo film in coda\n");
	printf("0 per terminare\n");

	scanf_s("%d",&scelta);

	if(scelta ==1)
		visualizzaLista(head);
	if(scelta==2)
		head = inserimentoTesta(head);
	if(scelta==3)
		head = cancellaUltimoFilm(head);
}	
}
