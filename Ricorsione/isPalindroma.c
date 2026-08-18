#include<stdio.h>
#include<string.h>

/* Funzione che verifica se una stringa è palindroma */
int isPalindroma(char*stringa,int inizio,int fine) {
	/* CASO A BASE*/
	if(inizio>=fine)
		return 1;
	if(stringa[inizio]!=stringa[fine])
		return	0;

	/* PASSO RICORSIVO */
	else
		return isPalindroma(stringa,inizio+1,fine-1);


	}




int main() {
	char stringa[50];
	printf("Dammi una stringa: ");
	fgets(stringa,50,stdin);
	stringa[strlen(stringa)-1] = '\0';

	if(isPalindroma(stringa,0,strlen(stringa)-1))
		printf("La stringa che mi hai dato e' palindroma\n");
	else
		printf("La stringa che mi hai dato NON e' palindroma\n");
}
