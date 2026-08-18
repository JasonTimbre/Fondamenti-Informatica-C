#include <stdio.h>
//funzione che restituisce il risultato del prodotto scalare tra due vettori
int prodottoScalare(int arr1[],int arr2[],int lung){
	int arr3[lung];
	int risultato=0;
	for(int i=0;i<lung;i++){
		risultato+=arr1[i]*arr2[i];
	}
	
	return risultato;
}

int main(){

//acquisizione dimensione vettori
int lung;
printf("quanti elementi nel vettore da moltiplicare?\n");
scanf_s("%d",&lung);

//input primo vettore
printf("creiamo il primo vettore\n");
int vett1[lung];
for(int i=0;i<lung;i++){
	printf("inseririsci un numero:\n");
	scanf_s("%d",&vett1[i]);
}
printf("il primo vettore e':\n");
for(int i=0;i<lung;i++){
	printf("%d ",vett1[i]);
}
printf("\n");

//acquisizione secondo vettore
printf("creaiamo il secondo vettore\n");
int vett2[lung];
for(int i=0;i<lung;i++){
	printf("inseririsci un numero:\n");
	scanf_s("%d",&vett2[i]);
}
printf("il secondo vettore e':\n");
for(int i=0;i<lung;i++){
	printf("%d ",vett2[i]);
}
printf("\n");

int ris=prodottoScalare(vett1,vett2,lung);
printf("il risultato del prodotto scalare dei due vettori inseriti e':%d\n",ris);
}