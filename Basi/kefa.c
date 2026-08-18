#include <stdio.h>
#include <math.h>
//pre: n>0

int main(int argc, char **argv){
int x; int y;
int k; int z; 
printf("Scrivi un numero >0\n");
scanf_s("%d", &x);
y = 2;
k = 0;
z = (int)sqrt(x);
while (!k && (y<=z)){
	if (x%y== 0)
	k = 1;
	y = y +1;
}
	if (k==1)
		printf("NON e' PRIMO");
	else 
	printf("E' PRIMO");
	return 0;
}