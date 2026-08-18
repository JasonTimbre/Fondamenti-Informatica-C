#include<stdio.h>
/* Scrivere un programma che prende in input una sequenza 
di interi e verifica se nella sequenza esiste un elemento 
che è pari al quadrato del precedente o del successivo.*/

int quadratoIntorno(int* arr,int l) {
	/* CASO BASE*/
	if(l==3 && !(arr[1]==arr[0]*arr[0] || arr[1]==arr[2]*arr[2]))
		return 0;
	else {
		if(arr[1]==arr[0]*arr[0] || arr[1]==arr[2]*arr[2])
			return 1;
		else
			return quadratoIntorno(arr+1,l-1);
	}
}

int main() {
	int l;
	printf("quanti elementi:\n");
	scanf_s("%d",&l);
	int arr[l];
	for (int i = 0; i < l; ++i) {
		printf("Inserisci Numero\n");
		scanf_s("%d",&arr[i]);
	}
	if(quadratoIntorno(arr,l))
		printf("Esiste almeno un elemento che ha un quadrato prima o dopo!!");
	else
		printf("NON esiste nessun un elemento che ha un quadrato prima o dopo!!");
}