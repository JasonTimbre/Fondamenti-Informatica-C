/*Scrivere un programma che legge una sequenza
 di interi introdotta dall'utente e 
crea e stampa la sequenza inversa di quella letta.*/

#include<stdio.h>

int invertiSequenza(int seq[],int dimensioneArray){
	for(int i=0; i<dimensioneArray; i++){
		seq[i]=seq[i]*-1;
	}
return seq;
}

int main(){
int lenght;
printf("quanti numeri hai intenzione di introdurre?: ");
scanf_s("%d", &lenght);

int sequenza[lenght];
for(int i=0; i<lenght; i++){
	printf("inserisci un intero\n");
	scanf_s("%d", &sequenza[i]);
}
sequenza[lenght]=invertiSequenza(sequenza,lenght);
for(int j=0;j<lenght;j++)
	printf("%d ",sequenza[j]);

}