#include<stdio.h>
int main() {
	int lunghezza;
	printf("Caro Utente, inserisci dieci numeri: \n");
	scanf_s("%d",&lunghezza);
	int seq[lunghezza];
	for(int i = 0;i<lunghezza;i++)
	printf("%d", seq[i]);
}