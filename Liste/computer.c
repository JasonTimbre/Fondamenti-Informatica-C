#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct computer {
	char modello[50];	//modello del computer	
	int id;				//codice identificativo
	int ip[12];			//Indirizzo IP del computer
}Computer;

typedef struct nodo {
	Computer pc;
	struct nodo* next;
}Nodo;

/*funzione per acquisire input da utente*/
void leggiDati(Computer* pc) {
    int c;
    char buffer[100];

    printf("Dammi il codice del modello: ");
    fgets(pc->modello, 50, stdin);
    pc->modello[strcspn(pc->modello, "\n")] = '\0';

    printf("Dammi il codice identificativo: ");
    scanf_s("%d", &(pc->id));
    while((c = getchar()) != '\n' && c != EOF);

    printf("Dammi le 12 cifre dell'indirizzo IP (tutte di seguito, senza spazi): ");
    fgets(buffer, 100, stdin);

    // Conversione delle 12 cifre in 12 interi
    for(int i = 0; i < 12; i++) {
        pc->ip[i] = buffer[i] - '0';
    }
}

/*Funzione che inserisce pc in testa alla lista*/
Nodo* inserimentoTesta(Nodo* head) {
	/* Creo nuovo nodo*/
	Nodo* nuovo = malloc(sizeof(Nodo));	
	if(nuovo == NULL) {
		printf("Errode di allocazione\n\n");
		return head;
	}
	leggiDati(&(nuovo->pc));
	nuovo->next = head;	//nuovo nodo punta al primo nodo
	head = nuovo;	//sostituisco il vecchio nodo al nuovo no
	
	printf("Inserimento effetutato.\n\n");
	return head;

}

/* Funzione che cancella il primo computer dalla lista*/
Nodo* cancellaComputer(Nodo* head) {
	Nodo* primoNodo;	//nuovo primo nodo della lista
	/*se lista vuota*/
	if(head == NULL){
		primoNodo = NULL;
		printf("Lista Vuota, Niente da cancellare\n\n");
	}
	else {
		/*primo nodo diventa secondo nodo*/
		primoNodo = head->next;	
		/*dealloco memoria del vecchio primo nodo*/
		free(head);
		printf("Cancellazione effettuata.\n\n");
	}
	/*restituisco il nuovo primo nodo*/
	return primoNodo;
}


/*funzione per controllo esistenza di computer basandosi sul codice identificativo*/
int esisteComputer(Nodo* head,int ip) {
		/*se lista vuota*/
		if(head == NULL){
			return 0;
		}
		else {
			while(head != NULL) {	//scorro la lista
				/*se ip dell'utente è uguale al ip del nodo*/
				if(ip == head->pc.id)
					return 1;
				else
					head = head->next; //passo al nodo successivo
			}
			return 0;
		}
	}

	/* Funzione per leggere i dati inseriti dall'utente*/
	void stampaDati(Computer pc) {
		printf("Il computer e' di modello %s,  ",pc.modello);
		printf(" ha codice identificativo %d ed indirizzo IP ",pc.id);

		for(int i = 0;i<12; i++) {
			printf("%d",pc.ip[i]);
			/*ogni 3 cifre metti un punto, tranne dopo l'ultima*/
			if((i+1) % 3 == 0  && i != 11)
				printf(".");
		}
	}

	/* Funzione per la visualizzazione della lista*/
	void visualizzaLab(Nodo* head) {
		/*se lista vuota*/
		if(head == NULL) {
			printf("Lista vuota.\n\n");
		}
		else {
			printf("Ecco la lista:\n");
			while(head!=NULL){
				stampaDati(head->pc);
				printf("\n");
				head = head->next;
			}
			printf("Fine Lista\n\n");
		}
	}
	/* Funzione che inserisce pc in coda */
	Nodo* inserisciComputer(Nodo* head) {
		/*Creo il nuovo nodo*/
		Nodo* nuovo = malloc(sizeof(Nodo));
		if(nuovo==NULL) {
			printf("Errore di allocazione.\n\n");
			return head;
		}
		
		leggiDati(&(nuovo->pc));
		nuovo->next = NULL;		//dichiaro che sara l'ultimo nodo
		
		/*se lista vuota*/
		if(head==NULL) {
			printf("Inserimento effettutato.\n\n");
			return nuovo;
		}
		/*creo var temporanea per scorrere lista*/
		Nodo* temp = head;
		/* Scorro la lista*/
		while(temp->next != NULL) {
			temp = temp->next;
		}
		//aggancio il nuovo nodo in coda
		temp->next = nuovo;
		printf("Inserimento effettuato.\n\n");
		return head;
	}


	int main() {
		Nodo* head = NULL;
		int scelta = -1;
		while(scelta!=0) {
			printf("Premi 1 per visualizzare la lista\n");
			printf("Premi 2 per verificare esistenza di un pc nella lista\n");
			printf("Premi 3 per cancellare computere dalla lista\n");
			printf("Premi 4 per inserire un computer in coda nella lista\n");
			printf("Premi 5 per inserire pc in testa\n");
			printf("Premi 0 per terminare e salvare\n");

			scanf_s("%d",&scelta);
			while(getchar() != '\n');

			if(scelta == 1)
				visualizzaLab(head);
			if(scelta == 2){
				int codiceId;
				printf("Dammi il codice identificativo: ");
				scanf_s("%d",&codiceId);
				while(getchar() != '\n');	//pulizia buffer

				if(esisteComputer(head,codiceId))
					printf("Il computer esiste nella lista\n\n");
				else
					printf("Non esiste nessun Pc con quel Codice identificativo\n\n");
			}
			if(scelta == 3)
				head = cancellaComputer(head);

			if(scelta == 4)
				head = inserisciComputer(head);
			
			if(scelta == 5)
				head = inserimentoTesta(head);
	} 
	FILE* fp = fopen("lista.computer", "w");
	if(fp == NULL)
		printf("Apertura file non riuscito\n");

	else{
		Nodo* curr = head;
		while(curr!=NULL){
			fprintf(fp,"%s, %d, %d\n",
					curr->pc.modello,
					curr->pc.id,
					curr->pc.ip);
			curr = curr->next;
		}
		fclose(fp);
		printf("salvataggio riuscito\n");	
	}
}