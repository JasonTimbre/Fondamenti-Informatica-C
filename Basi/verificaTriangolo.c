/*Copia e incolla il seguente codice in un file verificaTriangolo.c
int n1, n2, n3;
printf("Introduci il valore di n1, n2 ed n3: ");
scanf("%d%d%d", &n1, &n2, &n3);
printf("I tre numeri rappresentano i lati di un triangolo: (1) = SI, (0)
= NO --> %d", ...);
Al posto dei puntini scrivi un'espressione booleana che vale vero (1) se i n1, n2 ed n3 possono
essere i lati di un triangolo, falso (0) altrimenti.
Tre numeri rappresentano le misure dei lati di un triangolo se ogni coppia di numeri ha una somma
maggiore del terzo numero.
Ad esempio, i valori n1=2, n2=8 e n3=4 non possono rappresentare le misure dei lati di un
triangolo.*/
#include <stdio.h>

int main(){

	int n1,n2,n3 ;

	printf("introduci il valore di n1,n2 ed n3:\n");
	scanf_s("%d%d%d",&n1,&n2,&n3);
	printf("I tre numeri rappresentano i lati di un triangolo:\n""%d",n1 + n2 > n3 && n1 + n3 > n2 && n2 + n3 > n1);



}