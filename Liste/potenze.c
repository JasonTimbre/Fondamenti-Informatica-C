	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<math.h>


	typedef struct potenza {
		float base;
		float esponente;
	}Potenza;

	typedef struct nodo {
		Potenza p;
		struct nodo* next;
	}Nodo;

	/*funzione per cancellare nodo*/
	Nodo* cancellaPotenza(Nodo* head, int n) {
		/*se lista vuota*/
		if(head==NULL) {
			printf("Lista vuota, niente da cancellare\n\n");
			return head;
		}

		Nodo* temp = head;
		Nodo* prev = NULL;

		if(pow(temp->p.base, temp->p.esponente) == n) {
			head = head->next;
			free(temp);
			printf("Cancellazione effettuata\n\n");
			return head;
		}
		
		while(temp != NULL){	//scorro la lista
			if(pow(temp->p.base, temp->p.esponente) == n) {		//se potenza corrisponde ai dati del nodo
				prev->next = temp->next;
				free(temp);
				printf("Cancellazione effettuata\n\n");
				return head;								//sgancio il nodo
				}	
			prev = temp;
			prev->next = NULL;
			}
		
		printf("Nessun nodo trovato con quella potena\n\n");
		return head;
	}

	/*funzione per inserire in testa*/
	Nodo* inserimentoTesta(Nodo* head) {
		Nodo* nuovo = malloc(sizeof(Nodo));
		if(nuovo == NULL) {
			printf("Errore di allocazione\n");
			return head;
		}
		printf("Dammi base: ");
		scanf_s("%f",&(nuovo->p.base));
		printf("Dammi esponente: ");
		scanf_s("%f", &(nuovo->p.esponente));
		
		/*se lista vuota*/
		if(head == NULL) {
			head = nuovo;
			nuovo->next = NULL;	
			printf("Inserimento effettuato\n\n");
		}
		else{
			nuovo->next = head;	// nuovo nodo punta al vecchio primo nodo
			head = nuovo;		//aggiorno la testa
			printf("Inserimento effettuato\n\n");
		}
		return head;
	}


	/* funzione per visualizzare la lista*/
	void visualizzaLista(Nodo* head) {
		/*se lista vuota*/
		if(head == NULL)
			printf("Lista vuota\n\n");
		else {
			printf("Ecco la lista:\n");
			while(head != NULL) {
				printf("Base:%f ",head->p.base);
				printf("Esponente:%f.\n", head->p.esponente);	
				head = head->next;
			}
			printf("Fine lista.\n\n");
		}
	}
	int main() {
		Nodo* head = NULL;
		int scelta = -1;
		while(scelta != 0) {
			printf("1 per visualizzare lista\n");
			printf("2 per inserire in testa\n");
			printf("3 per cancellare\n");
			printf("0 per terminare\n");
			scanf_s("%d",&scelta);
			if(scelta == 1)
				visualizzaLista(head);
			if(scelta == 2)
				head =inserimentoTesta(head);
			if(scelta == 3) {
				int n;
				printf("Dammi la potenza da cancellare: ");
				scanf_s("%d",&n);
				head = cancellaPotenza(head,n);
			}
		}

	}