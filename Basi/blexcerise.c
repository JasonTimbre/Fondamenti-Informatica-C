#include <stdio.h>
 int main(){

 	int x, bl;
 	printf("introduci il valore di x:\n");
 	scanf_s("%d", &x);
 	bl = (x % 5 != 0) && (x>=10 && x<=100) && (x % 4 == 0);

 	printf("il risultato booleano e'\n%d",bl);

return 0;
}
/*Considera il seguente codice
int x, bl;
printf("Introduci il valore di x: ");
scanf("%d", &x);
bl = ...;
Al posto dei puntini scrivi un'espressione booleana che esprime il fatto che un numero x non è
divisibile per 5, è compreso tra 10 e 100 ed è un multiplo di 4*/