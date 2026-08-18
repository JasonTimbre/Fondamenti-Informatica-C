#include <stdio.h>
int  main(){

	/* Realizzare un programma 
	Duplicatore che legge un intero introdotto dall'utente 
	e stampa sullo schermo dell'utente un intero pari al doppio dell'intero letto. */
	int n ;

	printf("inserisci un numero\n");
	scanf_s("%d",&n);

	int m = n*2;
	printf("%d",m);
	
}