#include<stdio.h>

/* programma che effettua la ricerca 
binaria in un array ordinato*/
int ricercaBinaria(int* arr,int des,int sin,int x) {
	/* CASO BASE */
	if(x==des || x==sin) 
		return 1;
	/* PASSO RICORSIVO */
	else {
		int cen = (des+sin)/2
		if(arr[cen]<=x)
			return ricercaBinaria(arr,0,l-1,x)


	}
}1,2,3,4,5 (1)
int main() {
	int l;
	int scelta;
	printf("Quanti elementi: \n");
	scanf_s("%d", &l);
	int arr[l];
	printf("Inserisci la sequenza ordinata!!\n");
	for(int i = 0 ;i<l; i++) {
		printf("Inserisci numero: \n");
		scanf_s("%d",arr[i]);
	}
	printf("Inserisci il numero che vuoi cercare: \n");
	scanf_s("%d",scelta);
	if(ricercaBinaria(arr,0,l-1,scelta));
		printf("Il numero cercato e' presente!!\n");
	else
		printf("Il numero cercato NON e' presente!\n");
}