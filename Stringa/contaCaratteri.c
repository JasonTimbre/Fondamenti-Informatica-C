#include<stdio.h>
#include<string.h>

int contaCaratteri(char* stringa) {
	int quanti = 0;	//risultato
	int i = 0;
		/* scorro la stringa */
	while(stringa[i]!='\0') {
	quanti++;
	i++;
}
return quanti;
}

	
int main() {
	char stringa[50];
		/* INPUT*/
	printf("Caro utente, dammi una stringa : ");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1] = '\0';
		/* OUTPUT */
	int caratteri = contaCaratteri(stringa);
	printf("La stringa contiene %d caratteri!! ",caratteri);
}
