#include<stdio.h>

//VERIFICA ESISTENZIALE
/*	INPUT:array d'interi, dimensione array
	PRE:dimensione>3
	OUTPUT: val booleano (1 o 0)
	POST: 1 se esiste un numero che sia uguale al cubo del precedente o al prossimo elemento
*/
/*funzione che mi calcola il cubo di un numero*/
int alCubo(int n){
	n=n*n*n;
	return n;
}

/*funzione che verifica se all'interno di array esiste
	intero == al cubo del precedente o prossimo*/
int cuboPrecSucc(int* seq, int lung){
	/*caso base*/
	if(lung<3)
		return 0;
	/*passo ricorsivo*/
	else{
		if(seq[1]==alCubo(seq[0]) || seq[1] == alCubo(seq[2]))
			return 1;
		else
			return	cuboPrecSucc(seq+1,lung-1);
	}

}


int main(){
	int lunghezza;
	printf("QUanti interi vuoi inserire?\n");
	scanf_s("%d",&lunghezza);

	int arr[lunghezza];
	for (int i = 0; i < lunghezza; i++){
		printf("Dammi numero: ");
		scanf_s("%d",&arr[i]);
	}
	if(cuboPrecSucc(arr,lunghezza))
		printf("esiste alme no 1 numero che ha come cubo il precedente o prossimo\n");
	else
		printf("NON esiste almeno 1 numero che ha come cubo il precedente o prossimo\n");
}