/*Scrivere un'applicazione SommaNInteri 
che chiede all'utente di inserire un 
intero n e poi di inserire n interi di cui
 l'applicazione stampa la somma.*/
#include <stdio.h>
int main(){
int n;  // var input
int quant; // var quantita n da sommare
int i; // var contatore 

printf("Caro utente, Inserisci un numero\n");
scanf_s("%d",&n);
printf("Quanti altri numeri vuoi sommarci?\n");
scanf_s("%d",&quant);

int somma=0; // var somma
for(i=1;i<=quant;i++){
	printf("inserisci l'altro numero\n");
	scanf_s("%d",&n);
	somma += n;
}
	printf("%d\n",somma);
}