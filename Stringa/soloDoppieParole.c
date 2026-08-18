#include<stdio.h>
#include <string.h>
/*funzione che verifica se un carattere è alfabetico*/
int alfa(char c) {
	int ris; //per il risultato
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		ris=1;
	else
		ris=0;
	return ris;

}

/*funzione che prende una stringa e lascia solo 
	le sue parole,separate da spazi*/

void soloParole(char* stringa) {
	int i=0;	//variabile contatore
	/* Guarda i caratteri uno ad uno*/
	while(stringa[i]!= '\0') {
		/* Se carattere alfabetico lascialo stare*/
		if(alfa(stringa[i]))
			i++;

		/*carattere non alfabetico*/

		else
			/* Devo rimpiazzare il carattere con uno spazio? */	
			if(i>0 && alfa(stringa[i+1])){
				stringa[i] = ' ';
				i++;
			}
			/*cancellazione*/

			for(int j =i;stringa[j]!='\0';j++)
				stringa[j]=stringa[j+1];
	}
}


/* Programma Principale */
int main() {
	char stringa[50];
	
	/* input */
	printf("Dammi una stringa: ");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1] = '\0';

	/* Modifica la stringa e stampala*/

	soloParole(stringa);
	printf("La stringa modificata e': %s",stringa);

}