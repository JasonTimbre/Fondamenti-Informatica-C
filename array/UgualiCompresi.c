/* INPUT: array di interi a, inter l (lunghezza)
   PRE :l>=3
   OUTPUT:intero risultato(boolean)
   POST: risultato = vero se esiste una tripla in cui la somma di  almeno
    due elementi è compresa tra 10 e 20 e esattamente due sono uguali altrimenti falso
	TIPO DI PROBLEMA:  verifica esistenziale1*/
#include <stdio.h>
int proprieta(int x,int y,int z){
	return (
			((x+y>=10 && x+z<=20)||
			 (x+z>=10 && x+z<=20)||))
			 (y+z>=10 && y+z<=20)||			
			 (x+y>=10 && x+z<=20)||
			 (x+y+z>=10 && x+y+z<=20))
			 
			((x==y && x!=z)||
			 (x==z && x!=y)||
			 (y==z && y!=x)
			 ) 	;

int ugualiCompresi(int a[],int 1){
	int i=0;
	int ris=0;
	while(i<l-2 && !ris)
		if(proprieta(a[i],a[a+1],a[a+2]))
			ris=1;
		else i++;
	return ris;

}

int main (){
int l,i;
printf("lunghezza array?\n");
scanf_s("%d",&l);
int a[l];
printf("scrivo i %d elementi\n",l);
for(i=0;i<l;i++)
	scanf_s("%d",&a[i]);
if (ugualiCompresi(a,l))
	printf("esiste una tripla che contien due interi .....\n");
else
	printf("NON esiste una tripla che contiene due intere.....\n");















}