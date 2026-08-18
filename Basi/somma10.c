/*Scrivere un'applicazione Somma10Interi che chiede
 all'utente di inserire 10 interi di cui l'applicazione 
 stampa la somma.*/
#include <stdio.h>
int main(){

int n;  //var input
int i; //var contatore
int somma=0; //var somma
printf("Caro Utente inserisci 10 numeri\n");
for(i=1;i<=10;i++){
	printf("inserisci il %d numero\n",i);
	scanf_s("%d",&n);
	somma+=n;

}
printf("la somma dei numeri inseriti e' %d",somma);



}