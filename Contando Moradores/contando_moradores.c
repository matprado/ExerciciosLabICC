#include <stdio.h>
#include <stdlib.h>
int** aloca_matriz(int n, int m){
	int** condominio = NULL;
	condominio = (int**) calloc(n, sizeof(int*));
	int i;
	for(i = 0; i < n; i++){
		condominio[i] = (int*) calloc(m, sizeof(int)); 	
	}
	return condominio;	
}
void desaloca_matriz(int n, int** condominio){
	int i;
	for(i = 0; i < n; i++){
		free(condominio[i]);
	}
	free(condominio);		
}	
void update(int** condominio, int i, int j){
	condominio[i][j] += 1;		
}	
int main(){
	int n, m, q, count, i, j, a, b;
	scanf("%d%d%d", &n, &m, &q);
	int** condominio = aloca_matriz(n, m);
	for(count = 0; count < q; count++){
		scanf("%d%d", &i, &j);
		if(i < n && i >= 0 && j < m && j>= 0)
			update(condominio, i, j);	
	}
	for(a = 0; a < n; a++){
		for(b = 0; b < m; b++){
			printf("%d ", condominio[a][b]);	
		}
		printf("\n");		
	}			
	desaloca_matriz(n, condominio);
	return 0;
}
