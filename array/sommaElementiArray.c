#include<stdio.h>
/* Applicazione che Somma elemento per elemento due array
 della stessa lunghezza.*/
/*funzione che stampa la somma di due array*/
void sommaElementi(int* a,int* b,int* c,int l) {
	for(int i = 0;i<l;i++)
		c[i]=a[i]+b[i];
	for (int i = 0; i < l; ++i)
		printf("%d", c[i]);	
}
//Siccome una funzione non puo restituire un array come valore 
//gli passo un'array vuoto alla funzione void 
//e la funzione me la stampa e basta =)
int main() {
	int l;	//lunghezza
	printf("Quanti numeri vuoi inserire? ");
	scanf_s("%d",&l);

		/* INPUT*/
	//primo array
	int seq1[l];
	for(int i = 0;i<l;i++) {
		printf("Inserisci un numero ");
		scanf_s("%d",&seq1[i]);
	}
	printf("Vai con la seconda sequenza\n");
	//secondo array
	int seq2[l];
	for(int i = 0;i<l;i++) {
		printf("Inserisci un numero ");
		scanf_s("%d",&seq2[i]);
	}
	//array da riempire per somma
	int seq3[l];
	
		/* OUTPUT */
	sommaElementi(seq1,seq2,seq3,l);
	
}