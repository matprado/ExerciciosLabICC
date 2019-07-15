#include <stdio.h>
void shift(int* vet, int k, int n){
	int i = 0, j = 0, a[n];
	if(k > 0){
		k = k % n;
		while(i <= n - k){
			a[i] = vet[(i + (n - k)) % n];
			i++;
		}
		while(i < n){
			a[i] = vet[(i - k + n) % n];
			i++;	
		}
	}
	else{
		k = k * (-1);
		k = k % n;
		k = k * (-1);
		while(j < n + k){
			a[j] = vet[j - k];
			j++;
		}
		while(j < n){
			a[j] = vet[j - (n + k)];
			j++;	
		}
	}		
	for(i = 0; i < n; i++){
		vet[i] = a[i];	
	} 
}	

int main(int argc, char* argv[]){
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	int vet[n];
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]);	
	}		
	shift(vet, k, n);
	for(j = 0; j < n; j++){
		printf("%d ", vet[j]);
	}
	return 0;	
}


/*if(k > 0){
		while(i <= n - k){
			a[i] = vet[i + (n - k)];
			i++;
		}
		while(i < n){
			a[i] = vet[i - k];
			i++;	
		}
	}
	else{
		while(j < n + k){
			a[j] = vet[j + k];
			j++;
		}
		while(j < n){
			a[j] = vet[j - (n + k)];
			j++;	
		}
	}*/
