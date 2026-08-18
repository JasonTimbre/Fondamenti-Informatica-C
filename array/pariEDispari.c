#include<stdio.h>
/*Funzione che controlla se  ogni tripla di interi contiene
 un intero pari e uno dispari */

int pariEDispari(int* arr,int l) {
	int i;	//var contatore
	int contiene = 0;	//risultato
		/* scorro la le sequenza */
	for(i = 0; i<l-2; i++) {
		/* Se contiene sia pari che dispari*/
		if((arr[i] % 2 == 0 && arr[i+1] % 2 == 1) ||S 
			(arr[i] % 2 == 0 && arr[i+2] % 2 == 1)||
			(arr[i+1] % 2 == 0 && arr[i+2] % 2 == 1)){
			contiene = 1;
			i++;
		}
		else
			contiene = 0;
		}
		return contiene;
	}


int main() {
	int lung;
	printf("quanti interi inserisci?\n");
	scanf_s("%d", &lung);
	int seq[lung];
	for(int i = 0;i<lung;i++) {
		printf("Inserisci un intero ");
		scanf_s("%d",&seq[i]);
	}

	if(pariEDispari(seq,lung))
		printf("Tutte le triple contengono almeno un pari e un dispari!!\n");
	else
		printf("Esiste almeno una tripla che NON contiene sia uin pari che un dispari!!");

}

