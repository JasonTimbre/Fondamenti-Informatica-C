#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/* Scrivere un programma che prende in input un array non
nullo e non vuoto di interi e che restituisce in output 
a un intero composto dalle cifre dell’array: la cifra più
significativa corrisponde all'indice 0 dell'array.
 Utilizzare una funzione ricorsiva.
  Esempio: {1,2,3} -> 123.*/
int convertiArrayIterativo(int* num,int lung) {
	int somma = 0;
	int espo=0;
	for(int i = lung-1; i>=0; i--) {
			num[i] = num[i]*pow(10,espo);
			printf("cifra vale %d\n",num[i]);
			espo++;
			somma  += num[i];
			printf("totale vale %d\n",somma);
			}
		return somma;
		}

int convertiArrayRicorsivo(int* str,int l,int esp) {
	/* CASO BASE */
	if(l==1)
		return str[l-1]*pow(10,esp);
	/* PASSO RICORSIVO */	
	return str[l-1]*pow(10,esp) + convertiArrayRicorsivo(str,l-1,esp+1);

}
	

int main() {
	int l;
	printf("Caro Utente, quanti numeri vuoi introdurre: ");
	scanf_s("%d",&l);

	int seq[l];
	for(int i = 0;i<l;i++){	
	printf("Caro Utente, inserisci un numero: ");
	scanf_s("%d",&seq[i]);
	}
	printf("La sequenza e' la seguente: ");
	for(int i=0;i<l;i++){
		printf("%d ",seq[i]);
	}
	printf("\n");
	int num = convertiArrayRicorsivo(seq,l,0);
	printf("Il numero convertito dall'array e': %d\n",num);
}