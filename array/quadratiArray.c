/*Realizzare un programma che consiste di due funzioni.

La funzione main legge una sequenza di interi introdotta 
dall'utente (prima di leggere tale sequenza chiede all'utente
di quanti numeri consiste la sequenza). 
La funzione tutteUnQuadrato riceve come parametro un array di
interi e la sua lunghezza e verifica, se all’interno di un array
di interi ricevuto come parametro,
tutte le triple di interi consecutivi della sequenza, sono tali che
uno degli elementi della tripla sia il quadrato di uno tra 
gli altri due elementi.
Ad esempio, se l’array è [4, 3, 2, 9], la funzione deve restituire 1,
in quanto nella tripla [4, 3, 2], 4 è il quadrato di 2 e nella tripla
 [3,2,9], 9 è il quadrato di 3. Se l’array è [1, 3, 1, 12], la funzione
deve restituire 0, poiché nella tripla [3, 1, 12] nessun numero è il
 quadrato di uno degli altri due elementi della tripla.
*/
#include <stdio.h>
int tutteUnQuadrato(int interi[],int lunghezza){
	for(int i=0;i<lunghezza-2;i++){
		if(interi[i]*interi[i]=interi[i+1] || interi[i]*interi[i]=interi[i+1] || interi[i]*interi[i]=interi[i+2])
			return 1;
		else 
		return 0;
	}

}


int main(){

int lunghezza; // dimensione array

printf("Caro Utente, di quanti numeri consiste la sequenza?\n");
scanf_s("%d",&lunghezza);

int interi[lunghezza];
for(int i=0;i<lunghezza;i++){
	printf("Inserisci un intero:\n");
	scanf_s("%d",&interi[i]);
}
printf("%d",tutteUnQuadrato(interi,lunghezza));
}


