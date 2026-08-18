#include<stdio.h>
#include <stdlib.h>
#include<math.h>
//16:41

typedef struct punto {
	char colore[20];
	int x;
	int y;
}PUNTO;

typedef struct nodo {
	PUNTO p;
	struct nodo* next;
}NODO;

/* Funzione per la stampa di un nodo*/
void stampaNodo(NODO* head) {
	printf("\nColore: %s , X: %d, Y: %d  ",head->p.colore,head->p.x,head->p.y);
}

/* Funzione per la visualizzazione della lista */
void visualizzaLista(NODO* head) {
	/* Se lista vuota*/
	if(head==NULL) {
		printf("\nSpiacente,Lista vuota\n\n");
	}
	else {
		printf("\nEcco la lista\n");
		while(head!=NULL) { //finche non arrivo all'ultimo
			stampaNodo(head);	//stampo il nodo
			head = head->next;	//AVANZA AL PROSSIMO NODO
		}
		printf("\nFine Lista\n");	
	}
}	
/* Funzione per la acquisizione del punto */
void leggiDati(PUNTO* p) {
	printf("Dammi il colore: \n");
	scanf_s("%s", p->colore,20);
	printf("Dammi la X: \n");
	scanf_s("%d", &(p->x));
	printf("Dammi la Y: \n");
	scanf_s("%d", &(p->y));
}
/* Funzione per l'inserimento in testa */
NODO* inserimentoTesta(NODO* head) {
	NODO* nuovo = malloc(sizeof(NODO));
	leggiDati(&(nuovo->p));
	/* Se lista vuota */
	if(head == NULL) {
		nuovo->next = NULL;
		head = nuovo;
	}
	else {
		nuovo->next = head;	//aggangio il vecchio head
		head = nuovo;
	}
	return head;
}
/* Funzione che cancella il punto con coordinata Y minima */
NODO* cancellaMinimo(NODO* head) {
	/* Se lista vuota, esci*/
	if(head==NULL)
		printf("Spiacente,Nulla da cancellare.\n\n");
	else {
		NODO* minPrec = NULL;
		NODO* corrente = head;
		NODO* minNodo = head;
		NODO* precedente = NULL;
		while(corrente!=NULL) {
			if(corrente->p.y<minNodo->p.y) {
				minNodo = corrente;
				minPrec  = precedente;
			}
				precedente = corrente;
				corrente = corrente->next;
		}
		if(minPrec == NULL){
			head = head->next;
		}
		else{
			minPrec->next = minNodo->next;
		}
		free(minNodo);
		printf("Cancellato!\n\n");
	}
	return head;
}

/* Funzione che calcola la distanza euclidea dei punti della lista */
int distanzaMinima(NODO* head) {
	int distMin;
	/* Se lista vuota  o 1 nodo */
	if(head==NULL || head->next == NULL)
		return -1;

	else {
		distMin = 1000;
		NODO* p1 = head;
		/* Scelgo il primo punto */
		while(p1 != NULL) {
			NODO* p2 = p1->next;
			/* Confronto p1 con tutti i punti successivi */
			while(p2 != NULL) {
				int dx = p1->p.x - p2->p.x;
				int dy = p1->p.y - p2->p.y;

				int dist = sqrt(dx*dx + dy*dy);	//distanza euclidea

				if(dist < distMin)
					distMin = dist;

				p2 = p2->next;
			}
			p1 = p1->next;
		}
		return distMin;
	}

}

int main() {
	NODO* head = NULL;
	int scelta = -1;

	while(scelta!=0) {
		printf("Digita 1 per visualizzare la lista: \n");
		printf("Digita 2 per inserire un nuovo punto in testa:  \n");
		printf("Digita 3 per cancellare punto con y piu piccola: \n");
		printf("Digita 4 per calcolare e stampare la distanza minima tra deu punti della lista: \n");		
		printf("Digita 5 per visualizzare punti con colore che vuoi: \n");
		scanf_s("%d",&scelta);
		if(scelta==1)
			visualizzaLista(head);
		else if(scelta==2){
			 head = inserimentoTesta(head);
			 printf("Nodo inserito!\n\n");
		}
		else if(scelta==3){
			head = cancellaMinimo(head);
		}
		else if(scelta==4){
			int minimo = distanzaMinima(head);
			if(minimo == -1)
			printf("Non ci sono abbastanza punti per calcolare la distanza.\n\n");
		else
			printf("La distanza minima e': %d\n\n",minimo);
		}


		else
			printf("\n\nScelta non valida!\n\n");
	}
}