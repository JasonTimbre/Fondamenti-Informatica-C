#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Fritto {
	char nome[50];
	float prezzo;
	char surgefre;
}FRI;

typedef struct nodo {
	FRI f;
	struct nodo* next;
}NODO;

/* f che legge i dati di un fritto */
void leggiDati(FRI* f) {
printf("Come si chiama il nuovo fritto?\n");
fgets(f->nome,50,stdin);
(f->nome)[strlen(f->nome)-1] = '\0';
printf("Quanto costa?\n");
scanf_s("%f*c",&(f->prezzo));
printf("surgelato o fresco? (s/f)? ");
scanf_s("%c",&(f->surgefre));
}

/* inserimento coda*/
void inserimentoCoda(NODO**puntaHead) {
	NODO* nuovo = malloc(sizeof(NODO));
	leggiDati(&(nuovo->f));
	nuovo->next = NULL;
	/**lista vuota*/
	if(*puntaHead == NULL) 
		*puntaHead = nuovo;
	else {
		NODO* nodo = *puntaHead;
		/* vai alla ricerca dell ultimo nodo*/
		while(nodo->next!= NULL)
			nodo = nodo->next;		
		/* fai il collegamento*/
		nodo->next = nuovo;
	}
	printf("Inserimento effettuato\n");
	}

/* funzione visualizza lista*/
	void visualizza(NODO* head) {
		if(head== NULL)
			printf("niente da visualizzare\n");
		else {
			printf("Ecco la lista di fritti");
			while(head!=NULL) {
				printf("Fritto: %s\n",head->f.nome);
				printf("Prezzo: %.2f\n\n",head->f.prezzo);
				if(head->f.surgefre=='f')
					printf("il fritto e' fresco\n");
				else if(head->f.surgefre == 's')
					printf("il fritto e' surgelato\n");				
			}
			printf("lista di fritti finita\n");
		}
	}

	/* Cancellazione multipla */
	void cancellaTutti(NODO** head) {
		if(*head==NULL)
			printf("Lista vuota, niente da cancellare\n\n");
		else {
			int cancellato;	//hai cancellato?
			/* Cancellazioni in testa*/
			while(*head!=NULL && (*head)->f.prezzo>3) {
				NODO* dealloca = *head;
				*head = dealloca->next;
				free(dealloca);
				cancellato = 1;
			}
			/*Lista ora vuota*/
			if(*head==NULL)
				printf("La lista si e'svuotata\n");
			/* Lista ha ancora nodi */
			else {
				NODO* nodo = *head;
				NODO* successivo = nodo->next;
				while(successivo!= NULL) {
					if(successivo->f.prezzo>3) {
						NODO* dealloca = successivo;
						nodo->next = successivo->next;
						free(dealloca);
						cancellato=1;
						successivo  = nodo->next;
					}
					else {
						nodo =successivo;
						successivo = successivo->next;
					}
				}
				if(cancellato)
					("Ho cancellato fritti costosi\n\n");
				else
					printf("Non c'era nessun fritto costoso\n\n");
			}
		}
	}

	int ordineSbagliato(FRI* f1,FRI* f2) {
		int ris = 0;
		if((f1->surgefre == 's' && f1->surgefre == 'f') ||
			(f1->surgefre == f2->surgefre && f1->prezzo>f2->prezzo))
			ris = 1;
			return ris; 
	}


	/* Ordinamento */
	void bubbleSort(NODO* head) {
		if(head==NULL)
			printf("Lista vuota, niente da ordinare\n");
		else {

		int fattoScambio = 1;		//ultima passata ha modificato
		while(fattoScambio) {
			fattoScambio = 0;	//in questa passata nessuno scambio
			for(NODO* nodo = head; nodo->next!=NULL; nodo=nodo->next) {
				if(ordineSbagliato(&(nodo->f),&(nodo->f)))
					fattoScambio=1;
					FRI temp = nodo->f;
					nodo->f = nodo->next->f;
					nodo->next->f = temp;
					fattoScambio = 1;
				}
			}
	printf("La lista e' ora ordinata\n");
	}
}

/*Funzione Principale*/
int main() {
/* creazione lista*/
	NODO* nuovo = NULL;
	NODO* head = NULL;
	int scelta = -1;	//per la scelta dell'utente
	while(scelta!=0)
		printf("Caro utente,cosa vuoi fare?\n");
		printf("Digita 1 per inseririo un fritto in coda\n");
		printf("Digita 2 per visualizzare i fritti\n");
		printf("Digita 3 cancella i fritti costosi\n");
		printf("Digita 4 per ordinare i fritti\n");
		printf("0 per terminare il programma\n");
		scanf_s("%d",&scelta);

		if(scelta==1)
			inserimentoCoda(&head);
		if(scelta==2)
			visualizza(head);
		if(scelta==3)
			cancellaTutti(&head);
		if(scelta==4)
			bubbleSort(head);
}