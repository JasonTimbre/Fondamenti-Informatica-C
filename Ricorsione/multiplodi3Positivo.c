#include<stdio.h>

/* Programma che prende in input una sequenza 
e verifica se nella sequenza esiste un intero 
positivo e mutiplo di 3 */
int multiploEPositivo(int* arr,int l) {
	/*CASO BASE*/
	if(l==0)	//niente piu da controllare
		return 0;
	else {
	/* PASSO RICORSIVO */
	if(arr[0]>0 && arr[0]%3==0)	//se trova multiplo di 3 e >0
		return 1;
	else
		return multiploEPositivo(arr+1,l-1);//richiama se stessa
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
	if(multiploEPositivo(seq,l))
		printf("Esiste un numero positivo e multiplo di tre!!\n");
	else
		printf("NON Esiste un numero positivo e multiplo di tre!!");

}