#include<stdio.h>
#include<stdlib.h>

int* dammiArray() {
	int*sequenza = malloc(10*sizeof(int));
	return sequenza;
}

int main() {
	int* puntatore = malloc(sizeof(int));
	printf("Ecco l'indirizzo di memoria %d\n",puntatore);
	if(puntatore==NULL)
		printf("Mi dispiace memoria vuota!");
	else {
		*puntatore = 2;
		*(puntatore+1) = 6;
		puntatore[2] = 3;

	for(int i = 0;i<3;i++)
		printf("%d ",puntatore[i]);

}
}