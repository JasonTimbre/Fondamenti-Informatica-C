#include<stdio.h>

/* Programma che prende in input una sequenza
	di interi e determina se ogni tre elementi 
	consecutivi sono tali che uno è pari alla somma 
	degli altri due attravarso una funzione ricorsivo*/

int sommaTriple (int* arr,int l) {
	/* CASO BASE */	// se ho 3 elemnti e sono un'istanza postiva
	if(l==3) {	
		if( arr[0] == arr[1]+arr[2] ||
			arr[1] == arr[0]+arr[2] ||
			arr[2] == arr[0]+arr[1])		
		return 1;
		else
			return 0;

	}
	/* PASSO RICORSIVO */
	if(arr[0] == arr[1]+arr[2] ||
		arr[1] == arr[0]+arr[2] ||
		arr[2] == arr[0]+arr[1])
		return sommaTriple(arr+1,l-1);
	else
		return 0;
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
if(sommaTriple(seq,l))
	printf("Istanza Positiva!!");
else
	printf("Istanza Negativa!!");
}