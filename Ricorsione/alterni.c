#include<stdio.h>
// fatto in 10 minuti senza ai!!!
/* funzione che verifica se in un array i numeri positivi e negativi si alternano 00:34*/
int tuttiAlterni(int* arr,int l) {
	/* CASO BASE */
	if(l==2 && ((arr[0]>0 && arr[1]<0) || (arr[0]<0 && arr[1]>0)))
		return 1;
	/* PASSO RICORSIVO */
	else {
		if((arr[0]>0 && arr[1]<0) || (arr[0]<0 && arr[1]>0))
			return tuttiAlterni(arr+1,l-1);
		else
			return 0;
	}
}