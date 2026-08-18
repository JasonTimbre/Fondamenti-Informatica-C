/*NUMERO TRIPLE SOMMA ZERO
-------------------------

Realizzare un programma che consiste di due funzioni.

La funzione main legge una sequenza di interi introdotta
dall'utente (prima di leggere tale sequenza chiede all'utente 
di quanti numeri consiste la sequenza). La funzione main invoca
quindi la funzione tripleSommaZero che calcola e restituisce il
numero di triple di interi consecutivi nella sequenza la cui somma
è pari a 0; la funzione main stampa quindi tale intero.
La funzione tripleSommaZero riceve come parametro un array
di interi e la sua lunghezza 
e restituisce il numero di triple di interi consecutivi nella
sequenza la cui somma è pari a 0.

-------------------------
*/
#include<stdio.h>
int tripleSommaZero(int interi[],int lunghezza){
	int n=0;  //variabile accumulazione
	for(int i=0;i<lunghezza-2;i++){
		if(interi[i]+interi[i+1]+interi[i+2]==0)
			n++;
}
		return n;

	
}

int main(){

int lunghezza;	//variabile dimensione array
printf("Quanti interi hai intenzione di inserire?\n");
scanf_s("%d",&lunghezza);

int interi[lunghezza];
for(int i=0;i<lunghezza;i++){
	printf("inserisci un intero:\n");
	scanf_s("%d",&interi[i]);
}

printf("la sequenza ha %d triple con somma uguale a 0",tripleSommaZero(interi,lunghezza));
}