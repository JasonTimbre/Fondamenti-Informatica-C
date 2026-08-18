#include<stdio.h>
#include<string.h>

/* Funzione che conta quante volte compare
	 un carattere in una stringa ricorsivamente.*/

int quanteRipIterativa(char* str,char let) {
	int rip = 0;
	int i = 0;
	while(str[i]!='\0') {
		if(str[i]!=let)
			i++;
		else{
			rip++;
			i++;
		}
	}
	return rip;
}
int quanteRipRicorsiva(char* str,char let) {
	/* Caso Base*/
	if(strlen(str)==0)
		return 0;
	/* Passo ricorsivo*/
	else {
		printf("elemento=%c\n",str[0]);
		if(str[0]==let)
		return 1 + quanteRipRicorsiva(str+1,let);
		else
			return quanteRipRicorsiva(str+1,let);
	}

}

int main() {
	char let;	//carattere da cercare
	char stringa[50];
	printf("Dammi una stringa: ");
	fgets(stringa,50,stdin);
	stringa[strlen(stringa)-1] = '\0';
	printf("Quale lettera ti devo controllare: ");
	scanf_s("%c",&let);


	int quantita = quanteRipRicorsiva(stringa,let);
	printf("La lettera '%c' compare %d volte ",let,quantita);
}