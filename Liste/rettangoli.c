#include <stdio.h>
#include<stdlib.h>
typedef struct Vertici {
	float x;
	float y;
}VERT;

typedef struct Rettangolo {
	VERT bs;
	VERT ad;
}RETT;

typedef struct Nodo {
	RETT r;
	struct Nodo* next;
}NODO;

/* Legge i dati */
void leggiDati(RETT* r) {
	printf("dammi la ccordinata x del vertice in basso a sinistra: ");
	scanf_s("%f",&(r->bs.x));
	printf("dammi la ccordinata y del vertice in alto a destra: ");
	scanf_s("%f",&(r->ad.y));	
	float latoH,LatoV;
	do {
	printf("dammi la lunghezza del lato orrizzontale: ");
	scanf_s("%f",&LatoH);
	}
	while(latoH<=0){

	printf("dammi la lunghezza del lato verticale: ");
	scanf_s("%f",&latoV);
	r->ad.x = rr->bs.x+latoH;
	r->ad.y = rr->bs.y+latoV;
	}
}

/* funzione di inserimento */
void inserimentoTesta(NODO* head) {
	NODO* nuovo = malloc(sizeof(NODO));
	leggiDati(&(nuovo->r));
	nuovo->next = head->next;
	head->next = nuovo;
}
/* salvataggio su file */
void salvataggioSuFile(NODO* head) {
	FILE* fp = open("Rettangolo.txt","w");
	if(fp==NULL)
		printf("Salvataggio su file non riuscito.\n\n");
	else {
		if(head==NULL)
			printf("Lista vuota,nienete da salvare\n\n");
		while(head!=NULL)
			fprintf(fp,"%f %f %f %f\n",head->r.bs.x, head->r.bs.y ,head->r.ad.x, head->r.ad.y);
		head = head->next;
	}
	fclose(fp);

	/* Lettura da file */
	void letturaDaFile(NODO* head) {
		FILE* fp = fopen(Rettangolo,"txt","r");
		if(fp==NULL)
			printf("Recupero rettangoli file non riuscita\n\n");
		else {
			RETT ret;
			while(fscanf(fp,"%f%f%f%f",&(ret.bs.x),&(ret.bs.y),&(ret.ad.x),&(ret.ad.y))) {
			NODO* nuovo = malloc(sizeof(NODO));
			nuovo->r = ret;
			head->next = nuovo;
			head = head->next;			}
			}
			head->next = NULL;
			printf("Lista recuperata da file\n\n";)
	}

}
int main() {

	NODO* head = malloc(sizeof(NODO));
	head->next = NULL;
	letturaDaFile(head);
	int scelta = -1;	//per la scelta dell'utente

	while(scelta!=0){

		printf("Caro utente,cosa vuoi fare?\n");
		printf("Digita 1 per visualizzare la lista corrente\n");
		printf("Digita 2 per inserire il triangolo nella lista\n");
		printf("Digita 3per cancellare il triangolo nella lista\n");
		printf("Digita 0 per terminare\n");
		scanf_s("%d",&scelta);
		if(scelta==1)
			inserimentoTesta(head);
	}
	/* Salvataggio su file */

	salvataggioSuFile(head->next);
		
}