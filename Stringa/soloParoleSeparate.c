#include<stdio.h>
#include<string.h>

/*Funzione che modifica stringa 
sostituendo spazi a caratteri non alfabetici*/
void soloParoleSeparate(char* str1, char* str2) {
	int i = 0;	//variabile contatore
	int j = 0;
	/*scorro la stringa*/
	while(str1[i] !='\0') {
		while(	((str1[i] >= 'a' && str1[i] <= 'z') ||
				(str1[i] >= 'A' && str1[i] <= 'Z'))) {	//copio caratteri nell'altra stringa
			str2[j] = str1[i];
			i++;
			j++;
		}
		if(!((str1[0] >= 'a' && str1[0] <= 'z') ||
			(str1[0] >= 'A' && str1[0] <= 'Z'))) {
			i++;		
		}

		if(!((str1[i] >= 'a' && str1[i] <= 'z') ||
			(str1[i] >= 'A' && str1[i] <= 'Z'))) {
			str2[j] = ' ';
			i++;
			j++;
		}
	}
	str2[j] = '\0';
} 

int main () {
	char stringa1[50];
	char stringa2[50];
	printf("Inserisci una stringa: ");
	fgets(stringa1,50,stdin);
	stringa1[strlen(stringa1)-1] = '\0';

	soloParoleSeparate(stringa1,stringa2);
	printf("Ecco la stringa modificata: %s", stringa2);

}