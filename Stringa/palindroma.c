#include<stdio.h>
#include<string.h>

int palindroma(char* stringa) {
	int palindromi = 1;
	int i = 0;
	int j = strlen(stringa)-1;
	for(i;i<=j;i++) {
		printf("i=%c ,j=%c ",stringa[i],stringa[j]);
		if(stringa[i]!=stringa[j]){
			palindromi = 0;	
		}
		j--;
		}
	return palindromi;
}

int main() {
	char string[] = "abcba"; 
	int risposta = palindroma(string);
	printf("%d",risposta);
	return 0;
}
