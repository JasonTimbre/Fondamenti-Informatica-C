#include <stdio.h>
//Specifica:input:array d'interi e dimensione, 
//pre:dimensione>=0, output:vero/falso, 
//post: esiste elemento che è pari alla somma o prodotto degli altri due
//altri due
//problema universale
int sommaProdottoTre(int* arr,int lung) {
	/*caso base*/
	if(lung<3)
		return 1;
	/* passo ricorsivo */
	else {
		if(	(arr[1] + arr[2] == arr[0] || arr[0] + arr[2] == arr[1] || arr[0] + arr[1] == arr[2]) || 
			(arr[1] * arr[2] == arr[0] || arr[0] * arr[2] == arr[1] || arr[0] * arr[1] == arr[2]) )
			return  sommaProdottoTre(arr+1,lung-1);
		/*caso d'insuccesso*/
		else
			return 0;

	}
}

int main() {
	int lung;
	printf("Quanti interi da inserire?: ");
	scanf_s("%d",&lung);

	int arr[lung];
	for(int i = 0; i<lung; i++) {
		printf("Inserisci intero: ");
		scanf_s("%d",&arr[i]);
	}
	if(sommaProdottoTre(arr,lung))
		printf("istanza positiva.");
	else
		printf("istanza negativa.");

}