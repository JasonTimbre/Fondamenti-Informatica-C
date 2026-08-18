#include <stdio.h>

//funzione per il calcolo del fattoriale di un numero

int recFatt(int n){
	//pre: n>1=
	int fatt = 1;
	int i = 1;
	while(i<=n) {
		fatt=fatt*i;
		i++;
	}
	return fatt;
}

/*programma per il calcolo del fattoriale di un numero*/

int main() {
	int numero;
	printf("Io calcolo fattoriali. Di che numero vuoi il fattoriale?\n");
	scanf_s("%d",&numero);
	printf("il fattoriale vale %d",recFatt(numero));
}

