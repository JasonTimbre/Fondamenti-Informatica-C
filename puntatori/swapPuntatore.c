#include<stdio.h>

	/* Funzione che scambia i valori di due variabili usando i puntatori */
void swap(int* a,int* b) {
	int temp =*a;
	*a=*b;
	*b=temp;
}

int main() {
	/*prima si inizializza la variabile e poi si assegna il puntatore alla variabile */

	int x = 2;
	int* p = &x;
	printf("%p\n",p);		//%p per la stampa di puntatori(indirizzo di memoria della variabile puntata)

	int y = 3;
	int* p2 = &y;
	swap(&x,&y);
	printf("%d, %d",x,y);
}