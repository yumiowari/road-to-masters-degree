#include <stdio.h>

#include "tree.h"

int main(){
    int value, res, size;
    tree_t *tree = NULL;

    while(1){
        printf("1. Alocar memória para a árvore\n");
        printf("2. Inserir elemento na árvore\n");
        printf("3. Consultar o tamanho da árvore\n");
        printf("4. Remover o elemento da árvore\n");
        printf("\n0. Sair\n");
        printf("Escolha: ");

        int op; scanf("%d", &op);

        switch(op){
            case 1:
                tree = plant();

                if(!tree)
                    printf("Não havia memória disponível.\n");
                else
                    printf("Memória alocada com sucesso.\n");

                break;

            case 2:
                printf("Insira o valor a ser inserido: ");
                scanf("%d", &value);

                res = branch(tree, value);

                switch(res){
                    case 0: printf("Elemento inserido.\n"); break;
                    case 1: printf("Memória insuficiente.\n"); break;
                    case -1: printf("A árvore ainda não foi alocada.\n"); break;
                }

                break;

            case 3:
                size = getsize(tree);

                if(size >= 0)
                    printf("A árvore possui %d elementos.\n", size);
                else
                    printf("A árvore ainda não foi iniciada.\n");

                break;

            case 4:
                printf("Insira o valor a ser removido: ");
                scanf("%d", &value);

                res = cut(tree, value);

                switch(res){
                    case 0: printf("Elemento removido.\n"); break;
                    case 1: printf("Valor não encontrado.\n"); break;
                    case -1: printf("A árvore ainda não foi alocada.\n"); break;
                }

                break;

            case 0: 
                printf("Encerrando aplicação...\n");

                return 0;

            default:
                printf("Opção inválida.\n");

                break;
        }
    }
}