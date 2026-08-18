#include<stdio.h>
#include<stdlib.h>

/* programma che calcola la distanza del valore tra due inter 
consecutivi di una sequenza e restituisce il minimo 
di tutti i valori*/

int distanzaMinima(int* arr,int l) {

	/* caso base*/
	if(l==2)	//ci sono solo 2 elementi quindi sara la distanza minima
		return abs(arr[0]-arr[1]);
	
	int dist1 = abs(arr[0]-arr[1]);
	int dist2 = distanzaMinima(arr+1,l-1);
	if(dist1<dist2)
		return dist1;
	else
		return dist2;
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
		int minimo  = distanzaMinima(seq,l);
		printf("La distanza minima della sequenza e' : %d",minimo);
	
}