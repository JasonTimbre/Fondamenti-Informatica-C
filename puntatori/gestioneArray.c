#include<stdio.h>	
#include<stdlib.h>
void modificaX(int*punta) {
	*punta=7;
}

int main() {
	int x;
	modificaX(&x);
	printf("Valore x:%d", x);
	


}