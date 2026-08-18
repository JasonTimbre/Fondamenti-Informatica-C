#include<stdio.h>
#include <string.h>

/* Funzione che modifica la stringa eliminando 
	ripetizione di caratteri alfabetici maiuscoli */
 void nienteDoppieMaiuscole(char* stringa) {
 	int i = 0;	//variabile contatore
 	/* Controllo di ogni singolo elemento*/
 	while(stringa[i]!='\0') {
 		/* Cancello quando sono su un alfabetico maiuscolo
 			uguale al successivo*/
 		if((stringa[i]>='A' && stringa[i]<='Z')
 		 && stringa[i] == stringa[i+1])
 			/* Cancellalo*/
 			for(int j=i;stringa[j]!='\0';j++)
 				stringa[j]=stringa[j+1];
 		else
 			i++;
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

	nienteDoppieMaiuscole(stringa);
	printf("La stringa modificata e': %s",stringa);

}