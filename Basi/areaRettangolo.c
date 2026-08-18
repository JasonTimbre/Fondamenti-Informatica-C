
	/* Programma che calcola l'area di un rettangolo 
	dati base e altezza in input */
#include<stdio.h>
int main(){

	int b ; //base
	int h ; //altezza
	
	printf("inserisci la misura della base\n");

	scanf_s("%d",&b); //acquisisce base

	printf("inserisci la misura dell'altezza\n");

	scanf_s("%d",&h); //acquisisce l'altezza

	int area = b * h;  //calcola l'area

	printf("l'area del rettangolo e':\n""%d",area);
}