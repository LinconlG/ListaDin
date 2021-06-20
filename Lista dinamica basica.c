#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct no {
	int dado;
	struct no *prox; //Apontará para o proximo nó
};

typedef struct no *pont; // "ponteiro do tipo no" faz a alocação dinâmica na memória para cada novo elemento da lista.
pont procura; // "variavel do tipo ponteiro" A partir dela poderemos navegar do primeiro ao último elemento, fazer remoções e inserções.

int op;


//Prototipando
void inserir(pont procura);
void remover(pont procura);
void mostrar(pont procura);
void menu();

//PROGRAMA******
int main(){
	srand(time(NULL));  //inicializa a função de numeros aleatorios
	procura = (pont) malloc(sizeof(struct no));
	procura->dado = 0;  //primeiro dado [VARIAVEL GLOBAL (1)]
	procura->prox = NULL;
	
	while(op != 4){
		
		menu();
		
		switch(op){
			case 1: inserir(procura);
				break;
			case 2: remover(procura);
				break;
			case 3: mostrar(procura);
				break;
			case 4:	
				break;
			default: printf("\n Resposta invalida, por favor insira uma resposta valida...\n\n");
					system("pause");
				break;	
		}		
	}
	
	
	return 0;
}



//FUNÇÕES***

void menu(){
	
	printf("\n\n****************************************\n \n 1-Inserir dado na lista    2-Remover dado da lista\n 3-Mostrar lista            4-Sair \n\n Resposta: ");
	scanf("%d", &op);
	fflush(stdin);
	system("cls");
	printf("\n\n");
}

//---------------------------------
void inserir(pont procura){ /* Teoria= A variavel global(1) é diferente da do escopo da função(2): quando altera 2, o 1 NÃO é alterado [por valor], porém a variavel é um ponteiro e
								 dentro da função é alocado um lugar na memória para cada dado inserido, por meio de endereços e não variaveis, são acessados.*/
	while(procura->prox != NULL){
		
		procura=procura->prox;
	}
	
	procura->prox=(pont) malloc(sizeof(struct no));
	procura = procura->prox;
	printf("\n...\n");
	procura->dado = rand()%100;
	procura->prox=NULL;
	printf("\nINSERIDO\n\n ");
	system("pause");
	system("cls");
}
//-------------------------------
void remover(pont procura){
	int d;
	pont atual;
	printf("\nQual dado deseja remover? ");
	scanf("%d", &d);	
	fflush(stdin);
	
	atual = (pont) malloc(sizeof(struct no));
	
	while(procura->dado != d){
		
		if(procura->prox == NULL){
			break;
		}
		
		atual = procura;
		procura = procura->prox;
	}
	
	if(procura->dado == d){

		atual->prox=procura->prox;
	}	
}
//------------------------------
void mostrar(pont procura){
	
	while(1){
		
		printf(" %d; ", procura->dado);
		if(procura->prox == NULL){
			break;
		}
		procura = procura->prox;
	}
	printf("\n\n");
	system("pause");
}
