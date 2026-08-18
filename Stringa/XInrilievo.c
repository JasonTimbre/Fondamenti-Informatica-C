#include<stdio.h>
#include<string.h>

void XinRilievo(char* str1,char* str2) {
	int i = 0;	//var contatore str1
	int j = 0;	//var contatore str2
	/*scorro la lista fino a carattere terminatore*/
	while(str1[i]!='\0') {
		/*se trovo la X*/
		if(str1[i]=='X'){
			str2[j]=str1[i];
			i++;
			j++;
			if(str1[i] == str1[i+1]){
				str2[j]= ' ';	
				j++;
			}

		}
		else {
			i++;
		}
	}
	str2[j] = '\0';	
}	




int main() {
	char str1[50];
	char str2[50];
	printf("Dammi una stringa: ");
	fgets(str1,50,stdin);
	str1[strlen(str1)-1] = '\0';
	XinRilievo(str1,str2);
	printf("La stringa modificata e' la seguente: %s",str2);
}