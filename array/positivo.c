#include <stdio.h>


//funzione che restituisce solo i valorei positivi della sequenza
int contaPositivo(int interi[],int lunghezza){
int newArr[lunghezza];
for (int i = 0; i < lunghezza; i++){
	if(interi[i]>0){
		newArr[i]=interi[i];
	else
		 char newArr[i]='-';
	}

}
return newArr;
}





int main(){
//input
int lenght;
printf("quanti numeri hai intenzione di introdurre?\n");
scanf_s("%d",&lenght);
int sequenza[lenght];
for(int i =0;i<lenght;i++){
	printf("introduci un intero\n");
	scanf_s("%d",&sequenza[i]);
}
//output
printf("la sequenza con solo i valori positivi e' la seguente:\n");
 int nuovaSequenza[lenght];
 nuovaSequenza[lenght]=contaPositivo(sequenza,lenght);
for(int j=0;j<lenght;j++)
	printf("%d ", nuovaSequenza[j]);

}