#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct esame{
	char nomeEsame[20];
	char professoreNome[20];
	int cfu;
	char obbligatorio;
}Esame;

typedef struct nodo{
	Esame ex;
	struct nodo* next;
}Nodo;

/* Funzione per cancellare primo esame della lista*/
Nodo* cancellaPrimoEsame(Nodo* head){
	Nodo* primoNodo=malloc(sizeof(Nodo));
	/*se lista vuota*/
	if(head==NULL){
		printf("Lista vuota,niente da cancellare.\n\n");
		return head;
	}
	/*se c'è un solo esame*/
	if(head->next==NULL){
		free(head);
		printf("Cancellazione effettuata.\n\n");
		return NULL;
	}
	/*se piu esami*/
	else{
		primoNodo = head->next;
		free(head);
		printf("Cancellazione effettuata.\n\n");
		return primoNodo ;
	}
}

/*Funzione per cancellare l'ultimo esame della lista*/
Nodo* cancellaUltimoEsame(Nodo* head){
	/*se lista vuota*/
	if(head==NULL){
		printf("niente da cancellare\n\n");
		return head;
	}
	/*se un solo esame*/
	if(head->next==NULL){
		free(head);
		printf("Cancellazione effettuata\n\n");
		return NULL;
	}
	Nodo* temp = head;
	Nodo* prev = NULL;
	while(temp->next!=NULL){
		prev = temp;	//aggiorno il precedente
		temp=temp->next; //vai al prossimo
	}
	prev->next = NULL; //prev diventa l'ultimo
	free(temp);
	printf("Cancellazione effettuata\n\n");
	return head;
}

/*Funzione per l'aquisizione dei dati in input*/
void leggiDati(Esame* ex){
	printf("Dammi nome dell'esame: ");
	fgets(ex->nomeEsame,20,stdin);
	(ex->nomeEsame)[strlen(ex->nomeEsame)-1]='\0';

	printf("Dammi nome del prof che tiene l'esame: ");
	fgets(ex->professoreNome,20,stdin);
	(ex->professoreNome)[strlen(ex->professoreNome)-1]='\0';

	printf("Quanti CFU vale l'esame? ");
	scanf("%d%*c", &(ex->cfu));

	printf("E' u esame obbligatorio?(s o n)");
	scanf("%c%*c",&(ex->obbligatorio));	
}
/*Funzione per inserire esame in testa*/
Nodo* InserimentoEsame(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	if(nuovo==NULL){
		printf("Errore di allocazione\n\n");
		return head;
	}

	leggiDati(&(nuovo->ex));

	if(head==NULL){
		nuovo->next=NULL;
		head = nuovo;
		printf("Inserimento effettuato\n\n");
		return head;
	}
	else{
		nuovo->next = head;
		head = nuovo;
		printf("Inserimento effettuato.\n\n");
		return head;
	}

}

/*Funzione per visualizzare la lista*/
void visualizzaLista(Nodo* head){
	/*se lista vuota*/
	if(head==NULL)
		printf("Lista vuota.\n\n");
	else{
		printf("Ecco la lista degli esami:\n\n");
		while(head!=NULL){
			printf("%s\n",head->ex.nomeEsame);
			printf("%s\n",head->ex.professoreNome);
			printf("%d\n",head->ex.cfu);
			if(head->ex.obbligatorio=='s')
			printf("Obbligatrio\n\n");
			else
				printf("A scelta\n\n");
			head=head->next;
		}
		printf("\n");
		printf("Fine lista.\n\n");
	}
}
/*funzione per inserire esame in coda*/
Nodo* esameCoda(Nodo* head){
	Nodo* new = malloc(sizeof(Nodo));
	if(new==NULL){
		printf("Errore d'allocazione memoria\n\n");
		return head;
	}
	leggiDati(&(new->ex));
	/*se lista vuota*/
	if(head==NULL){
		head = new;
		new->next = NULL;
		printf("Inserimento effettuato\n\n");
		return new;
	}
	else{
		Nodo* temp = head;
		/*scorro fino all'ultimo*/
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = new;
		new->next = NULL;
		printf("Inserimento effettuato.\n\n");
		return head;
	}
}
/*funzione che cancella la il primo esame obbligatorio*/
Nodo* cancellaObbligatorio(Nodo* head){
	/*se lista vuota*/
	if(head==NULL){
		printf("Lista vuota, niente da cancellare\n\n");
		return head;
	}

	/*se un'esame unico*/
	if((head->next == NULL)){
		/*se obbligatorio*/
		if(head->ex.obbligatorio == 's'){
			free(head);
			printf("Cancellazione effettuata\n\n");
			return NULL;
		}
		/*se a scelta*/
		else{
			printf("Non ci sono esami obbligatori\n\n");
			return head;
			}
	}
	
	else{
		/*2 o piu esami*/
		Nodo* temp=head;	//Nodo d'appoggio
		Nodo* prev = NULL;	//Nodo d'appoggio per il precedente
		/*scorro  la lista*/
		while(temp->next==NULL){
			/*se obbligatorio cancello*/
			if(temp->ex.obbligatorio=='s'){
			prev->next = temp->next;
			free(temp);	
			printf("Cancellazione effettuata\n\n");
			return head;			
			}
			else
				temp=temp->next;
		}
		printf("Non ci sono esami obbligatori\n\n");
		return head;
	}
}
int main(){ 
	Nodo* head = NULL;
	int scelta = -1;
	while(scelta!=0){
		printf("Premere 1 per visualizzare lista\n");
		printf("Premere 2 per inserire esame in testa\n");
		printf("Premere 5 per inserire esame in coda\n");
		printf("Premere 3 per cancellare ultimo esame\n");
		printf("Premere 4 per cancellare primo esame\n");
		printf("Premere 6 per cancellare primo esame obbligatorio\n");
		printf("Premere 0 per terminare\n");

		scanf_s("%d%*c",&scelta);

		if(scelta==1)
			visualizzaLista(head);

		if(scelta==2)
			head=InserimentoEsame(head);

		if(scelta==3)
			head=cancellaUltimoEsame(head);

		if(scelta==4)
			head = cancellaPrimoEsame(head);

		if(scelta==5)
			head = esameCoda(head);
		if(scelta==6)
			head = cancellaObbligatorio(head);
	}
	FILE* fp = fopen("esami.txt","w");
	if(fp==NULL){
		printf("Apertura file non riuscito\n");
	}
	else{
		Nodo* curr = head;
		while(curr!=NULL){
			fprintf(fp, "%s\n%s\n%d\n%c",
					curr->ex.nomeEsame,
					curr->ex.professoreNome,
					curr->ex.cfu,
					curr->ex.obbligatorio);
			curr= curr->next;
		}
		fclose(fp);
		printf("Salvataggio file riuscito.");
	}
}