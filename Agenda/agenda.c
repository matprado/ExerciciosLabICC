#include <stdio.h>
#include <stdlib.h>

// defino o tipo pessoa, que é uma struct:
typedef struct pessoa{
	char *nome;
	double altura;
	double peso;
	char genero;
	int id;
}pessoa;
// chamadas das funções;
char* readline();
void imc();

// função imc recebe a pessoa e imprime seu imc e sua classificação;
void imc(pessoa p){
	double IMC = p.peso / (p.altura * p.altura);
	printf("%lf\n", IMC);
	if(p.genero == 'F'){
		if(IMC < 19.1)	printf("Abaixo do peso\n");
		else if(19.1 <= IMC && IMC < 25.8) 	printf("Peso ideal\n");
		else if(25.8 <= IMC && IMC < 27.3) 	printf("Pouco acima do peso\n");
		else if(27.3 <= IMC && IMC < 32.3) 	printf("Acima do peso\n");
		else printf("Obesidade\n");
	}else{
		if(IMC < 20.7)	printf("Abaixo do peso\n");
		else if(20.7 <= IMC && IMC < 26.4) 	printf("Peso ideal\n");
		else if(26.4 <= IMC && IMC < 27.8) 	printf("Pouco acima do peso\n");
		else if(27.8 <= IMC && IMC < 31.1) 	printf("Acima do peso\n");
		else printf("Obesidade\n");
	}		
}
// função readline lê uma string até o \n
char* readline(){
	char* vet = NULL;
	int i = 0;
	char c;
	do{
		vet = (char*)realloc(vet, sizeof(char) * ++i);
		c = getchar();
		vet[i-1] = c;
	}while(vet[i-1] != '\n' && vet[i-1] != '\r');
	vet[i-1] = '\0';
	return vet; 	
}			
int main(){
	int n, i;
	scanf("%d ", &n);
	pessoa *vet = NULL;
	vet = (pessoa *) malloc(n * sizeof(pessoa));
	// lê os dados de cada pessoa;
	for(i = 0; i < n; i++){
		vet[i].nome	= readline();
		scanf("%lf %lf ", &vet[i].altura, &vet[i].peso);
		scanf("%c ", &vet[i].genero);
		scanf("%d ", &vet[i].id);
	}	
	int ids = 0;
	pessoa auxiliar;
	while(ids >= 0){
		scanf("%d", &ids);
		if(ids == -1) break;
		for(i = 0; i < n; i++){
			if(vet[i].id == ids)
				auxiliar = vet[i];
		}	
		printf("%s\n", auxiliar.nome);
		imc(auxiliar);
	}	
	free(vet);
	return 0;
}
