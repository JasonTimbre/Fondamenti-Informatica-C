#include<stdio.h>


int sommaElementiArray(int n) {
	int conta = 0;	//per il risultato
	if(n==1)
		/* CASO BASE */
		return conta+1;
	
	else /* PASSO RICORSIVO */ {
	printf("n=%d ,conta=%d ",n,conta);
	conta = n + sommaElementiArray(n-1);
	}
}
int main() {
	int r=sommaElementiArray(7);
	printf("%d",r);
	return 0;


}