#include <stdio.h>
#include <string.h>

/*funzione che mi dice se il carattere è un numero*/
int isNumber(char c){
	if(c>='0' && c<='9')
		return 1;
	else
		return 0;
}
/*funzione che cancella tutte le coppie di 
	due caratteri numerici consecutivi*/
void cancellaDueNumeriUguali(char* str, char* new){
	int i=0;
	int j=0;
	while(str[i]!='\0'){
		if(isNumber(str[i])&&isNumber(str[i+1])&&str[i]==str[i+1]){
			i+=2;	//salto la coppia
		}

		else{
			new[j]=str[i];
			i++;
			j++;
		}
	}
	new[j] = '\0';
}

int main(){
	char str1[50];
	char str2[50];
	printf("Dammi una stringa: ");
	fgets(str1,50,stdin);
	str1[strlen(str1)-1]='\0';

	cancellaDueNumeriUguali(str1,str2);
	printf("La stringa modificata e' la seguente :%s\n",str2);
}