#include <stdio.h>

#define n 10

int main(){

	int i, j, cont, menor, aux=0;
	int vector[n]={9,8,7,6,0,5,3,4,2,1};

	for(i = 0; i < n - 1; i++){
		menor = vector[i];
		for(j = i + 1; j < n; j++){
			if(vector[menor] > vector[j]){
			menor = j;
			}
		}
		if(vector[i] != vector[menor]){
			aux = vector[i];
			vector[i] = vector[menor];
			vector[menor] = aux;
		} 
	}
	i = 0;
	for(i = 0; i < n; i++){
	printf("%d	" ,vector[i]);
	} 

} 

