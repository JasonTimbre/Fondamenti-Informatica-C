#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Punto {
	float x;
	float y;
}PUNTO;

typedef struct TriangoloEquilatero {
	PUNTO alto;
	float lunghezza;
}TRI;

typedef struct Nodo {
	TRI t;	//il triangolo
	struct Nodo* next;	//per il prossimo nodo
}NODO;


/* Funzione che calcola il perimetro di un triangolo il cui indirizzo è il paramatro*/
	float perimetro(TRI *t) {
	return 3*(t->lunghezza);
}


/* Visualizzazione*/
	void visualizzaTriangolo(TRI *t) {
	printf("Triangolo con perimetro %.2f\n", perimetro(t));
	float altezza = sqrt(3)*t->lunghezza/2;
	printf("Vertice in alto(%.2f,%.2f)\n", t->alto.x, t->alto.x);
	printf("Vertice basso sx(%.2f,%.2f)\n", t->alto.x - t->lunghezza/2);
}

	/* Funzione che fa inserimento ordinato*/

	void leggiDati(TRI *t) {
		printf("Dammi la x del vertice in alto: ");
		scanf_s("%f", &(t->alto).x);	
		printf("Dammi la y del vertice in basso: ");
		scanf_s("%f", &(t->alto).y);	
		printf("Dammi la lunghezza del lato: ");
		scanf_s("%f",&t->lunghezza);
	}

	NODO* inserimento(NODO* head) {
		NODO* nuovo = malloc(sizeof(NODO));
		leggiDati(&(nuovo->t));
		/*inserimento in testa*/
		if(head==NULL || nuovo->t.lunghezza < head->t.lunghezza){
			nuovo->next = head;
			head = nuovo;
		}
		/* inserimento non in testa*/
		else {
			NODO* nodo = head;
			while(nodo->next!= NULL && nodo->next->t.lunghezza <= nuovo->t.lunghezza);
				nodo = nodo->next;

			/* fai i collegamenti */
			nuovo->next = nodo->next;
			nodo->next = nuovo;	
		}
		printf("inserimento effettuato!!\n");
		return head;
	}

	void visualizzaLista(NODO* head) {
	if(head == NULL)
		printf("Lista vuota,niente da visualizzare\n");
	else{
		printf("ecco la lista\n");
		while(head!=NULL){
			visualizzaTriangolo(&(head->t));
			head = head->next;
		}
	}
	printf("Fine della lista\n");
}

	/*funzione di cancellazione per valore*/
	NODO* cancellazione(NODO* head) {
		/*lista vuota*/
		if(head == NULL)
			printf("Lista vuota niente da cancellare");
		else {
			float p;
			printf("che perimetro ha il triangolo da cancellare?\n");
			scanf_s("%f",&p);
			if(perimetro(&(head->t)==p)){
				NODO* dealloca = head;
				head= head->next;
				free(dealloca);
				printf("Cancellazione effettuata!(era in testa)\n");
		}
		/* Cancellazione non in testa*/
			else{
				NODO* nodo = head;

				/*cerca il nodo da cancellare*/
				while(nodo->next!=NULL && perimetro(&(nodo->next->t))!=p)
					nodo = nodo->next;
			}
		/*nodo non trovato*/
			if(NODO->next==NULL) {
				printf("La lista non contiene un triangolo ");
				printf(" perimetro richiesto\n");
			}
			/*nodo trovato*/
			else {
				NODO* dealloca = nodo->next;
				nodo->next = nodo->next->next;
				free(dealloca);
				printf("Nodo con perimetro richiesto cancellato\n");
			}
}
}
	/*Funzione Principale*/
	int main() {
	NODO* head = NULL;
	int scelta = -1;	//per la scelta dell'utente
	while(scelta!=0)
		printf("Caro utente,cosa vuoi fare?\n");
		printf("Digita 1 per visualizzare la lista corrente\n");
		printf("Digita 2 per inserire il triangolo nella lista\n");
		printf("Digita 3per cancellare il triangolo nella lista\n");
		printf("Digita 0 per terminare\n");
		scanf_s("%d",&scelta);
		if(scelta==1)
			visualizzaTriangolo(head);
		if(scelta==2)
			head=inserimento(head);
		
}
