#include<stdio.h>
#include<string.h>
/*funzione che controlla se carattere è minuscolo*/
int isMinuscolo(char a){
	if(a>='a' && a<='z')
		return 1;
	else 
		return 0;
}
/*funzione che cancella ogni sequenza di esattamente 
	due caratteri minuscoli uguali consecutivi*/
void cancellaDueMinuscoliUguali(char* str){
	int i=0;	//indice str
	int j=0;	//indice new
	char new[50];	//stringa di supporto

	while(str[i]!='\0'){
		/*se trovo minuscola*/
		if(isMinuscolo(str[i])){
			/*conto quanti caratteri uguali*/
			int start = i;
			int count = 0;
			while(isMinuscolo(str[i])){
				i++;
				count++;
			}
			if(count==2 && str[start]==str[start+1]){
				continue;	//salto la coppia
			}
			for(int k = start;k<start+count;k++)
				new[j++]=str[k];
		}
		else{
			new[j] = str[i];
			i++;
			j++;
		}	
	}
	new[j]='\0';
	strcpy(str,new);
}




int main(){
	char stringa[50];
	printf("Dammi una stringa: ");
	fgets(stringa,50,stdin);
	stringa[strlen(stringa)-1]='\0';

	cancellaDueMinuscoliUguali(stringa);
	printf("La stringa modificata e':%s",stringa);
}