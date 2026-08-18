#include <stdio.h>

/* Funzione che conta quante
 coppie uguali ci sono in una sequenza*/
/*Problema di conteggio*/
/*SPECIFICHE: INPUT: array e dimensione, PRE: dimensione>=0, OUTPUT: intero >=0, POST: n coppie adiacenti uguali*/
int numeroCoppieUguali(int* arr, int lung) {
	/*CASO BASE*/
	if(lung<2)
		return 0;
	/*PASSO RICORSIVO*/
	else {
		if(arr[0] == arr[1])
			return 1 + numeroCoppieUguali(arr+1, lung-1);
		else
			return 0 + numeroCoppieUguali(arr+1, lung-1);
	}
}


int main() {
	int l;	//per la lunghezza
	printf("Quanti interi vuoi introdurre?: ");
	scanf_s("%d",&l);
	int arr[l];
	for(int i = 0; i<l; i++) {
		printf("Inserisci numero: ");
		scanf_s("%d",&arr[i]);
	}
	int n = numeroCoppieUguali(arr,l);
	printf("La sequenza ha %d coppie uguali.",n);

	FILE* fp = fopen("sequenza.txt","w");
	if(fp==NULL)
		printf("apertura file non riuscito\n");
	else{
		for(int j = 0; j<l; j++)
			fprintf(fp, "%d ",arr[j]);
		
		fclose(fp);
		printf("salvataggio riuscito\n");
	}
	}