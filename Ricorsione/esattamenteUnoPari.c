#include<stdio.h>

/* Calcola la somma dei primi N numeri naturali. */
int primiNumeriNaturali(int n) {
	int conta = 0;	//per il risultato
	if(n==1)
		/* CASO BASE */
		return conta+1;
	
	else /* PASSO RICORSIVO */ {
	printf("n=%d,conta=%d",n,conta);
	conta = n + primiNumeriNaturali(n-1);
	}
}
int main() {
	int r=primiNumeriNaturali(4);
	printf("%d",r);
	return 0;


}