#include<stdio.h>
	/* Funzione che determina qual
		 è il massimo valore di un array */
int massimoElementiArray(int* arr,l) {
	int massimo;
	int temp;
	for(int i = 0;i<l;i++) {
		if(arr[i]>arr[i+1]) {
			temp = arr[i];
			massimo = temp;
		}
		
	}
}
2,1,3
/* Funzione principale */
int main () {
	int l;
	printf("Quanti elementi da introdurre? ");
	scanf_s("%d",&l);
	int arr[l];
	int massimo = masssimoElementiArray(arr,l);
}