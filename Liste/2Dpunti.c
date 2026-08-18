#include<stdio.h>
#include<stdlib.h>

typedef struct punto {
	float x;
	float y;
}Punto;

typedef struct nodo {
	Punto p;
	struct nodo* next;
}Nodo;
/*funzione per cancellare ultimo punto*/
Nodo* cancellaUltimoPunto(Nodo* head) {
	/*se lista vuota*/
	if(head == NULL) {
		printf("Lista vuota, niente da cancellare\n\n");
		return head;
	}
	/*caso con 1 nodo*/
	if(head->next == NULL) {
		free(head);
		printf("Cancellazione effettuata\n\n");
		return NULL;
	}
	Nodo* temp = head;
	Nodo* prev = NULL;
	while(temp->next != NULL) {
	prev = temp;
	temp = temp->next;
	}
	/*prev è l'ultimo nodo*/
	prev->next = NULL;
	free(temp);
	printf("Cancellazione effettuata\n\n");
	return head;
}
/*funzione per cancellare primo punto*/
Nodo* cancellaPrimoPunto(Nodo* head) {
	Nodo* primoNodo;
	/*se lista vuota*/
	if(head == NULL){
		printf("Lista vuota, Niente da cancellare\n\n");
		return head;
	}
	else {
		primoNodo = head->next;//ASSEGNO AL NUOVO NODO IL VALORE DEL PROSSIM
		free(head);
		printf("Cancellazione effettuata\n\n");
	}
	return primoNodo;
}
/*Inserimento in coda*/
Nodo* inserimentoInCoda(Nodo* head) {
	Nodo* nuovo = malloc(sizeof(Nodo));
	nuovo->next = NULL;
	if(nuovo == NULL) {
		printf("Errore di allocazione\n\n");
		return head;
	}
	/*inserisco i dati*/
	printf("inserisci X: ");
	scanf_s("%f",&(nuovo->p.x));
	printf("inserisci Y: ");
	scanf_s("%f",&(nuovo->p.y));
	/*Se lista vuota*/
	if(head == NULL) {
		printf("Inserimento effettuato\n\n");
		return nuovo;
	}
	else {
		Nodo* temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		/*arrivato all'ultimo*/
		temp->next = nuovo; //il nuovo nodo ora è l'ultimo
		printf("Inserimento effettutato\n\n");
		return head;
	}
}

/*funzione per inserire in testa*/
Nodo* inserimentoTesta(Nodo* head) {
	/*creo nodo*/
	Nodo* nuovo =malloc(sizeof(Nodo));
	if(nuovo ==NULL) {
		printf("Errore di allocazione\n\n");
		return head;
	}
	/*Inserisco i dati*/
	printf("inserisci X: ");
	scanf_s("%f",&(nuovo->p.x));
	printf("inserisci Y: ");
	scanf_s("%f",&(nuovo->p.y));
	/*se lista vuota*/
	if(head == NULL) {
		nuovo->next = NULL;
		head = nuovo;
		printf("Inserimento effettutato\n\n");
		return head;
	}
	else {
		nuovo->next = head;	//il nuovo nodo puntera alla vecchia testa
		head = nuovo;	//il nuovo diventa la testa
		printf("Inserimento effettutato\n\n");
		return head; 
	}
}
/*funzione visualizza lista*/
void visualizzaLista(Nodo* head) {
	/* se lista vuota*/
	if(head == NULL) 
		printf("Lista vuota.\n\n");
	else {
		printf("Ecco la lista:\n");
		while(head!=NULL){
			printf("%f, %f\n",head->p.x, head->p.y);
			head = head->next;
		}
		printf("Fine lista\n\n");
	}
}	
int main() {
		Nodo* head = NULL;
		int scelta = -1;
		while(scelta != 0) {
			printf("1 per visualizzare lista\n");
			printf("2 per inserire in testa\n");
			printf("3 per inserire in coda\n");
			printf("4 per cancellare punto in testa\n");
			printf("5 per cancellare punto in coda\n");

			printf("0 per terminare\n");
			scanf_s("%d",&scelta);

			if(scelta==1) 
				visualizzaLista(head);
			if(scelta==2)
				head= inserimentoTesta(head);
			if(scelta==3)
				head = inserimentoInCoda(head);
			if(scelta==4)
				head = cancellaPrimoPunto(head);
			if(scelta==5)
				head= cancellaUltimoPunto(head);
		}
	}