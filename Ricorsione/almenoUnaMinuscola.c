#include<stdio.h>
#include<string.h>

/* Programma che prende una stringa e restituisce true se 
	la stringa contiene almeno un carattere alfabetico minuscolo,
	false altrimenti.*/

/* Funzione che restituisce true se contiene carattere minuscolo,
	false altrimenti */
int almenoUnaMinuscola(char* seq) {
	int ris;	//risultato
	/*CASO BASE*/
	if(*seq == '\0')
		ris = 0;
	else
		if(*seq>='a' && *seq<='z')
			ris = 1;
		else
			ris = almenoUnaMinuscola(seq+1);
	return ris;
}

/* Programma principale*/
int main() {
	/* INPUT */
char stringa [50];
printf("Caro utente, dammi una stringa: ");
fgets(stringa, 50, stdin);
stringa[strlen(stringa)-1] = '\0';

	/* OUTPUT */
if(almenoUnaMinuscola(stringa))
	printf("La stringa contiene almeno una minuscola.");
else
	printf("La stringa NON contiene nemmeno una minuscola!!");
}