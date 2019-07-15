#include <stdio.h>

int main(int argc, char* argv[]){
	
	// Declarando inteiros n e m:
	int n, m;
	// Declarando matrizes N, M e O(Intersecção das duas):
	int N[100], M[100], O[200];
	// Declarando contadores;
	int i, j = 0;
	
	
	// Lendo os valores para n e m;	
	scanf("%d%d", &n, &m);
	
	
	
	// Lê os valores para N;
	for(i = 0; i < n; i++){
		
		scanf("%d", &N[i]);
	
	}
	
	
	// Lê os valores para M:
	for(i = 0; i < m; i++){
		
		scanf("%d", &M[i]);
	
	}
	
	
	
	
	// Aqui, eu divido o programa em três partes:
	// 1º - Se n é menor que m:	
	  
	if(n < m){
	
		for(i = 0; i < 2 * n; i = i + 2){
	
			O[i] = N[j];
		
			O[i + 1] = M[j];
	
			j++;
		
		}
		
		for(i = 2 * n; i < m + n; i++){
		
			O[i] = M[j];
			
			j++;
		
		}

	}
	
	// 2º - Se m é menor que n:
	
	if(m < n){
	
		for(i = 0; i < 2 * m; i = i + 2){
	
			O[i] = N[j];
		
			O[i + 1] = M[j];
	
			j++;
		
		}
		
		for(i = 2 * m; i < n + m; i++){
		
			O[i] = N[j];
			
			j++;
		
		}

	}
	
	// 3º - Se m é igual a n:
	
	if(n == m){
	
		for(i = 0; i < m + n; i = i + 2){
	
			O[i] = N[j];
		
			O[i + 1] = M[j];
	
			j++;
		
		}
	}
	
	printf("%d\n", n + m);
	
	for(i = 0; i < n + m; i++){
	
		printf("%d ", O[i]);
		
	}
	
	
	
return 0;

}
