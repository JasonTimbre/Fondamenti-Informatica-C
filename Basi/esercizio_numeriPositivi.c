/*Scrivere un programma che chiede all'utente di inserire due interi x e y 
 e stampa tutti gli interi positivi che  sono compresi tra x ed y (estremi inclusi) 
 e che non sono divisibili per 3*/
#include <stdio.h>
int main(){
int x,y;
printf("inserisci due numeri interi\n");
scanf_s("%d %d",&x,&y);	
int start,end;

if (x<y){
	start = x;
	end = y;			//definisco massimo e minimo
}else{
	start = y;
	end = x;
}
for(int i = start;i <= end;i++){
	if(i>0 && i % 3!=0)			//ciclo che fa scorrere i vari elementi
	printf("%d ",i);
}
}