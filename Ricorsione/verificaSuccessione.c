#include<stdio.h>
/*funzione ricorsiva che verifica che ogni tripla di elementi consecutivi
	la somma del primo e del secondo elemento della tripla è uguale
	alla differenza tra il terzo e il secondo*/
int verificaSuccessione(int* seq,int lung) {
	/*caso base*/
	if(lung<=3)
		return 1;
	/*passo ricorsivo*/
	else{
		if(seq[0]+seq[1] == seq[2]-seq[1])
			return verificaSuccessione(seq+1, lung-1);
		else
			return 0;
	}
}
int main(){
	int lung;
	printf("Quanti numeri vuoi introdurre: ");
	scanf_s("%d",&lung);
	int seq[lung];
	for(int i = 0; i<lung; i++){
		printf("Dammi un numero: ");
		scanf_s("%d",&seq[i]);
	}
	if(verificaSuccessione(seq,lung))
		printf("Istanza positiva\n\n");
	else
		printf("Istanza negativa");
}