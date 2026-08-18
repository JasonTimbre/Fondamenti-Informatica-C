#include<stdio.h>
/* Conta quanti numeri pari ci sono in un array*/

int quantiPari(int* arr,int l) {
	int accumula=0;	//var accumulatore
	for(int i = 0;i<l;i++){
		if(arr[i]%2==0)
			accumula++;
	}
	return accumula;
}

int main() {
	int l;
	printf("Quanti interi devi inserire?\n");
	scanf_s("%d", &l);

	/* INPUT */
	int seq[l];
	for(int i = 0;i<l;i++){
		printf("Inserisci un numero ");
		scanf_s("%d",&seq[i]);
	}

	/* OUTPUT */

	int pari =quantiPari(seq,l);
	printf("la sequenza contiene %d numeri pari", pari); 

}

