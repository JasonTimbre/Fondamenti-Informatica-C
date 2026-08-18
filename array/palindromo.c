#include<stdio.h>
/*applicazione che verifica se una sequenza di interi è polindroma*/
//controllo primo ed ultimo elemento e se sono diversi non è
//palindromo se lo sono vado avanti con il primo e indietro con ultimo =)
int isPalindromo(int* arr,int l) {
	int i = 0;
	int j = l-1;
	while(i<j){
		if(arr[i]!=arr[j]){
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}


int main() {
	int l;	//lunghezza array
	printf("Quanti numeri vuoi inserire? ");
	scanf_s("%d",&l);

		/* INPUT */
	int seq[l];
	for(int i = 0;i<l;i++){
	printf("Inserisci un numero ");
	scanf_s("%d",&seq[i]);
}
		/* OUTPUT */

	if(isPalindromo(seq,l))
		printf("La sequenza inserita e' una sequenza palindroma!");
	else
		printf("Mi dispiace, la sequenza inserita NON e' palindroma!");
}