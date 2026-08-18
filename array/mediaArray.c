#include<stdio.h>


float mediaArray(int* arr,int l) {
	float media;// risultato
	int somma = 0;	//variabile accumulazione
	int totale = 0;	//quantità della sequenza
	for(int i = 0;i<l;i++) {
		somma+=arr[i];
		totale++;
	}
	media = (float)somma/totale; // casting esplicito per la conversione
	return media;
}

int main() {
	int lung;	//lunghezza array
	printf("Caro Utente quanti interi vuoi inserire?\n");
	scanf_s("%d", &lung);
		/* INPUT */
	 int seq[lung];
	 for(int i = 0;i<lung;i++) {
	 	printf("Inserisci un numero \n");
	 	scanf_s("%d", &seq[i]);
	 }

	 	/* OUTPUT */
	 float media = mediaArray(seq,lung);
	 printf("La media dei numeri inseriti e' : %f", media);
}