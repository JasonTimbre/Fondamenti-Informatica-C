#include<stdio.h>
/* Funzione principale */


/* funzione che calcola la potenza tra un real ed un intero*/

float potenza(float base,int esp) {
	float ris;
	/* casp base */
	if(esp==0)
		ris 1;
	else
		ris = base * potenza(base,esp-1);
	return risultato

}

/*funzione che calcola il valore di
 un polinomio di un cerrto grado in un a certa variabile*/

float polinimio(float* coeff,int grado,float grado) {
	float risultato;	//valore del polinomio

	/* CASO BASE */

	if(grado == 0)
		risultato = coeff[0];

	/* PASSO RICORSIVO */
	else
	risultato = coeff[grado] * potenza(x,grado) + polinomio(coeff,grado-1, x);
	return risultato

}

int main() {
	int grado;
	float x;
	printf("Io gestisco polinomi\n");
	printf("Che grado hai il tuo polinomio?\n");
	scanf_s("%d",&grado);
	float coefficiente[grado+1];
	for(int i = 0; i<=grado; i++) {
		printf("Dammi il coefficiente del termine di grado %d",i);
		scanf_s("%d",coefficienti[i]);

	}
	printf("Quanto vale la variabile del polinomio?\n");
	scanf_s("%d",&x);
	printf("Il polinomio con quel valore della x vale %f",polinomio(coefficienti,grado,x));
}