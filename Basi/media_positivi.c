/*programma che ripetutamente chiede all'utente
di inserire un numero intero. 
La prima volta che
l'utente introduce un intero non positivo, 
il programma termina stampando la media (come valore reale)
dei numeri precedentemente introdotti.*/
#include <stdio.h>	
int main(){	

int x ;			//numero intero richiesto
int sum=0;		//variabile somma	
int count=0;	//variabile contatore	

printf("inserisci un numero intero\n");
scanf_s("%d",&x);		//acquisisco il numero
while(x>0){
	sum+=x;				//aumento e assegno la somma ad x
	count++;
	printf("inserisci un altro numero\n");
	scanf_s("%d",&x);
}
if(count>0){
	float media = (float)sum / count;	//calcolo la media
	printf("la media dei numeri inseriti e' %f\n",media);

}
else
	printf("non hai inserito numeri positivi");

}
	






