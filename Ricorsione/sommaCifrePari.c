#include <stdio.h>
int sommaCifrePari(int x) {
	/*caso base(se il numero ha 0 cifre)*/
	if(x<10){
		if(x%2 == 0)
			return x;
		else
			return 0;
	}
	else {
		int ultima = x % 10;	// ultima cifra
		int resto = x / 10;		//resto del numero

		if(ultima % 2 == 0)
			return ultima + sommaCifrePari(resto);
		else
			return sommaCifrePari(resto);


	}
}


int main() {
	int x;
	printf("Inserisci un numero e ti restituisco la somma delle cifre pari.\n");
	scanf_s("%d",&x);
	printf("La somma delle cifre pari e': %d ",sommaCifrePari(x));

}