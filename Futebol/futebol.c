#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* readfile();
void le_linha();
int procurar_time();
void atribuir_valores();
void quem_venceu();
void quem_perdeu();

typedef struct time{
	char* nome;
	int pontos;
	int gols_feitos;
	int gols_sofridos;
	int vitorias;
	int jogos;
}time; 

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
	if(vet[i-1] == '\r') getchar();
	vet[i-1] = '\0';
	return vet; 	
}

char* readfile(FILE *fpr){
	char* vet = NULL;
	int i = 0;
	char c;
	do{
		vet = (char*)realloc(vet, sizeof(char) * ++i);
		c = fgetc(fpr);
		vet[i-1] = c;
	}while(vet[i-1] != '\n' && vet[i-1] != '\r' && vet[i-1] != '#' && vet[i-1] != EOF);
	if(vet[i-1] == '\r') fgetc(fpr);
	vet[i-1] = '\0';
	return vet; 	
}	

void le_linha(time *vet, int equipes, FILE *fpr){
	char *selecao;
	int gols1, gols2;	
	selecao = readfile(fpr);
	int primeira = procurar_time(selecao, vet, equipes);
	fscanf(fpr, "%d", &gols1);
	fgetc(fpr);	//FSEEK	
	fscanf(fpr, "%d", &gols2);
	fgetc(fpr);
	//printf("selecao1: %s\n", selecao);
	//printf("1: %d\n", primeira);
	selecao = readfile(fpr);
	//printf("selecao2: %s\n", selecao);
	int segunda = procurar_time(selecao, vet, equipes);
	//printf("2: %d\n", segunda);
	atribuir_valores(vet, primeira, segunda, gols1, gols2);
}	

int procurar_time(char* selecao, time *vet, int equipes){
	int i;
	for(i = 0; i < equipes; i++){
		if(!strcmp(selecao, vet[i].nome)){
			return i;
		}	
	}
	return -1;	
}	

void atribuir_valores(time *vet, int primeira, int segunda, int gols1, int gols2){	
	vet[primeira].jogos++;
	vet[primeira].gols_feitos += gols1;
	vet[primeira].gols_sofridos += gols2;
	vet[segunda].jogos++;
	vet[segunda].gols_feitos += gols2;
	vet[segunda].gols_sofridos += gols1;
	if(gols1 > gols2){
		vet[primeira].vitorias++;
		vet[primeira].pontos += 3;	
	}
	else if(gols2 > gols1){
		vet[segunda].vitorias++;
		vet[segunda].pontos += 3;
	}
	else{
		vet[primeira].pontos += 1;
		vet[segunda].pontos += 1;	
	}		
}	

void quem_venceu(time *vet, int equipes){
	time maior = vet[0];
	int i;
	for(i = 1; i <= equipes-1; i++){
		if(vet[i].pontos > maior.pontos){
			maior = vet[i];	
		}
		else if(vet[i].pontos == maior.pontos){
			if(vet[i].vitorias > maior.vitorias){	
				maior = vet[i];		
			}
			else if(vet[i].vitorias == maior.vitorias){
				if((vet[i].gols_feitos - vet[i].gols_sofridos) > (maior.gols_feitos - maior.gols_sofridos)){
					maior = vet[i];		
				}
				else if((vet[i].gols_feitos - vet[i].gols_sofridos) == (maior.gols_feitos - maior.gols_sofridos)){
					if(vet[i].gols_feitos > maior.gols_feitos){
						maior = vet[i];		
					}
					else if(vet[i].gols_feitos == maior.gols_feitos){
						if(vet[i].jogos < maior.jogos){
							maior = vet[i];	
						}
						else if(vet[i].jogos == maior.jogos){
							if(strcmp(vet[i].nome, maior.nome) < 0){
								maior = vet[i];	
							}	
						}
					}	
				}	
			}	
		}	
	}
	printf("%s\n", maior.nome);	
}

void quem_perdeu(time *vet, int equipes){
	time maior = vet[0];
	int i;
	for(i = 1; i <= equipes-1; i++){
		if(vet[i].pontos < maior.pontos){
			maior = vet[i];	
		}
		else if(vet[i].pontos == maior.pontos){
			if(vet[i].vitorias < maior.vitorias){
				maior = vet[i];		
			}
			else if(vet[i].vitorias == maior.vitorias){
				if((vet[i].gols_feitos - vet[i].gols_sofridos) < (maior.gols_feitos - maior.gols_sofridos)){
					maior = vet[i];		
				}
				else if((vet[i].gols_feitos - vet[i].gols_sofridos) == (maior.gols_feitos - maior.gols_sofridos)){
					if(vet[i].gols_feitos < maior.gols_feitos){
						maior = vet[i];		
					}
					else if(vet[i].gols_feitos == maior.gols_feitos){
						if(vet[i].jogos > maior.jogos){
							maior = vet[i];	
						}
						else if(vet[i].jogos == maior.jogos){
							if(strcmp(vet[i].nome, maior.nome) > 0){
								maior = vet[i];	
							}	
						}
					}	
				}	
			}	
		}	
	}
	printf("%s\n", maior.nome);	
}

int main(int argc, char *argv[]){
	char *arquivo = readline();
	int equipes;
	scanf("%d ", &equipes);
	//printf("%d\n", equipes);
	time vet[equipes];
	int i;
	for(i = 0; i < equipes; i++){
		vet[i].nome = readline();
		//printf("%s\n", vet[i].nome);
		vet[i].jogos = 0;
		vet[i].pontos = 0;
		vet[i].gols_feitos = 0;
		vet[i].gols_sofridos = 0;
		vet[i].vitorias = 0;
	}
	int jogos;
	scanf("%d", &jogos);
	//printf("%d jogos\n", jogos);
	FILE *fpr = NULL;
	if((fpr = fopen(arquivo, "r")) == NULL){
		printf("ERRO\n");	
	}
	for(i = 0; i < jogos; i++){
		le_linha(vet, equipes, fpr);
	}
	quem_venceu(vet, equipes);
	quem_perdeu(vet, equipes);
	fclose(fpr);
	return 0;
}	
