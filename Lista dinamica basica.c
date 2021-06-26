#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct no{
	int dado;
	struct no *prox;
};
//--------------
typedef struct no *pont;
pont navegador;
int op;
//-------------
void mostrar(pont arg);
void inserir(pont arg);
void remover(pont arg);
void menu();
//programa
int main(){
	
	srand(time(NULL));
	
	navegador = (pont) malloc(sizeof(struct no));
	navegador->dado = 0;
	navegador->prox = NULL;
	
	while(op != 3){
		
		mostrar(navegador);
		menu();
		
		switch(op){
			case 1: inserir(navegador);
				break;
			case 2: remover(navegador);
				break;
			case 3:	
				break;
			default: printf("\n Resposta invalida, por favor insira uma resposta valida...\n\n");
					system("pause");
				break;	
		}		
	}
	
	return 0;
}
//Funções****************
void menu(){
	
	printf("\n****************************************\n \n 1-Inserir dado na lista    2-Remover dado da lista\n         3-Sair \n\n Resposta: ");
	scanf("%d", &op);
	fflush(stdin);
	printf("\n\n");
}
//------------------------
void inserir(pont arg){
	
	while(arg->prox != NULL){
		
		arg = arg->prox;
	}
	
	arg->prox = (pont) malloc(sizeof(struct no));
	arg = arg->prox;
	arg->dado = rand()%100;
	arg->prox = NULL;
	
	system("cls");
}

//------------------------
void mostrar(pont arg){
	
	while(arg->prox != NULL){
		
		printf(" %d;", arg->dado);
		
		arg = arg->prox;
	}
	
	printf(" %d;", arg->dado);
	printf("\n");
}
//------------------------
void remover(pont arg){
	
	int d;
	pont antecessor;
	
	printf("\nQual dado deseja remover? ");
	scanf("%d", &d);
	fflush(stdin);
	
	while(arg->dado != d){
		
		if(arg->prox != NULL){		
		
			antecessor = arg;
			arg = arg->prox;
		}
		else
		{
			printf("\nNAO ENCONTRADO\n");
			system("pause\n");
			break;
		}
	}
	
	if(arg->dado == d)
	{
		
		antecessor->prox = arg->prox;
		free(arg);
	}

	
	system("cls");
}

