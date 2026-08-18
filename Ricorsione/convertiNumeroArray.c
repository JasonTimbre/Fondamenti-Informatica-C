 #include<stdio.h>
#include<stdlib.h>
	/*Esercizio 5 (ConvertiNumeroArray) Scrivere un programma che prende
 	in input un intero n e stampa in output un array di interi in cui ogni
  	componente dell’array corrisponde a una cifra del numero.
  	La cifra più significativa di n si trova in posizione d’indice 0.
	Si consiglia di utilizzare funzioni di supporto.
	Esempio: 123 -> {1,2,3}*/
 



//L'idea è sarebbe di ottenere il numero di cifre attraverso la funzione contaQuanteCifre, 
//Per sapere la dimensione dell'array dell'output.
//Poi scomporre attraverso scomponiIntero(devo capire come) ed assegnare  ogni valore 
//All'array gia salvato

	int contaQuanteCifre(int n) {
		int quante = 0;		//per il risultato
			/* finche macciore di 0*/
		while(n>0) {
			/*divido per 10 e conto le cifre*/
			n = n/10;
			quante++;
		}
		return quante;
	}

	int* scomponiIntero(int n) {
		int temp;
		int i = contaQuanteCifre(n)-1; 
		int* arr =(int*) malloc(sizeof(int)*contaQuanteCifre(n));
		while(n>0) {
			temp = n%10;
			n = n/10;
			arr[i] = temp;
			i--;
		}
		return arr;
	}
	

	int* convertiArray(int n,int l) {
		if(l==1) {
			int* arr = (int*)malloc(sizeof(int));
			arr[0] = n;
			return arr;
		}
		else{
			int* temp = convertiArray(n/10,l-1);
			temp = realloc(temp,l);
			temp[l-1] = n%10;
			return temp;
		}
	}


int main() {
	int numero;
	printf("Caro Utente, inserisci un numero: ");
	scanf_s("%d",&numero);
	int quanteCifre = contaQuanteCifre(numero);
	int* arr = convertiArray(numero,quanteCifre);
	printf("Stampo array :\n");
	for(int i = 0;i<quanteCifre;i++) {
		printf("%d ",arr[i]);
	}

}