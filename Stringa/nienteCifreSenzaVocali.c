#include<stdio.h>
#include<string.h>

/* FUNZIONE CHE CONTROLLA SE IL CARATTERE è NUMERICO */
int isNumber(char x) {
	if(x >= '0' && x <= '9')
		return 1;
	else 
		return 0;
}
int isChar(char x) {
	if((x >= 'a' && x <= 'z') || x >= 'A' && x <= 'Z')
		return 1;
	else 
		return 0;

}

/* FUNZIONE CHE RIMUOVE TUTTI I CARATTERI NUMERICI DI 
	UNA STRINGA, CHE NON 
	SONO PRECEDUTI DA UNA VOCALE   */
void nienteCifreSenzaVocali(char* str1, char* str2) {
	int i = 0;
	int j = 0;
	while(str1[i] != '\0') {
		if(isNumber(str1[i])) {
			if(str1[i-1] == 'a' || str1[i-1] =='e' ||
				str1[i-1] =='i' || str1[i-1] =='o' ||
				str1[i-1] =='u') {
				str2[j] = str1[i];
				i++;
				j++;
				}
			else if(isChar(str1[i])) {
				str2[j] = str1[i];
				i++;
				j++;
				}
			}
			
		else
			i++;
	}
	str2[j] = '\0';
}

/* FUNZIONE PRINCIPALE */
int main() {
	char str1[50];
	char str2[50];
	printf("Dammi una stringa: ");
	fgets(str1,50,stdin);
	str1[strlen(str1)-1] = '\0';

	nienteCifreSenzaVocali(str1,str2);
	printf(" Ecco la stringa modificata: %s",str2);
}