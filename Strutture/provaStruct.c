#include<stdio.h>

struct Data {
	int giorno;
	int mese;
	int anno;
};

struct Persona {
	char nome[50];
	char cognome [50];
	struct Data nascita;
};

struct Punto {
	/*CAMPI	(attributi dell'oggetto)*/
	float x;	//la coordinata x
	float y;	//la coordinata y
};

struct simulArray {
	nt array[50];

};


int main() {
	struct simulArray a;
	a.array[0] = 7;
	funzione(a);
	struct Punto p;	//un punto	
	printf("Dammi le coordinate del tuo punto\n");
	scanf_s("%f%f",&(p.x), &(p.y));
	printf("Ecco il punto (%.2f,%.2f)\n",p.x, p.y);

	struct Persona p1;
	p1.nascita.giorno = 18;
	p1.nascita.mese = 03;
	p1.nascita.anno = 1997;

	printf("La data di nascita inserita e': %d/%d/%d",p1.nascita.giorno, p1.nascita.mese, p1.nascita.anno);
}


/*p è una variabile di tipo struct Punto che contiene
  le variabile x e y di tipo float*/