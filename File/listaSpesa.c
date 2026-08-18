#include<stdio.h>
#include <string.h>

/* Programma per creare una lista della spesa */
int main() {
	FILE *fp = fopen("Lista della spesa.txt","w");
	int fine = 0;		//hai finito la lista?
	char articolo[80];	//un articolo da comprare
	int numero;			//quantità
	while(!fine) {
		printf("Che articolo vuoi comprare? ");
		fgets(articolo,80,stdin);
		articolo[strlen(articolo)-1] = '\0';
		fprintf(fp,"%s",articolo);
		printf("Quanti te ne servono?	 ");
		scanf_s("%d%*c", &numero);
		fprintf(fp,"%d\n",numero);
		printf("FINITO(1= SI, 0= NO)?");
		scanf_s("%d%*c",&fine);
	}
	fclose(fp);
}