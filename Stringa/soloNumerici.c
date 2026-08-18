#include<stdio.h>
#include<string.h>

/*funzione che verifica se una stringa è composta
 da soli caratteri numerici*/

int soloNumerici(char* stringa) {
	int tutti=1;  //risultato
	int i = 0; // variabile contatore

	/*guarda tutti i caratteri della stringa fino a 
	  che non hai trovato la risposta */

	while(stringa[i]!='\0' && tutti) {
		/*  è numerico?*/	
		if(stringa[i]>='0' && stringa[i]<='9')
			i++;
		else
			tutti=0;

	return tutti;
	}

}

/* programma che legge una stringa introdotta
   dall'utente e dice all'utente se tutti 
   i caratteri della stringa sono numerici*/

int main() {
	char stringa[50];  // per la stringa

	/*input*/
	printf("Dammi una stringa: ");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1] = '\0';

	if(soloNumerici(stringa))
		printf("Tutti i caratteri sono numerici!");

	else
		printf("Non tutti i caratteri sono numerici");
}