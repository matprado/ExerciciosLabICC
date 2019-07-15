#include <stdio.h>

int main(int argc, char **argv){

	float c, f, k;
	/*Lê a temperatura em Kelvin*/
	scanf("%f", &k);
	c = k - 273;
	f = 9 * (k - 273) / 5 + 32;
	/*Imprime as conversões em celsius e farenheit*/
	printf("%.2f\n%.2f\n", c, f);
	return 0;
}

