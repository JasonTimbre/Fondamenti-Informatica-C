#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct pasta{
	char tipoPasta[20];
	char aziendaProd[50];
	int tempoCottura;
	char intRaf;
}Pasta;

typedef struct nodo{
	Pasta p;
	struct nodo* next;
}Nodo;

/*funzione per cancellare primo pacco*/
Nodo* cancellaPacco(Nodo* head){
Nodo* primoNodo = malloc(sizeof(Nodo));
	if(primoNodo==NULL){
		printf("errore di allocazione\n\n");
		return head;
	}
	if(head==NULL){
		printf("lista vuota, niente da cancellare\n\n");
		return head;
	}
	/*se un solo elemento*/
	if(head->next == NULL){
		free(head);
		printf("Cancellazione effettuata\n\n");
		return NULL;
	}
	else{
		primoNodo = head->next;//primoNodo diventa la testa
		free(head);	//dealloco la testa
		printf("Cancellazione effettuata\n\n");
		return(primoNodo);	
		}
}	




/*fuznione per acquisire dati in input*/
void leggiDati(Pasta* p){
	printf("Tipo pasta: ");
	fgets(p->tipoPasta,20,stdin);
	(p->tipoPasta)[strlen(p->tipoPasta)-1] = '\0';

	printf("Nome azienda: ");
	fgets(p->aziendaProd, 50, stdin);
	(p->aziendaProd)[strlen(p->aziendaProd)-1] = '\0';	

	printf("Integrale o raffinata(i o r): ");
	scanf_s("%c%*c",&(p->intRaf));

}
/*funzione per stampare pacco di pasta*/
void stampaPacco(Pasta p){
	printf("Tipo pasta: %s\n", p.tipoPasta);
	printf("Aziena produttrice: %s\n", p.aziendaProd);

	if(p.intRaf == 'i'){
		printf("Integrale\n\n");
	}
	if(p.intRaf == 'r'){
		printf("Raffinata\n\n");
	}
}

/*funzione per inserire pacco in coda*/
Nodo* paccoInCoda(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	if(nuovo==NULL){
		printf("allocazione non riuscita\n\n");
		return head;
	}
	leggiDati(&(nuovo->p));
	if(head==NULL){
		nuovo->next = NULL;
		head = nuovo;
		printf("Inserimento effettuato\n\n");
		return head;
	}
	else{
		Nodo* curr = head;	//puntatore d'appoggio
		/*scorro la lista*/
		while(curr->next!=NULL){
			curr=curr->next;
		}
		/*ora sono all'ultimo nodo*/
		curr->next = nuovo;
		nuovo->next = NULL;
		printf("Inserimento effettuato\n\n");
		return head;
	}
}
/*funzione per visualizzare la lista*/
void visualizzaPacco(Nodo* head){
	/*se lista vuota*/
	if(head==NULL){
		printf("Lista vuota, niente da visualizzare\n\n");
	}
	else{
		printf("Ecco l'elenco dei pacchi di pasta:\n\n");
		while(head!=NULL){
			stampaPacco(head->p);
			head = head->next;
		}
		printf("\n\nFine Lista\n\n");
	}
}

int main(){
	Nodo* head = NULL;
	FILE* fp = fopen("pasta.txt", "r");
	if(fp==NULL){
		printf("iniziamo con lista vuota\n");
	}
	Pasta p;
	while(fscanf(fp,"%s",p.tipoPasta) != EOF){
		fscanf(fp,"%s%d%*c%c%*c",&(p.aziendaProd),
				&(p.tempoCottura),
				&(p.intRaf));
		head =paccoInCoda(head); 
	}
	fclose(fp);
	int scelta =-1;
	while(scelta!=0){
		printf("1 per visualizzare elenco\n");
		printf("2 per inserire pacco in coda alla lista\n");
		printf("3 per cancellare primo pacco dell'elenco\n ");
		printf("0 per terminare e salvare\n\n");
		scanf_s("%d%*c",&scelta);

		if(scelta==1)
			visualizzaPacco(head);
		if(scelta==2)
			head = paccoInCoda(head);
		if(scelta==3)
			head = cancellaPacco(head);
	}
	fp =fopen("pasta.txt","w");
	Nodo* curr = head;
	while(curr!=NULL){
		fprintf(fp,"Tipo pasta:%s, Azienda prod:%s, tempoCottura: %d,%c",
				curr->p.tipoPasta,
				curr->p.aziendaProd,
				curr->p.tempoCottura,
				curr->p.intRaf);
		curr = curr->next;
	}
	fclose(fp);
printf("Salvataggio riuscito\n");
}