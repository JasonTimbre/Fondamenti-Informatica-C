/*Scrivi un programma per giocare al gioco "Indovina che numero ho
pensato".
Il programma sceglie un numero intero casuale (vedi spiegazione nella
prossima pagina) compreso tra 1 e 100, estremi inclusi, e poi chiede
all'utente di indovinare il numero scelto. Dopo ogni tentativo, il
programma segnala se la risposta è giusta, oppure se il numero immesso
dall'utente è maggiore (troppo alto!) oppure minore (troppo basso!)
rispetto a quello scelto dal programma. Il programma continua a chiedere
numeri all'utente fino a che questi non abbia dato la risposta corretta o
abbia scelto di rinunciare ad indovinare, digitando il numero zero.
Inoltre, il programma conta e visualizza il numero di tentativi impiegati
dall'utente per indovinare il numero.*/

#include <stdio.h>
#include<stdlib.h>
#include <time.h>

int main(){

int n; //numero scelto dal programma
int x; //numero input  dell'utente
int i;  // variabile contatore
int tentativi=0;  //variabile numero di tentativi
srand(time(NULL));

n=rand() % 100+1;

printf("Ho pensato ad un numero compreso tra 1 e 100\n");
printf("Indovina a quale numero ho pensato!\n");
printf("Ricorda che puoi digitare 0 se vuoi smettere di giocare\n");
printf("Indovina il numero: ");
scanf_s("%d",&x);
i=0;
while(x!=n){
	if(x<n && x!=0){
		printf("%d e' troppo basso\n",x);
		printf("riprova!! \n");
		scanf_s("%d",&x); 
		tentativi++;
	}
	 else if(x>n && x!=0){
		printf("%d e' troppo alto\n",x);	
		printf("riprova!! \n");
		scanf_s("%d",&x);
		tentativi++;
	}
	else if(x==0){
		printf("Ti sei arreso!!Il numero era %d\n",n);
		printf("Ci hai provato %d volte..",tentativi);
	break;
	}
}
	if (x==n){
		printf("Hai indovinato!!! Era proprio il %d \n",n);
		printf("Hai vinto dopo %d tentativi!!\n",tentativi);
	}



}


