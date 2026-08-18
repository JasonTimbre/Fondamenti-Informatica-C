#include <stdio.h>	
/*SEGNO
Scrivere un'applicazione Segno che chiede all'utente di 
inserire un intero da tastiera, lo legge e stampa un 
messaggio che dice all'utente se l'intero è positivo,
 negativo o nullo.*/


int main(){
	int numero;
	printf("Caro utente inserisci un numero e ti diro' se e' positivo o negativo\n");
	scanf_s("%d",&numero);

	if (numero>0)
		printf("il numero e' positivo!!");
	else if(numero==0)
		printf("il numero e' zero!!");
	else
		printf("il numero e' negativo!!");


}