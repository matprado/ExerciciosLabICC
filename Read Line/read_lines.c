#include <stdio.h>
#include <stdlib.h>

char* readline();
int equal();
int lenght();

char* readline(){
	char* vet = NULL;
	int i = 0;
	char c;
	do{
		vet = (char*)realloc(vet, sizeof(char) * ++i);
		c = getchar();
		vet[i-1] = c;
	}while(vet[i-1] != '\n');
	vet[i-1] = '\0';
	return vet; 	
}	 


int equal(char *a, char *b){
	int i = 0;
	int tamanho1 = lenght(a);
	int tamanho2 = lenght(b);
	if(tamanho1 != tamanho2){
		return 0;
	}
	while(i < tamanho1){
		if(a[i] != b[i])	return 0;
		i++;	
	}
	return 1;
}	

int lenght(char *vet){
	int tamanho = 0;
	while(vet[tamanho] != '\0'){
		tamanho++;	
	}
	return tamanho;	
}	

int main(int argc, char* argv[]){
	char *leitura1, *leitura2;
	leitura1 = readline();
	leitura2 = readline();
	int igual = equal(leitura1, leitura2);
	if(igual == 1){
		printf("Linhas 1 e 2: %s\n", leitura1);	
	}
	else{
		printf("Linha 1: %s\nLinha 2: %s\n", leitura1, leitura2);	
	}
	free(leitura1);
	free(leitura2);
	return 0;
}
