#include<stdio.h>
/*Implementare funzione ricorsica che verifica se 
	all'interno di array, ogni tripla di elementi 
	adiacenti è tale che esattamente due su tre
	sono elementi positivi*/

int esattamenteDue(int* arr,int l) {

	/*CASO BASE*/
	if(l<3)
		return 1;
	/*PASSO RICORSIVO*/
	if((arr[0]>0 && arr[1]>0 && arr[2]<0) ||
		 (arr[0]>0 && arr[1]<0 && arr[2]>0) ||
		 (arr[0]<0 && arr[1]>0 && arr[2]>0))
		return esattamenteDue(arr+1,l-1);

	else
		/*CASO D'INSUCCESSO*/
		return 0;
}


int main() {
	int lung;	//Variabile lunghezza
	printf("Quanti elementi vorresti inserire?\n");
	scanf_s("%d",&lung);

	int arr[lung];
	for(int i = 0; i<lung; i++){
		printf("Inserisci numero: ");
		scanf_s("%d",&arr[i]);
	}
	if(esattamenteDue(arr,lung))
		printf("Ogni tripla ha esattamente due numeri positivi!\n");
	else
		printf("Non tutte le sequenza hanno esattamente due numeri positivi");
}