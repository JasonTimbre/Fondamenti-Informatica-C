/*Scrivere un'applicazione DispariFinoAN che chiede all'utente
 di inserire un intero positivo da tastiera e stampa
 tutti gli interi dispari minori o uguali dell'intero letto.*/

#include <stdio.h>
int main(){

int n;  //var input
int i; //var contatore

printf("Caro Utente inserisci un numero\n");

scanf_s("%d",&n);

for(i=1;i<=n;i++)
	if(i % 2 !=0)
		printf("%d ",i);




}