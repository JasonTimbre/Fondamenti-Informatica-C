#include<stdio.h>
/*imuovi tutte le occorrenze
 di un valore da un array (shift a sinistra).*/

void versoSinistra(int* arr,int l) {
	for(int i = 0;i<l;i++) {
		//se diverso dal successivo
		if(arr[i]!=arr[i+1])
			//vai avanti

	}
}

int main() {
	int l;	//lunghezza
	printf("Quanti interi vuoi introdurre? ");
	scanf_s("%d", &l);

		/* INPUT */
	int seq[l];
	for(int i = 0;i<l;i++) {
		printf("Inserisci numero: ");
		scanf_s("%d",&seq[i]);
	}
		/* OUTPUT*/
	versoSinistra(seq,l);
}
