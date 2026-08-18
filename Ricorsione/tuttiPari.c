#include<stdio.h>
	/*Programma che verifica che tutti gli elementi 
	  di una sequenza sono pari*/

/* realizzazioni 1 */

int tuttiPari(int* seq,int l) {
	int ris;	// per il risultato
	/* CASO BASE */
	if(l==0)
		ris = 1;
	/* PASSO RICORSIVO*/
	else
		ris=(seq[l-1]%2==0) && tuttiPari(seq,l-1);
	return ris;

	/* Realizzazione 3 */
	int tuttiPari3(int* seq,int l) {
		int ris;	//risultato
		/* CASO BASE */
		if(l==0)
			ris=1;
		else
			ris = (seq[0]%2==0) && tuttiPari3(seq+1,l-1);
	}
	
	/* realizzazione 2 */
		/*funzione che restituisce 1 se tutti gli elementi si qeq
		 a partire da quello con indice i sono pari*/

	int tuttiRic(int* seq, int i, int l) {
		int ris;	//risultato

		/* CASO BASE */
		if(i>=l)
			ris = 1;
		else
			ris = (seq[i]%2==0) && tuttiRic(seq, i+1, l);

		return ris;
	}

	int tuttiPari2(int* seq,int l) {
		return tuttiRic(seq, 0, l);
	}
}

int main() {
	int sequenza[4]={2,4,2,2};
	if(tuttiPari3)
		printf("La sequenza di elementi contiene tutti numeri pari");
}