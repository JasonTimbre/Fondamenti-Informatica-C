#include<stdio.h>
#include<string.h>
	/* Funzione che verifica se stringa contine ripetizioni*/
int doppiaStringa(char* Stringa) {
	int i = 0;	//variabile contatore
	int doppia = 1;	//per il risultato
	int lun = strlen(Stringa);	//lunghezza stringa
	/*Controllo se lunghezza dispari*/
	if(lun%2 != 0)
		doppia=0;
	else {
		/*Controllo fino a metà stringa*/
		while(i<lun/2 && doppia)
			if(Stringa[i]!=Stringa[lun/2+i])
				doppia=0;
			else
				i++;
		}
	return doppia;
	}

/* Programma che verifica se una stringa contiene 
   due ripetizioni della stessa sottostringa*/

		/* Programma Principale*/
int main() {
char Stringa[50];	//Inizializzo la stringa

		/* INPUT*/
printf("Dammi una Stringa: ");
fgets(Stringa, 50, stdin);
Stringa[strlen(Stringa)-1] = '\0';

		/*OUTPUT*/
if(doppiaStringa(Stringa))
	printf("La tua stringa ha ripetizioni!!");

else
	printf("La tua stringa NON ha ripetizione!!");
}
