#include<stdio.h>
/* Programma che restituisce il numero di valori positivi in una sequenza */

/* Funzione che acquisisce due array e salva su uno solo i positivi dell'altro*/
void numeriPositivi(int* arr1,int* arr2,int lung) {
	int i = 0;
	int j = 0;
	/*scorro sequenza*/
	for(i = j;i<lung;i++) {
		/*se valore positivo*/
		if(arr1[i]>0) {
			arr2[j] = arr1[i];
			j++;
		}
	}
}
	int numeriPositiviRicorsivo(int*arr1,int i,int lung) {
		if(i == lung)
			return 0;
		else {
			return 1 + numeriPositiviRicorsivo(lung -1)
		}

	}


	/* Programma Principale */
int main() {
	int lung;	//lunghezza array
	printf("Caro Utente, quanti interi vuoi inserire: ");
	scanf_s("%d",&lung);
	/* INPUT */
	int seq1[lung];
	int seq2[lung];
	for(int i = 0;i<lung;i++) {
		printf("Inserisci un numero ");
		scanf_s("%d",&seq1[i]);			
	}

	/* OUTPUT */
	numeriPositivi(seq1,seq2,lung);
	printf("La sequenza con solo interi positivi e' la seguente: \n");
	for(int j = 0; j<lung;j++)
		printf("%d ",seq2[j]);
}