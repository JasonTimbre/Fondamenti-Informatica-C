#include<stdio.h>
#include <string.h>
/* programma che rice una stringa e restituisce 
il numero massimo contenuto nella stringa.
es "ndbsug21iudnsh45un789" la funzione restituisce 789.*/
int numeroMassimo(char* str) {
	int i = 0;
	int max = -1;
	while(str[i]!=0) {
		/* se l'elemento  è un numero*/
		if(str[i]<='0' && str[i]<='9') {
		
			int num = 0;
			
			while(str[i]<='0' && str[i]<='9') {

				max = num * 10 + (str[i]-'\0');
				i++;			
			}	
			
			if(num>max)
				max = num;
		}
		else { 
			i++;	
		}
	}
	return max;		
}

int main() {
	char str[50];
	printf("Dammi una stringa: \n");
	fgets(str,50,stdin);
	str[strlen(str)-1] = '\0';

	int max = numeroMassimo(str);
	printf("Il numero massimo contenuto e' : %d",max);

}