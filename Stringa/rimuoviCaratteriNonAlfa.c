#include<stdio.h>
#include<string.h>

/* programma che legge una stringa 
   e la modifica rimuovendo tutti i
   caratteri che non sono alfabetici*/
void rimuoviNonalfa(char* str1,char* str2) {
	int i = 0;
	int j = 0;	//var contatore
	while(str1[i]!='\0') {
		if(str1[i]>='a' && str1[i]<='z' || str1[i]>='A' && str1[i]<='Z' ){// se è un carattere
			str2[j]=str1[i];
			printf("carattere prima stringa = %c\n",str1[i]);
			printf("carattere seconda stringa = %c\n",str2[j]);
			j++;
		}
			i++;
		}
	str2[j]= '\0';
	}

int main() {
	int j = 0;
	char str1[50];  //per la stringa input
	char str2[50];	//per la stringa output
	/*input*/	
	printf("Dammi una stringa: ");
	fgets(str1, 50, stdin);
	str1[strlen(str1)-1] = '\0';
	rimuoviNonalfa(str1,str2);
	printf("La stringa modificata e' : %s",str2);
}