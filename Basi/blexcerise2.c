#include<stdio.h>
/*
Per quali valori di verità delle variabili a, b e c è vera l'espressione (a || b) || (!a || c) && (b &&
c)?
Per rispondere, utilizza una tavola di verità oppure ragionamenti logici che semplificano
l'espressione. Verifica quindi la tua risposta scrivendo un programma che mostra la tabella. Il
programma potrebbe iniziare così:
int a, b, c;
printf("|a|b|c|e|\n");
a=0; b=0; c=0;
printf("|%d|%d|%d|%d|\n", a, b, c, (a || b) || (!a || c) && (b && c));*/
int main(){
	int a,b,c;
	printf("a|b|c|e|\n");
	a=0; b=0; c=0;
	printf("|%d|%d|%d|%d|\n",a, b, c, (a || b) || (!a || c) && (b && c));

}