#include<stdio.h>
#include<string.h>

/* funzione che sostituisce ai caratteri numerici il carattere
	"*".*/

void numeriNascosti(char* str1,char* str2) {
	int i = 0;
	int j = 0;
		/* Scorro la lista */
	while(str1[i]!='\0') {
		/* Se contiene numero */
		if(str1[i]>='0' && str1[i]<='9'){
			/* sostituiscilo * alla nuova stringa */
			str2[j] = '*';
		}
		/* metti il carattere alfabetico nella nuova stringa*/
		else{
			str2[j] = str1[i];
		}
		i++;
		j++;
	}
	str2[j] = '\0';	//chiudo la stringa
	/* Stampa la lista modificata */
	int k = 0;
	while(str2[k]!='\0') {
		printf("%c",str2[k]);
		k++;
	}
}
int main() {
	char stringa1[100];
	char stringa2[100];

	printf("Dammi una stringa: ");
	fgets(stringa1,50, stdin);
	stringa1[strlen(stringa1)-1] = '\0';
numeriNascosti(stringa1,stringa2);
printf("%s\n",stringa2);
}