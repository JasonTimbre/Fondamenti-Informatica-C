#include <stdio.h>
/*funzione ricorsiva che verifica se per ogni triple consecutive
della sequenza il primo elemento + il secondo elemento 
==terzo elemento*/

/*problema di verifica universale*/
/* 	INPUT: array,lunghezza array
	PRE:lunghezza >=3
	OUTPUT: 1 o 0
	POST: primo elemento + secondo elemento = terzo elemento per tutte le triple consecutive

*/

int verificaSequenza(int* seq, int lung){
	/*CASO BASE*/
	if(lung<3)
		return 1;
	/*PASSO RICORSIVO*/
	else{
		if(seq[0]+seq[1]==seq[2])
			return verificaSequenza(seq+1,lung-1);
		else
			return 0;
	}
}


int main(){
	int lung;	//per la lunghezza
	printf("Quanti numeri vuoi inserire? ");
	scanf_s("%d",&lung);

	int seq[lung];
	for(int i = 0; i<lung; i++){
		printf("Inserisci numero: ");
		scanf_s("%d",&seq[i]);

	}
	if(verificaSequenza(seq,lung))
		printf("Istanza Positiva.");
	else
		printf("Istanza Negativa");
}