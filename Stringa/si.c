#include <stdio.h>
#include <string.h>

/*Una funzione C funzioneStringhe1
che riceve come parametro una stringa e restituisce il numero di sottostringhe "si" presenti nella
stringa. Ad esempio, se la stringa parametro è "si123sisiabcsi a", allora la funzione restituisce 4, poiché
la stringa contiene 4 sottostringhe "si". */
int contaSi(char * str) {
	int ris = 0;	//variabile per il risultato
	int i = 0;	//variabile contatore
	while(str[i]!='\0') {
		if(str[i] == 's' && str[i+1] == 'i' ) {
			ris++;
			i++;
		}
		else
			i++;
	}
	return ris;
}
/*ricorsiva*/
int contaSiRic(char* str) {
	if(strlen(str) == 0) 
		return 0;
	else {
		if(str[0] == 's' && str[1] == 'i')
			return 1 + contaSi(str+2);
		else
			return contaSiRic(str+1);
	}
}

int main() {
	char str[20];
	printf("Dammi una stringa\n");
	fgets(str,20,stdin);
	str[strlen(str)-1] = '\0';
	printf("La parola si e' stata ripetuta %d volte.",contaSiRic(str));
}