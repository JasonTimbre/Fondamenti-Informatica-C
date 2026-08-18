/*Progettare un'applicazione che legge un intero n e genera ripetutamente
dei numeri random, interi, compresi tra 1 e 100. La generazione termina
quando sono stati generati n numeri primi. Ogni volta che viene generato
un numero random, il numero viene mostrato in output, con un’indicazione
se è primo oppure no. Al termine della generazione viene stampato un
messaggio che indica quanti numeri sono stati generati in totale.
L’applicazione deve contenere
A. una funzione con prototipo int isPrimo(int num) che verifica se il
parametro num è primo oppure no
B. una funzione con prototipo void generatore(int numPrimi) che stampa
ripetutamente numeri random, interi, compresi fra 1 e 100, fino a
che non sono stati stampati numPrimi numeri primi. La funzione
termina stampando un messaggio che indica quanti numeri random sono
stati generati.
C. una funzione con prototipo void main(String[] args) (nella
struttura di seguito il main è completo).*/
#include <stdio.h>

int isPrimo(int x){		//funzione che verifica se n numero primo
	int num;
	if(num%2==0 && num%3==0 && num%5==0 && num%7==0 && num%11==0)
		return x;
}


int main(){
	int num;
	printf("Ciao inserisci un numero:\n");
	scanf_s("%d",&num);
	printf("il numero %d e' un numero primo", isPrimo(num));
	}


	





