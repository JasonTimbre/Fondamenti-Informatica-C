#include<stdio.h>
int main() {
	/* INPUT */
	int seq[10];
	printf("Inserisci dieci numeri\n")
	for(int i = 0;i<10;i++) 
		scanf_s("%d",&seq[i]);

	/* OUTPUT */
	for(int i = 9;i>=0;i--)
		printf("%d ",seq[i]);
}
