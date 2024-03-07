#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Veiculo{
	int ano;
	char montadora[30];
	char modelo[30];
	float valor;
};

struct Lista{
	Veiculo carros[20];
	int tam;
};

void iniciarLista(Lista *lista){
	lista -> tam = 0;
}

void cadastrar(Veiculo v, Lista *lista){
	if(lista -> tam >= 20){
		printf("\nLista cheia...");
		return;
	}
	
	lista -> carros[lista -> tam] = v;
	lista -> tam++;
}

void imprime(Lista lista){
	int i; 
	for(i = 0; i < lista.tam; i++){
		printf("\n\tVeiculo %d:\n", i);
		printf("\nAno: %d", lista.carros[i].ano);
		printf("\nMontadora: %s", lista.carros[i].montadora);
		printf("\nModelo: %s", lista.carros[i].modelo);
		printf("\nValor: %.2f\n", lista.carros[i].valor);
	}
}

void exclui(Lista *lista, int posicao){
	int i; 
	
	if(lista -> tam < posicao){
		printf("\nNenhum veiculo cadastrado na posicao informada.\n");
		return;
	}
	lista -> tam--;
	
	for(i = posicao; i < lista -> tam; i++){
		lista -> carros[i] = lista -> carros[i + 1];
	}
	printf("\nVeiculo %d excluido com sucesso.\n", posicao);
}

void somaAllVeiculos(Lista lista, float *soma){
	int i;
	*soma = 0;

	for(i = 0; i < lista.tam; i++){
		*soma += lista.carros[i].valor;
	}
}

void mediaAllVeiculos(Lista lista, float *media){
	int i, total = 0;
	
	for(i = 0; i < lista.tam; i++){
		total += lista.carros[i].valor;
	}
	*media = total / lista.tam;
}

void veiculoMaisCaro(Lista lista){
	int i; 
	if(lista.tam <= 0){
        printf("A lista de carros está vazia.\n");
        return;
    }

    int caro = 0;

    for(i = 1; i < lista.tam; i++){
        if(lista.carros[i].valor > lista.carros[caro].valor){
            caro = i;
        }
    }
	
	printf("\nAno: %d", lista.carros[caro].ano);
	printf("\nMontadora: %s", lista.carros[caro].montadora);
	printf("\nModelo: %s", lista.carros[caro].modelo);
	printf("\nValor: %.2f\n", lista.carros[caro].valor);
}

int veiculosMaisVinte(Lista lista){
	int quantCars = 0, i;
	
	for(i = 0; i < lista.tam; i++){
		if((2024 - lista.carros[i].ano) > 20){
			quantCars++;
		}
	}
	return quantCars;
}

int procurarMontadora(Lista lista, char montadora[]){
	int i;
	
	for(i = 0; i < lista.tam; i++){
		if(strcmp(montadora, lista.carros[i].montadora) == 0){
			return i;
		}
	}
	return -1;
}

void excluiPorModelo(Lista *lista, char modelo[]){
	int i, j; 
	int encontrado = 0;
	
    for(i = 0; i < lista -> tam; i++) {
        if (strcmp(modelo, lista -> carros[i].modelo) == 0) {
            lista->tam--;
            encontrado = 1;

            for (j = i; j < lista -> tam; j++) {
                lista -> carros[j] = lista -> carros[j + 1];
            }
            printf("\nVeiculo com modelo %s excluido com sucesso.\n", modelo);
        }
    }

    if(!encontrado) {
        printf("\nNenhum veiculo com esse modelo encontrado.\n");
    }
}

int vogalModelo(Lista lista){
	int i, j, tam;
	char vogais[] = "aeiou";
	
	for(i = 0; i < lista.tam; i++){
		tam = strlen(lista.carros[i].modelo) - 1;
		for(j = 0; j < 5; j++){
			if(lista.carros[i].modelo[tam] == vogais[j]){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	Veiculo v;
	Lista lista;
	iniciarLista(&lista);
	float soma = 0, media = 0;
	int op = 1, pos;
	char mod[30], mont[30]; 
	
	while(op != 0){
		system("cls");
		printf("1 - Cadastre um Veiculo\n2 - Exibir Veiculos Cadastrados");
		printf("\n3 - Excluir um Veiculo\n4 - Soma do Valor de Todos Veiculos");
		printf("\n5 - Media de Valor de Todos Veiculos\n6 - Veiculo Mais Caro");
		printf("\n7 - Quantidade de Veiculos com mais de 20 anos\n8 - Procurar Montadora");
		printf("\n9 - Excluir Veiculo por Modelo\n10 - Vogal na ultima letra do Modelo");
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		
		if(op > 1){
			if(lista.tam < 1){
				printf("\nNenhum Veiculo Cadastrado.\n");
				system("pause");
				continue;
			}
		}
		
		switch(op){
			case 1: {
				printf("\nDigite o Ano do Veiculo:\n");
				scanf("%d", &v.ano);
				printf("Digite a Montadora do Veiculo:\n");
				scanf("%s", &v.montadora);
				printf("Digite o Modelo do Veiculo:\n");
				scanf("%s", &v.modelo);
				printf("Digite o Valor do Veiculo:\n");
				scanf("%f", &v.valor);
				cadastrar(v, &lista);
				system("pause");
				break;
			}
			case 2: {
				imprime(lista);
				system("pause");
				break;
			}
			case 3: {
				printf("\nDigite a posicao do veiculo que deseja excluir:\n");
				scanf("%d", &pos);
				exclui(&lista, pos);
				system("pause");
				break;
			}
			case 4: {
				somaAllVeiculos(lista, &soma);
				printf("\nSoma do valor de todos veiculos: %.2f\n", soma);			
				system("pause");
				break;
			}
			case 5: {
				mediaAllVeiculos(lista, &media);
				printf("\nMedia do valor de todos veiculos: %.2f\n", media);
				system("pause");
				break;
			}
			case 6: {
				printf("\n\tVeiculo mais caro:\n");
				veiculoMaisCaro(lista);
				system("pause");
				break;
			}
			case 7: {
				veiculosMaisVinte(lista);
				printf("\nQuantidade de veiculos com mais de 20 anos: %d\n", veiculosMaisVinte(lista));
				system("pause");
				break;
			}
			case 8: {
				printf("Digite uma montadora:\n");
				scanf("%s", &mont);
				if(procurarMontadora(lista, mont) == -1){
					printf("\nNenhum ocorrencia dessa montadora.\n");
				}
				else{
					printf("\nMontadora %s encontrada com sucesso.\n", mont);
				}
				system("pause");
				break;
			}
			case 9: {
				printf("Digite um modelo:\n");
				scanf("%s", &mod);
				excluiPorModelo(&lista, mod);
				system("pause");
				break;
			}
			case 10: {
				if(vogalModelo(lista)){
					printf("\nVogal na ultima letra dos Modelos encontrado.\n");
				}
				else{
					printf("\nNenhuma vogal encontrada na ultima letra dos Modelos.\n");
				}
				system("pause");
				break;
			}
			case 0: {
				printf("\nSaindo...");
				break;
			}
			default: {
				printf("\nOpcao Invalida.\n");
				break;
			}				
		}
	}
	
	return 0;
}
