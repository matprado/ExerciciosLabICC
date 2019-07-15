#include <stdio.h>

int main(int argc, char **argv)
{
	int num_1, num_2;
	
	char op;
	
	scanf("%d%d", &num_1, &num_2);
	
	scanf(" %c", &op);
	
	float divisao = num_1 / num_2;
	
	switch (op) {
		
		case '+' : 
		
			printf("%d\n", num_1 + num_2);
		
			break;
		case '-' :
		
			printf("%d\n", num_1 - num_2);
			
			break;
			
		case '*' :
		
			printf("%d\n", num_1 * num_2);
			
			break;
			
		case '/' :
		
			printf("%.0f\n", divisao);
		
			break;
			
		default: 
		
			printf("Operacao invalida\n");
		
		}
	
	return 0;
}

