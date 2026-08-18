#include<stdio.h>

/* Scrivere un programma che prende in input
 una sequenza di interi e verifica se nella sequenza
  ogni tripla di interi adiacenti è composta da interi
  tutti diversi fra loro.*/
int tripleTuttiDiversi(int* arr,int l) {
	/* CASO BASE */
	if(l==3) {
		return 1;
	}
	else {
		if(arr[0]!=arr[1] && arr[1]!=arr[2] &&
			arr[0]!=arr[2])
			return tripleTuttiDiversi(arr+1,l-1);
		else
			return 0;
	}
}

int main() {
	int l;	//lunghezza
	printf("Quanti interi da inserire ?: ");
	scanf_s("%d",&l);
	int seq[l];
	for(int i = 0;i<l;i++) {
		printf("Inserisci intero: ");
		scanf_s("%d",&seq[i]);
	}
	if(tripleTuttiDiversi(seq,l))
		printf("Istanza positiva!!");
	else
		printf("Istanza negativa!!");
}