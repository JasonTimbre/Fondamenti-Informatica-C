#include <stdio.h>
#include<string.h>
/* Funzione che modifica stringa  cosi che ogni numero di almeno
	3 cifre rimangano solamente primo e d ultimo mentre
	tutti i numeri centrali saranno sostisuiti con '*' */
void numeriBucati(char* s1, char* s2) {
	int prima;	//prima cifra
	int ultima;	//ultima cifra
	int lunghezza;	//per il numero di cifre
	int i = 0;	//contatore di s1
	int j = 0;	//contatore di s2
	/*Scorro la stringa*/
	while(s1[i] != '\0') {
		if(s1[i] >= '0' && s1[i] <= '9') {
			prima = i;
			i++;
			}
			ultima = i-1;
			lunghezza = ultima - prima + 1;
	}
	printf("Blocco numerico : start=%d end=%d lunghezza=%d\n",
			prima,ultima,lunghezza);
}

int main() {
	char str1[50];
	char str2[50];
	fgets(str1,50,stdin);
	str1[strlen(str1)-1] = '\0';

	numeriBucati(str1,str2);
	printf("La stringa modificata e' %s",str2);	
}