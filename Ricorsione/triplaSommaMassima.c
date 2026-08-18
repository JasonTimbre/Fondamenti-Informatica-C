#include<stdio.h>
/* Scrivere un programma che prende in input
 una sequenza di interi e 
calcola la massima somma di tre interi
 adiacenti nella sequenza */
int triplaMassimaSomma(int* arr,int l) {
	/* CASO BASE */
	if(l==3) {
		return arr[0] + arr[1] + arr[2];
	}
	/* PASSO RICORSIVO */
	else {
		int sommaMax = arr[0] + arr[1] + arr[2];//assegno valore alla somma
		int sommaTemp = triplaMassimaSomma(arr+1,l-1); //chiamata ricorsiva 1235
		
		if(sommaMax>sommaTemp)
			return sommaMax;
		else
			return sommaTemp;
		}
}
int main() {
	int l;	//lunghezza
	printf("Quanti interi da inserire? ");
	scanf_s("%d",&l);
	int seq[l];
	for(int i = 0;i<l;i++) {
		printf("Inserisci un un numero: ");
		scanf_s("%d",&seq[i]);
	}
	int somma = triplaMassimaSomma(seq,l);
	printf("La somma massima delle triple e':%d",somma);
}
