#include<stdio.h>
#include <stdlib.h>

typedef struct date{
	int giorno;
	int mese;
	int anno;
}data;

typedef struct nodo{
	data d;
	struct nodo* next;
}Nodo;

/*finzione per acquisire dati*/
void leggiDati(data* d){
	printf("Dimmi giorno: ");
	scanf_s("%d",&(d->giorno));

	printf("Dimmi mese: ");
	scanf_s("%d",&(d->mese));

	printf("Dimmi giorno: ");
	scanf_s("%d",&(d->anno));
}
/*funzione che cancella prima data dell'elenco*/
Nodo* cancellaData(Nodo* head){
	Nodo* primoNodo=malloc(sizeof(Nodo));
	if(head==NULL){
		printf("Lista vuota,niente da cancellare\n\n");
		return head;
	}
	else{
		primoNodo = head->next;
		free(head);
		printf("Cancellazione effettuata\n\n");
		return primoNodo;
	}

}

/*funzione per inserire date in ordine crescente*/
Nodo* inserimentoData(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	if(nuovo==NULL){
		printf("Errore d'allocazione memoria\n\n");
		return head;
	}
	leggiDati(&(nuovo->d));
	/*se lista vuota*/
	if(head==NULL){
		head  = nuovo;
		head->next = NULL;
		printf("Inserimento effettuato\n\n");
		return head;
	}
	else{
		nuovo->next = head;
		printf("Inserimento effettuato\n\n");
		return nuovo;
		}
}

/*funzione stampa date*/
void stampaData(data d){
	printf("%d/",d.giorno);
	printf("%d/",d.mese);
	printf("%d\n\n",d.anno);
}

/*funzione per visualizzare elenco date*/
void visualizzaData(Nodo* head){
	if(head==NULL){
		printf("Lista vuota\n\n");
	}
	else{
		printf("Ecco l'elenco:\n\n");
		while(head!=NULL){
			stampaData(head->d);
			head = head->next;
		}
		printf("Fine lista\n\n");
	}
}
int main(){
	Nodo* head = NULL;
	int scelta=-1;
	FILE* fp=fopen("date.txt","r");
	if(fp!=NULL){
		data temp;
		while(fscanf(fp,"%d %d %d",
			&temp.giorno,
			&temp.mese,
			&temp.anno) == 3){
	
			Nodo* nuovo = malloc(sizeof(Nodo));
			nuovo->d = temp;
			nuovo->next = NULL;
		
			if(head == NULL){
			head = nuovo;
			}
			else{
				Nodo* curr = head;
				while(curr->next!=NULL){
					curr = curr->next;
					curr->next = nuovo;
					}		
				}
		}			
		fclose(fp);
	}

	while(scelta!=0){
		printf("1 per visualizzare\n");
		printf("2 per inserire data mantenendo ordine crescente\n");
		printf("3 per cancellare prima datra dell'elenco\n");
		printf("0 per terminare e salvare\n");
		scanf_s("%d",&scelta);
		if(scelta== 1)
			visualizzaData(head);
		if(scelta==2)
			head=inserimentoData(head);
		if(scelta==3)
			head=cancellaData(head);
	}
	fp = fopen("date.txt","w");
	if(fp==NULL){
		printf("Errore apertura file\n");
	}
	else{
		Nodo* curr = head;
		while(curr!=NULL){
			fprintf(fp,"%d/%d/%d\n",
				curr->d.giorno,
				curr->d.mese,
				curr->d.anno);
			curr = curr->next;
		}
		fclose(fp);
		printf("Dati salvati correttamente.");
	}
}