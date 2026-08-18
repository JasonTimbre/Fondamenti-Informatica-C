#include<stdio.h>
#include<string.h>
/*funzione che rende maiuscoli tutti i caratteri 
 di una stringa*/

void rendiMaiuscoli(char* stringa) {
	for(int i = 0;stringa[i]!= '\0';i++)
		if(stringa[i]>='a' && stringa[i]<='z')
			stringa[i]= stringa[i]-32;
}

/*funzione che rende tutti */
int main() {

	/*input*/
	char stringa [50];
	printf("Dammi una stringa: ");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1]='\0';	

	/* output */

	rendiMaiuscoli(stringa);
	printf("La stringa modificata e' : %s", stringa);
}