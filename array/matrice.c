#include <stdio.h>	

int main(){

	int i,j;
	int r,c; //numero di righe e colonne

	printf("Quante righe ha la matrice?\n");
	scanf_s("%d",&r);
	printf("Quante colonne ha la matrice?\n");
	scanf_s("%d",&c);

	int m[r][c];

	//lettura dei dati	

	for(i=0;i<r;i++){
		printf("Scrivi i dati della riga %d ",i);
		for(j=0;j<c;j++)
			scanf_s("%d",&m[i][j]);
		printf("\n");
	}

//stampa dei dati dei dati	
	printf("ecco la matrice letta\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++) //stampa la riga i-esima
			printf("%d ",m[i][j]);
		printf("\n");


}
} 	