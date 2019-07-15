
#include <stdio.h>

int main(int argc, char **argv)
{
	int a1, a2, b1, b2, c1, c2;
	
	scanf("%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2);
	
	if (a1 > 6 || a2 > 6 || b1 > 6 || b2 > 6 || c1 > 6 || c2 > 6) {
		
		printf("Alguem trapaceou nesse jogo\n");
		
		}
		
	else {
		
	int soma_a = a1 + a2;
	
	int soma_b = b1 + b2;
	
	int soma_c = c1 + c2;
	
	
	if (soma_a > soma_b && soma_a > soma_c) {
		
		if (soma_b > soma_c){
			
			printf("Andreia\nBruno\nCristina\n");
		}
		
		if (soma_c > soma_b){
			
			printf("Andreia\nCristina\nBruno\n");
		}
	}	
		
	if (soma_b > soma_c && soma_b > soma_a) {
		
		if (soma_a > soma_c){
			
			printf("Bruno\nAndreia\nCristina\n");
		}
		
		if (soma_c > soma_a){
			
			printf("Bruno\nCristina\nAndreia\n");
		}
	}
	if (soma_c > soma_b && soma_c > soma_a) {
		
		if (soma_b > soma_a){
			
			printf("Cristina\nBruno\nAndreia\n");
		}
		
		if (soma_a > soma_b){
			
			printf("Cristina\nAndreia\nBruno\n");
		}
	}
	
}
	return 0;
}

