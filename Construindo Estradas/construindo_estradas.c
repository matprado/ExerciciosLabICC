#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	int N, Q, i, j;
	scanf("%d%d", &N, &Q);
	int X[Q], Y[Q];
	char C[Q];
	int* mat[N];
	int count[N];
	int existe;
	for(i = 0; i < N; i++){
		count[i] = 0;
		mat[i] = NULL;
	}
	for(i = 0; i < Q; i++){
		scanf(" %c %d%d", &C[i], &X[i], &Y[i]);	
		if(C[i] == 'c'){
			mat[X[i]] = (int*) realloc(mat[X[i]], (count[X[i]] + 1) * sizeof(int)); // REALLOC
			mat[Y[i]] = (int*) realloc(mat[Y[i]], (count[Y[i]] + 1) * sizeof(int)); //	REALLOC
			mat[X[i]][count[X[i]]] = Y[i]; // COLOCAR NA MATRIZ
			mat[Y[i]][count[Y[i]]] = X[i]; // COLOCAR NA MATRIZ
			count[X[i]]++;		// AUMENTA O TAMANHO	
			count[Y[i]]++;		// AUMENTA O TAMANHO
		}
		else{
			existe = 0;
			for(j = 0; j < count[X[i]]; j++){
				if(mat[X[i]][j] == Y[i]){ 
					printf("Existe uma estrada entre %d e %d.\n", X[i], Y[i]);	
					existe = 1;		
				}
			}
			if(existe == 0){ 
				printf("Nao existe uma estrada entre %d e %d.\n", X[i], Y[i]);
			}				
		}
	}
	for(i = 0; i < N; i++){
		free(mat[i]);	
	}
	return 0;
}
