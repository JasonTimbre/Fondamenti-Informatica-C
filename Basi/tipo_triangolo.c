#include <stdio.h>
/*TIPO TRIANGOLO
-------------------------

Scrivere un'applicazione TipoTriangolo che chiede all'utente 
di inserire 3 interi 
a, b e c da tastiera, li legge e stampa un messaggio c
he dice all'utente se il triangolo con lati a, b e c 
è equilatero, isoscele o scaleno.*/
int main(){
	int a,b,c;
	printf("inserisci 3 interi e ti diro che tipo di triangolo sara'\n"); 
	scanf_s("%d%d%d",&a,&b,&c);
	if(a+b>c && a+c>b && b+c>a){
		if((a=b) && (b=c) && (c=a))
			printf("e' un triangolo equilatero!!");
		else if((a=b && b!=c) || (a=c && c!=b) || (b=c && b!=a))
			printf("e' un triangolo isoscele!!");
		else if(a!=b!=c!=a)
			printf("e'un triangolo scaleno!!");
	}
	else
		printf("i tre valori non corrispondo a lati di un triangolo!!");
}