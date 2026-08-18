#include<stdio.h>
#include<string.h>
/*funzione che verifica se il carattere è un numero*/
int isNumber(char c){
	if(c>='0' && c<='9')
		return 1;
	else
		return 0;
}
/*funzione che rimuove ogni sequenza di esattamente
due caratteri numerici consecutivi*/
void nienteNumeriDueCifre(char* s1) {
	char s2[50];
	int i = 0;
	int j = 0;
	while(s1[i]!='\0'){
		/*se 2 consecutivi sono numeri*/
		if(isNumber(s1[i]) && isNumber(s1[i+1]))
			i+=2;  	

		else{
			s2[j] = s1[i];
			i++;
			j++;
		}
	}
	s2[j]='\0';
	strcpy(s1,s2);	

}

int main(){
	char str1[50];
	printf("Dammi stringa: ");
	fgets(str1,50,stdin);
	str1[strlen(str1)-1] = '\0';

	nienteNumeriDueCifre(str1);
	printf("La stringa moficata e' :%s",str1);
}
