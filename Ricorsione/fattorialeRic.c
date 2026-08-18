#include<stdio.h>

int recFatt (int n) {
	int fatt;
	if(n>1)
		fatt=n*recFatt(n-1);
	else
		fatt=1;
	return fatt;
}

int main() {
	int numero;
	printf("Dammi un numero e ti restituisco il suo fattoiale : \n");
	scanf_s("%d", &numero);
	printf("Il fattoriale del tuo numero e': %d", recFatt(numero));

}