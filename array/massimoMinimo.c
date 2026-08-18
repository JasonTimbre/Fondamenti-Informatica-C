#include<stdio.h>
	/*applicazione che trova massimo e minimo di un array*/

int minimoSequenza(int* arr,int lenght) {
	int minimo=arr[0];	
	for(int i = 1;i<lenght;i++) {
		if(arr[i]<minimo) 
			minimo = arr[i];
	}
return minimo;
}
int massimoSequenza(int* arr,int lenght) {
	int massimo=arr[0];
	for(int i = 1;i<lenght;i++) {
		if(arr[i]>massimo)
			massimo = arr[i];
	}
return massimo;
}


int main() {

	int lung;	//lunghezza array
	int i;		// variabile contatore
		/* richiesta lunghezza */
	printf("Caro utente, quanti interi devi inserire?\n");
	scanf_s("%d", &lung);

		/* INPUT */
	int seq[lung];
	for(i = 0;i<lung;i++) {
		printf("Inserisci numero\n");
		scanf_s("%d", &seq[i]);
	}

		/* OUTPUT */
	int minimo = minimoSequenza(seq,lung);
	printf("Il minimo della sequenza inserita e' : %d",minimo);

	int massimo = massimoSequenza(seq,lung);
	printf("Il massimo della sequenza inserita e' : %d" massimo);
}