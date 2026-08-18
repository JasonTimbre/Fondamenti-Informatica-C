#include <stdio.h>	
#include<math.h>
#include<stdlib.h>

////////////STRUTTURE
typedef struct Vertice {
	float x;
	float y;
} VERT;

typedef Parallelogramma {
	VERT bs;
	VERT ad;
	float base;

} PARA;

/////////FUNZIONI GEOMETRICHE

/*Calcolo altezza del parallelogramma INPUT: PARA; OUTPUT: float*/

float altezza(PARA *p){
	return(p->ad.y-p->bs.y)
}

float lato(PARA *p){
	float b1=p->ad.x-p->base-p->bs.x;
	float h=altezza(p);
	return(sqrt(b1*b1+h*h));
}

float area(PARA *p){
	return p->base*altezza(p);
}

float perimetro(PARA *p){
	return p->base*2 + lato(p)*2;
}

/*VERIFICA SE UN PARALLELOGRAMMA è UN RETTANGOLO*/

int isRettangolo(PARA*p){
	return p->ad.x-p->base == p->bs.x;
} 
///creazione parallelogramma

void leggiParallelogramma(PARA*p){
	printf("coordinate del vertice in basso a sinistra: ");
	scanf_s("%f%f",&(p->bs.x),&(p->bs.y));
	printf("coordinate vel vertice in basso a destra: ");
	scanf_s("%f%f",&(p->bs.x),&(p->ad.y));
	printf("luunghezza della base: ");
	scanf_s("%f",&(p->base));
}
/////visualizzazione parallelogramma
void visualizzazaParallelogramma(PARA*p){
	printf("Vertice in basso a sinistra: ");
	printf("(%.2f,%.2f)\n",p->bs.x,p->bs.y);
	printf("Vertice in basso a destra: ");
	printf("(%.2f,%.2f)\n",p->ad.x,p->ad.y);
	printf("lunghezza della base: ");
	printf("%.2f\n",p->base);
	

		
}


//////MAIN PROGRAM
int main(){
	int dimensione=1; //dimensione dell'array
	int quanti;  //quanti elementi sono effettivamente presenti nell'array
	PARA *seq;

	seq = malloc(dimensione*sizeof(PARA));
	leggiParallelogramma(seq)
}