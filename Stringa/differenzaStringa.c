#include<stdio.h>
#include<string.h>
	 /*funzione che restituisce la differenza fra due caratteri
	 	che appartengono alla stringa*/

int differenzaNumerici(char* stringa) {
	int i = 0; //var contatore
	int maxDif=-1;	//per il risultato
		/*controllo uno ad uno*/

	while(stringa[i]!='\0'){
		/*verifico se contiene numerici*/
		if(stringa[i]>='0' && stringa[i]<='9'){
			int primo = stringa[i] - '0';
			/*cerca il prossimo numero, ma solo se NON ci sono
				altri numeri in mezzo*/
			int j = i + 1;
			int trovatoAltroNumero = '0';

		while(stringa[j]!='\0' && !(stringa[j]>='0' && stringa[j]<='9')) {
			if(stringa[j]>='0' && stringa[j]<='9'){
			int secondo = stringa[j] -'0';
			int diff = secondo - primo;
			if(diff < maxDif)
				maxDif = diff;
		}
	}
	i++;
}
	return maxDif;
}
}


/*Funzione principale*/
int main() {
	char stringa[50];
	/*input*/
	printf("Dammi una bella stringa: ");
	fgets(stringa,50,stdin);
		/*elimina \n*/
	stringa[strlen(stringa)-1] = '\0';

	/*output*/
	int risultato = differenzaNumerici(stringa);
	if(risultato>=0)
		printf("La differenza tra i due caratteri numerici e': %d\n", risultato);
	else
		printf("Non ci sono caratteri numerici!!");
 }