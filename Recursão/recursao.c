#include <stdio.h>

int soma(int *vet, int n){
	if(n+1 == 0)	return 0;
	n--;
	return (vet[n+1] + soma(vet, n));
}

/*int soma(int *vet, int n){
	if(n == 0)	return 0;
	--n;
	return (vet[n+1] + soma(vet, n));
}*/

long int potencia(int n, int p){
	if(p == 0)	return 1;
	return n * potencia(n, --p);	
}	

int main(int argc, char *argv[]){
	int n, p, i;
	scanf("%d%d", &n, &p);	
	int vet[n];
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]);	
	}
	int somatoria = soma(vet, n-1);	
	printf("Soma: %d\n", somatoria);
	printf("Potencias: ");
	for(i = 0; i < n; i++)
		printf("%ld ", potencia(vet[i], p));
	printf("\n");
	return 0;
}	
