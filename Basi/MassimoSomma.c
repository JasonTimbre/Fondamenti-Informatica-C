/*Scrivere un'applicazione MassimoSomma che ripetutamente chiede
all'utente di scrivere numeri interi positivi. Quando l'utente inserisce un
numero negativo o nullo, l'applicazione termina indicando all'utente qual è il
massimo fra i numeri inseriti e qual è la loro somma*/
#include <stdio.h>
int main(){
	int massimo,somma,num;
	int i;


	printf("Caro utente scrivi un numero\n");
	scanf_s("%d",&num);

	somma=0;
	massimo=num;

	while(num>0){
		if(num>massimo)
			massimo=num;
		somma=somma + num;
		printf("scrivi un altro numero\n");
		scanf_s("%d",&num);
	}

	if(massimo<=0)
		printf("Ok, facciamo un'altra volta!\n");
	else{
		printf("la somma dei numeri letti e' %d ",somma);
		printf("il massimo  dei numeri letti e' %d ",massimo);
	}

	


}