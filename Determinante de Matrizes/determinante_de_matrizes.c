#include <stdio.h>

int determinante(int ordem, int mat[ordem][ordem]){
	int det;
	if(ordem == 1)
		det = mat[0][0];
	else if(ordem == 2){
		det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);	
	}
	else if(ordem == 3){
		det = (mat[0][0] * mat[1][1] * mat[2][2]) + (mat[0][1] * mat[1][2] * mat[2][0]) + (mat[0][2] * mat[1][0] * mat[2][1]) - (mat[0][2] * mat[1][1] * mat[2][0]) - (mat[0][0] * mat[1][2] * mat[2][1]) - (mat[0][1] * mat[1][0] * mat[2][2]);	
	}		
	return det;
}	

int main(int argc, char* argv[]){
	int ordem, i, j;
	scanf("%d", &ordem);
	int MATRIZ[ordem][ordem];
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			scanf("%d", &MATRIZ[i][j]);
		}
	}
	printf("%d\n", determinante(ordem, MATRIZ));	
	
	return 0;	
}
