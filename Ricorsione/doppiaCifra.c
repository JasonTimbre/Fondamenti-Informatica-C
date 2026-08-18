#include <stdio.h>
#include<stdlib.h>

/*	INPUT: array d'interi,dimensione array
	PRE:dimensione >=3
	OUTPUT:var booleana(vero o falso,1 o 0)
	POST: ogni tripla deve contenere esattamente 1 numero con 2 cifre
*/

/*funzione che verifica se ogni tripla consecutiva ha 
	esattamente u nnumero con 2 cifre*/
int doppiaCifra(int* seq, int lung){
	/*caso base*/
	if(lung <3)
		return 1;
	else{
		if( (seq[0] >= 10 && seq[0]<=99) && !(seq[1] >= 10 && seq[1]<=99) && !(seq[2] >= 10 && seq[2]<=99) ||
			!(seq[0] >= 10 && seq[0]<=99) && (seq[1] >= 10 && seq[1]<=99) && !(seq[2] >= 10 && seq[2]<=99)||
			!(seq[0] >= 10 && seq[0]<=99) && !(seq[1] >= 10 && seq[1]<=99) && (seq[2] >= 10 && seq[2]<=99))

			return doppiaCifra(seq+1,lung-1);
		else
			return 0;
	}
}
//3,17, 4, 3, -12
int main(){
	int lung;	//per la dimensione dell'array
	printf("Quanti elementi ha la sequenza di numeri: ");
	scanf_s("%d",&lung);

	int seq[lung];
	for(int i = 0; i<lung; i++){
		printf("Inserisci numero: ");
		scanf_s("%d", &seq[i]);
	}

	if(doppiaCifra(seq,lung))
		printf("Ogni sequenza ha esattamente un numero con 2 cifre\n");
	else
		printf("Ogni sequenza ha NON esattamente un numero con 2 cifre\n");


}