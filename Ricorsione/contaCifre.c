#include<stdio.h>
/*Scrivere un programma che dato in input un numero
  intero positivo n restituisce in output il numero di
  cifre di cui è composto.
  Definire una funzione ricorsiva per tale conteggio.*/

int contaCifreRic (int n) {
	/* Caso Base*/
	if(n<10)
		return 1;
	/* Passo Ricorsivo */
	else
	return 1 + contaCifreRic(n/10);

}

int contaCifreIte(int n) {
	int i = 0;	//contatore
	while(n>0) {
		n = n/10;
		i++;
	}
	return i;
}
int main() {
	int number;
	printf("Dammi un numero e ti conto quante cifre contiene: ");
	scanf_s("%d", &number);
	int cifra = contaCifreRic(number);
	printf("Il numero che hai inserito contiene %d cifre\n", cifra);
	cifra = contaCifreIte(number);
	printf("Il numero che hai inserito contiene %d cifre", cifra);

}