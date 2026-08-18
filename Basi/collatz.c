/*
INPUT numero intero positivo
PRE	 ...
OUTPUT numero intero 
POST ...
*/



#include <stdio.h>
int main(){
	int a;
	 printf("Caro utente, inserisci un numero positivo\n");
	 scanf_s("%d",&a);
	if (a%2==0){
		while(a>=1)
		a = a/2;
		printf("%d\n",a);
}
	else{ 
	a = a * 3 + 1;
	printf("%d",a);		

}
	
}