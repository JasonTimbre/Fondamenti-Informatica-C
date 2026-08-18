/*01) Scrivere un programma che legge una sequenza
 di interi introdotta dall'utente
e crea una nuova sequenza che contiene tutti gli elementi positivi
della precedente; la nuova sequenza viene stampata.
Utilizzare una funzione che riceve come parametro un 
array di interi e 
conta il numero di interi positivi nell'array.
[soluzione ValoriPositivi.c]*/
#include <stdio.h>

/*Funzione che conta i numeri interi*/
int contaPositivi(int interi[],int lunghezza){
	int num=0;
	for(int i=0;i<lunghezza;i++){
		if(interi[i]>0)
			num++;
			return num;
	}
}

int main(){
	
int dimensione;  //lunghezza array

int nuovaDimensione;  //nuova lunghezza array 

int i,j;	// variabili contatore

//richiedi la lunghezza della sequenza
printf("Caro utente quanti valori vuoi introdurre?\n");
scanf_s("%d",&dimensione);


//leggi la sequenza
int interi[dimensione];
for(i=0;i<dimensione;i++){
	printf("Caro utente,introduci un numero:\n");
	scanf_s("%d", &interi[i]);
}
	printf("%d",interi);

}



	



















