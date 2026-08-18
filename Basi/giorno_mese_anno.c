#include <stdio.h>
/*GIORNO MESE ANNO
-------------------------

Scrivere un'applicazione 
GiornoMeseAnno che chiede all'utente di inserire 3 interi g,
 m ed a da tastiera, li legge e stampa un messaggio che 
 informa l'utente su quale sia il giorno successivo al giorno
  g del mese m dell'anno a 
  (ad esempio se l'utente introduce g= 31, m = 10 ed a =2016,
   il messaggio stampato deve essere del tipo "1/11/2016").*/
int main(){
	
    int g,m,a;
	printf("inserisci tre interi\n");
    scanf_s("%d%d%d",&g,&m,&a);
    if(g <= 31 && m <= 12){
        if(g<31)
            g++;
        printf("%d%d%d",g,m,a);
    }

}