#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct libro{
	char nomeLibro[20];
	char nomeAutore[20];
	int numeroPagine;
	char primaEdizione;
}Libro;

typedef struct nodo{
	Libro l;
	struct nodo* next;
}Nodo;
/*funzione p{er stampa di dati*/
void leggiDati(Libro l){
	printf("Nome Libro:%s\n",l.nomeLibro);
	printf("Nome autore:%s\n", l.nomeAutore);
	printf("Numero pagine:%d\n", l.numeroPagine);
	if(l.primaEdizione == 's')
		printf("Prima edizione\n\n");
	if(l.primaEdizione == 'n')
		printf("Ristampa\n\n");
}

/*funzione che legge i dati*/
void prendiLibro(Libro* l){
	printf("Nome del libro: ");
	fgets(l->nomeLibro,20,stdin);
	(l->nomeLibro)[strlen(l->nomeLibro)-1]='\0';

	printf("\nNome dell'autore: ");
	fgets(l->nomeAutore,20,stdin);
	(l->nomeAutore)[strlen(l->nomeAutore)-1]='\0';

	printf("\nQuante pagine: ");
	scanf_s("%d%*c",&(l->numeroPagine));


	printf("\nPrima edizione ?(s o n): ");
	scanf_s("%c%*c",&(l->primaEdizione));
}

/*funzione che inserisce libro in coda all'elenco*/
Nodo* inserimentoCoda(Nodo* head){
Nodo* nuovo = malloc(sizeof(Nodo));
	if(nuovo==NULL){
		printf("Errore di allocazione\n\n");
		return head;
		}
		prendiLibro(&(nuovo->l));
	/*se lista vuota*/
	if(head==NULL){
		head = nuovo;
		nuovo->next = NULL;
		printf("Inserimento effettuato\n\n");
		return head;
	}
	else{
		Nodo* curr=head;
		/*scorro la lista*/
		while(curr->next!=NULL){
			curr=curr->next;
		}
		/*arrivato all'ultimo*/
		curr->next=nuovo;	//punto l'ulitmo al nodo nuovo
		nuovo->next =NULL;//aggiorno nuovo ulitmo nodo
		printf("Inserimento effettuato\n\n");
		return head;
	}
}

/*funzione per visualizzazione*/
void visualizzaLista(Nodo* head){
	if(head==NULL){
		printf("Lista vuota\n\n");
	}
	else{
		printf("Ecco l'elenco dei libri:\n\n");
		while(head!=NULL){
			leggiDati(head->l);
			head=head->next;
		}
		printf("Fine Lista\n\n");
	}
}

/*funzione che cancella il primo libro dall'elenco*/
Nodo* cancellaPrimo(Nodo* head){
	Nodo* primoNodo = malloc(sizeof(Nodo));
	if(head==NULL){
		printf("Lista vuota, niente da cancellare\n\n");
		return head;
	}
	else{
		/*se unico nodo*/
		if(head->next==NULL){
			free(head);
			printf("Cancellazione effettuata\n\n");
			return NULL;
		}
		/*piu di un nodo*/
		else{
			/*sgancio il nodo*/
			Nodo* temp = head;
			free(temp);
			printf("Cancellazione effettuata\n\n");
			return head;
		}
	}
}

int main(){
	Nodo* head =NULL;
	int scelta=-1;

	    FILE* fp = fopen("elenco_libri.txt", "r");
    if(fp != NULL){
        Libro temp;
        while(fscanf(fp, "%19s %19s %d %c",
                     temp.nomeLibro,
                     temp.nomeAutore,
                     &temp.numeroPagine,
                     &temp.primaEdizione) == 4)
        {
            Nodo* nuovo = malloc(sizeof(Nodo));
            nuovo->l = temp;
            nuovo->next = NULL;

            if(head == NULL){
                head = nuovo;
            } else {
                Nodo* curr = head;
                while(curr->next != NULL)
                    curr = curr->next;
            	}
                curr->next = nuovo;
        }
        fclose(fp);
    }

	while(scelta!=-2){
		printf("Premere 1 per visualizzare l'elenco\n");
		printf("Premere 2 per inserire libro in coda all'elenco\n");
		printf("Premere 3 per cancellare il primo libro dall'elenco\n");
		printf("Premere 0 per salvare e terminare\n");

		scanf_s("%d%*c",&scelta);

		if(scelta==1)
			visualizzaLista(head);
		if(scelta==2)
			head=inserimentoCoda(head);
		if(scelta==3)
			head=cancellaPrimo(head);
		if(scelta==0){
			FILE*fp =fopen("elenco libri.txt","w");
			if(fp == NULL){
				printf("Errore apertura file\n");
			} 
			else{
				Nodo* curr = head;
				while(curr!=NULL){
					fprintf(fp,"%s %s %d %c\n",
						curr->l.nomeLibro,
						curr->l.nomeAutore,
						curr->l.numeroPagine,
						curr->l.primaEdizione);
					curr=curr->next;
				}
				fclose(fp);
				printf("Dati salvati correttamente\n");
			}
		}
	}
}
