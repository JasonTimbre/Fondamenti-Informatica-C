#include<stdio.h>
#include<string.h>

/* Funzione che riceve come parametro un stringa e la modifica 
rimovendo ogni sequenza
 di esattamente due caratteri alfaberici minuscoli uguali
consecutivi  */

void cancellaDueMinuscoleConsecutive (char* str1,char* str2) {
	int i = 0;
	int j = 0;
	/* scorri la stringa fino alla fine*/
	while(str1[i]!='\0') {
		/* Se elementi uguali  e minuscoli */
		if(str1[i] == str1[i+1] && ((str1[i]>='a' && str1[i]<='z'))){
			str2[j] = str1[i+2]; //salvo l'elemento dopo la doppia
			i++;
		}
		/*altrimenti se diversi lo salvi*/
		else {
			str2[j] = str1[i];
			i++;
			j++;
		}
	}
	str2[j] = '\0';
}

int main() {
	char str1[50];
	char str2[50];
	printf("Caro utente, inserisci un a stringa: ");
	fgets(str1,50,stdin);
	str1[strlen(str1)-1] = '\0';
	cancellaDueMinuscoleConsecutive(str1,str2);
	printf("Risultato: %s",str2);
}