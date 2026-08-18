#include<stdio.h>
//NON SONO RIUSCITO!!

int massimoArray(int* arr,int l) {
	/* CASO BASE */
	if(l==1) {
		return arr[0];	
	}	
	/* PASSO RICORSIVO */
	else {
		int massimo = massimoArray(arr,l-1);
		int ultimo  = arr[l-1];
		printf("massimo=%d\nultimo=%d\n",massimo,ultimo);
		if(massimo>ultimo)
			return massimo;
		else
			return ultimo;
		}

		
	
}	
/*caso base(caso migliore)
passo ricorsivo(oracolo che mi rimpicciolisce il problema + problema piu piccolo)*/



int main() {
	int l;   //lunghezza
	printf("quanti elementi devi inserire? ");
	scanf_s("%d",&l);

	int arr[l];
	for(int i = 0;i<l;i++) {
		printf("Inserisci un numero ");
		scanf_s("%d",&arr[i]);
	}

	int massimo = massimoArray(arr,l);

	printf("Il valore massimo che hai inseririto e' : %d",massimo);
 

	}