#include <stdio.h>
int main(){
	/*Realizzare un programma Moltiplicatore 
	che legge due numeri reali introdotti dall'utente
	 e stampa sullo schermo dell'utente un numero reale pari al prodotto dei due numeri reali letti. */
	int n ; 
	int m ;
	printf("inserisci 2 numeri e li moltiplichero'\n");
	scanf_s("%d", &n);
	scanf_s("%d",&m);
	int prodotto = n * m;
	printf("%d", prodotto);

}