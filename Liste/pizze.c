#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct pizza{
	char nomePizza[20];
	float prezzo;
	char veg;
}Pizza;

typedef struct nodo{
	Pizza piz;
	struct nodo* next;
}Nodo;

/*funzione che cancella la prima veg della lista*/
Nodo* cancellaPizza(Nodo* head){
	/*se lista vuota*/
	if(head==NULL){
		printf("Lista vuota, niente da cancellare\n\n");
		return head;
	}
	Nodo* temp = head;
	Nodo* prev = NULL;
	/*se esiste un unico nodo ed è veg*/
	if(temp->next == NULL && temp->piz.veg == 's'){
		free(temp);
		printf("Cancellazione effettuata.\n\n");
		return NULL;
	}
	/*se 2 o piu nodi scorro finche non trovo veg*/
	else{
		while(temp->next != NULL ){		//scorro fino all'ultimo
			if(temp->piz.veg != 's'){ //se pizza nn veg vado avanti
				temp = temp->next;
			}
			else{
				prev->next = temp->next;
				free(temp);
				printf("Cancellazione effettuata.\n\n");
				return head;
			}
		}
	}
}

/*funzione per inserimento in testa della pizza*/
Nodo* inserisciPizza(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	if(nuovo==NULL){
		printf("Errore di allocazione\n\n");
		return head;
	}

	printf("Nome pizza: ");
	scanf_s("%s", &(nuovo->piz.nomePizza),20);
	printf("Prezzo pizza: ");
	scanf_s(" %f%*c", &(nuovo->piz.prezzo));
	printf("E' vegetariana(s per si, n per no): ");
	scanf_s("%c%*c",&(nuovo->piz.veg));

	/*se lista vuota*/
	if(head==NULL){
		nuovo->next = NULL;
		head = nuovo;
		printf("Inserimento effettuato.\n\n");
		return head;
	}
	else{
		nuovo->next=head;
		head = nuovo;
		printf("Inserimento effettuato.\n\n");
	}
	return head;
}


/*funzione per visualizzazione menu*/
void visualizzaMenu(Nodo* head){
	/*se lista vuota*/
	if(head==NULL){
		printf("Menu vuoto.\n\n");
	}
	else{
		printf("Ecco il menu:\n");
		while(head!=NULL){
			printf("Nome: %s\n",head->piz.nomePizza);
			printf("Prezzo: %f\n ",head->piz.prezzo);
			if(head->piz.veg == 's')
				printf("vegetariana\n");
			else
				printf("Non vegetariana\n\n");
			head=head->next;
		}
		printf("Fine lista.\n\n");
	}
}

int main(){
	Nodo* head = NULL;

	FILE* fp=fopen("menuPizza.txt", "r");
	if(fp==NULL){
		printf("File non trovatato parto con lista vuota\n");
	}
	else{
		Pizza p; //Dato da salvare
		while(fscanf(fp,"%s ", p.nomePizza) != EOF){
			fscanf(fp,"%f %c%*c", &(p.prezzo), &(p.veg));
			/*Alloco memoria per nuovo nodo*/
			Nodo* nuovo = malloc(sizeof(Nodo));
			nuovo->piz = p;
			nuovo->next = NULL;
			/*inserimento in coda*/
			if(head==NULL){
				nuovo = head;
			}
			else{
				Nodo* curr = head;
				while(curr->next!=NULL){
					curr = curr->next;
				}
				/*ora è l'ultimo*/
				curr->next = nuovo;
			}
		}
		fclose(fp);

	}
	
	int scelta = -1;
	while(scelta!=0){
		printf("premi 1 per visualizzare la lista\n");
		printf("premi 2 per inserire pizza in testa al menu\n");
		printf("premi 3 per cancellare la prima pizza vegetariana del menu\n");
		printf("premi 0 per terminare\n");

		scanf_s("%d",&scelta);

		if(scelta==1)
			visualizzaMenu(head);
		if(scelta==2)
			head = inserisciPizza(head);
		if(scelta==3)
			head = cancellaPizza(head);
	}
	fp = fopen("menuPizza.txt","w");
	if(fp==NULL){
		printf("apertura file non riuscita\n");
	}
	else{
		Nodo* curr = head;
		while(curr!=NULL){
			fprintf(fp,"%s\n%f\n%c\n\n",
					curr->piz.nomePizza,
					curr->piz.prezzo,
					curr->piz.veg);
			curr=curr->next;
		}
		fclose(fp);
		printf("Salvataggio riuscito.");
	}
}

