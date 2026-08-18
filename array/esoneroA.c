#include <stdio.h>
/*funzione che 
verifica se ci sono almeno 2 interi
 pari in una sequenza la cui la somma sia divisibile per 7*/
int verificaSequenza(int seq[],int l){
	int verifica;  //variabile di verifica
	for(int i=0;i<l-2;i++){
		while(seq[i]%2==0 && seq[i+1]%2==0 || seq[i+2]%2==0){
			if(seq[i]+seq[i+1]==seq[i+2]%7==0 || seq[i]+seq[i+2]==seq[i+1]%7==0 || seq[i+1]+seq[i+2]==seq[i]%7==0)
				verifica=1;
			else
				verifica=0;
		}
	}
	return verifica;


	
}
int main(){
	//acquisizione sequenza
	int lung;
	printf("Caro utente,quanti numeri vuoi introdurre?\n");
	scanf_s("%d",&lung);
	int sequenza[lung];

for(int i=0;i<lung;i++){
	printf("inserisci numero\n");
	scanf_s("%d",&sequenza[i]);
}
int verificata=verificaSequenza(sequenza,lung);
printf("%d",verificata);
}