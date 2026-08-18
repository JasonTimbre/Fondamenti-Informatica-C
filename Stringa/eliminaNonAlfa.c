#include<stdio.h>
#include<string.h>

/*funzione che prende una stringa e ne cancella 
  i carattei non alfabetici*/
void soloAlfabateci(char* stringa) {
	int i=0;  // variabile contatore

	/*guarda tutti i caratteri della stringa*/

	whil(estringa[i]!='\0') {
		/*il carattere corrente è NON alfabetico?*/
		if(!((stringa[i]>='a' && stringa[i]<='z')||
			(stringa[i]>='A' && stringa[i]<='Z')))
			/*cancellalo*/
	 	for(int j=i;stringa[j]!='\0';j++)
			stringa[j]=stringa[j+1];
		else
			i++;
	}

}

/* programma che legge una stringa 
   e la modifica rimuovendo tutti i
   caratteri che non sono alfabetici*/
int main() {
	char stringa[50];  //per la stringa
	
	/*input*/
	printf("Dammi una stringa: ");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1] = '\0';

	/* modifica la stringa e stampala*/
	soloAlfabateci(stringa);
	printf("La stringa modificata vale: %s", stringa);
}