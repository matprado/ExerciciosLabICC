
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	double res = 0, true_cos, x, erro;
	int sinal = 1;
	int i, j, n, fat;
	
	scanf("%d %lf", &n, &x);
	
	for (i = 0; i < n; i++){
		
		fat = 1;
		
		for (j = 2 * i; j > 1; j--){
			
			fat = fat * j;
			
		}
		
		res = res + pow(x, (2 * i)) * sinal / fat;
		
		sinal = sinal * (-1);		
		
	}
	
	true_cos = cos(x);
	
	if(true_cos > res){
		
		erro = true_cos - res;
		
	}
		
	else {
		
		erro = res - true_cos;
		
	}	
	
	printf("%.6lf\n%.6e\n", res, erro);
	
	return 0;
}

