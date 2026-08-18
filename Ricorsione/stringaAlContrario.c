#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void invertiStringa(char* str,int i,int j) {
	/* Caso base */
	if(strlen(str)==1)
		return;
		/* Passo Ricorsivo*/
	else{
		if(i<=j){
			invertiStringa(str,i+1,j-1);
			char temp = str[i];
			str[i] = str[j];
			str[j] = temp;
		}
	}
}
int main() {
	char stringa[] = "cane";
	invertiStringa(stringa,0,strlen(stringa)-1);
	printf("%s",stringa);
}