/*Scrivi un programma che chiede all'utente di inserire
un numero intero n e stampa i primi n interi 
della sequenza di Fibonacci. 
La sequenza di Fibonacci 1,1,2,3,5,8,13,21,34... 
è tale che i primi due numeri della sequenza sono pari ad 1 ed ogni 
altro numero è pari alla somma dei due precedenti.*/

#include <stdio.h>
int main(){
 int n;
    printf("Inserisci il numero di elementi della sequenza di Fibonacci: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Inserire un numero positivo.\n");
        return 0;
    }

    int a = 1, b = 1;

    if (n >= 1) printf("%d ", a); // stampa il primo numero
    if (n >= 2) printf("%d ", b); // stampa il secondo numero

    for (int i = 1; i <= n - 2; i++) {
        int c = a + b;   // calcola il nuovo numero
        printf("%d ", c); // stampa il nuovo numero
        a = b;           // aggiorna a
        b = c;           // aggiorna b
    }

    printf("\n");
    return 0;
}