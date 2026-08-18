#include<stdio.h>

/* (ConsecutiviUguali) Scrivere un programma che prende
 in input una sequenza di interi e verifica
  se nella sequenza esistono due interi
   consecutivi uguali utilizzando una funzione 
   ricorsiva.*/
int consecutiviUguali(int* seq,int l) {

	/* CASO BASE */
	if(l<=2)
		return 0;
	/* PASSO RICORSIVO */
	if(seq[0]==seq[1])
		return 1;
	else
		return consecutiviUguali(seq+1,l-1);
}

int main() {
	int l;
	printf("Quanti numeri da inserire? ");
	scanf_s("%d",&l);

	int seq[l];
	for(int i = 0;i<l;i++) {
		printf("Inserisci un numero: ");
		scanf_s("%d",&seq[i]);
	}
	if(consecutiviUguali(seq,l))
		printf("Ci sono almeno due interi consecutivi nella sequenza\n");
	else
		printf("NON ci sono interi consecutivi nella sequenza");

}