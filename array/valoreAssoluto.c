/*La funzione main legge una sequenza di interi introdotta
 dall'utente (prima di leggere tale sequenza chiede all'utente di quanti numeri consiste la sequenza) 
 ed invoca la funzione valoriAssoluti che rimpiazza ciascun elemento dell'array con il suo valore assoluto.
  La nuova sequenza viene quindi stampata.
*/
#include <stdio.h>

/*funzione valore assoluto*/
void valoreAssoluto(int interi[],int lunghezza){
	for(int i=0;i<lunghezza;i++){
	if(interi[i]<0)
		interi[i]=-interi[i];
}
}


int main(){

int lunghezza; //lunghezza della sequenza di interi
int i;  //variabile contatore
printf("Caro Utente, di quanti numeri consiste la sequenza?\n");
scanf_s("%d",&lunghezza);
int interi[lunghezza];
for(int i=0;i<lunghezza;i++){
	printf("Introduci un numero: \n");
	scanf_s("%d",&interi[i]);
	
}

valoreAssoluto(interi,lunghezza);
printf("la sequenza in valore assoluto e':\n");
	for(i=0;i<lunghezza;i++)
		printf(" %d",interi[i]);

}