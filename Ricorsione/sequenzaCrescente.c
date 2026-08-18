#include <stdio.h>
/* programma che verifica se una sequenza è crescente */
int sequenzaCrescente(int* arr,int l) {
	/* CASO BASE */
	if(l<=1)	//niente piu da controllare
		return 1;
	else {
		if(arr[0]<arr[1])	//se primo elemento minore del secondo
			return sequenzaCrescente(arr+1,l-1);	//PASSO RICORSIVO
		else
			return 0;
	}
}

int main() {
	int l;
	printf("Quanti numeri da inserire? ");
	scanf_s("%d",&l);

	int seq[l];
	for(int i = 0;i<l;i++) {
		printf("Inserisci un numero: ");
		scanf_s("%d",&seq[i]);
	}
	if(sequenzaCrescente(seq,l))
		printf("La sequenza e' crescente!!!\n");
	else
		printf("La sequenza NON e' crescente!!\n");
}