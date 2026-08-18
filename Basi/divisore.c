#include <stdio.h>
int main(){
/* Scrivi un programma che legge due numeri interi introdotti dall'utente e stampa un messaggio che
informa l'utente del quoziente (senza parte decimale) e del resto della divisione intera fra il primo ed il
secondo numero. Ovvero il programma deve contenere: a) un'istruzione di stampa, in cui viene chiesto
all'utente di introdurre due numeri interi; b) una o due istruzioni di lettura, in cui vengono letti due
numeri interi introdotti dall'utente; tali numeri vengono memorizzati in due variabili di tipo int; c)
un'istruzione di stampa che informa l'utente sul quoziente ed il resto della divisione intera fra il primo ed
il secondo numero. Ad esempio, se i numeri introdotti dall'utente sono 13 e 5, il programma deve
stampare una frase del tipo "La divisione intera fra 13 e 5 ha quoziente 2 e resto 3!".
Il quoziente della divisione intera fra due numeri interi x ed y può essere ottenuto dall'espressione x / y,
mentre il resto della divisione intera fra due numeri interi x ed y può essere ottenuto dall'espressione x
% y.*/


int x ; 
int y ;
printf("inserisci due numeri:\n");
scanf_s("%d",&x);
scanf_s("%d",&y);

int quoziente = x / y ;
int resto = x % y ;
printf("il risulato della divisione e':\n""%d\n",quoziente);
printf("mentre il resto e':\n""%d",resto);


}


