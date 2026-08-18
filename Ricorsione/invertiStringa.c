#include<stdio.h>
#include<string.h>

/*	Scrivere un programma che prende in 
	input una stringa non nulla di caratteri e modifica la stringa mettendo
 	i caratteri in ordine invertito, attraverso una funzione ricorsiva.  */

void invertiStringa(char* str1,int i,int l) {
	char temp;
	if(l==-1)
		l=(strlen(str1)-1);

	/* CASO BASE */
	if(i==l/2) {
		temp = str1[i];
		str1[i] = str1[i+1];
		str1[i+1] = temp;
		printf("%c,%c\n",temp,str1[i]);
	}
	/* PASSO RICORSIVO */
	else {
		temp = str1[i];
		str1[i] = str1[l-i];
		str1[l-i] = temp;
		printf("%c,%c\n",temp,str1[i]);
		invertiStringa(str1,++i,l);
	}
		
}

int main() {
	char stringa[]="ciao";
	invertiStringa(stringa,0,-1);
	printf("%s",stringa);
}