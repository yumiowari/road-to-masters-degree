#include <stdio.h>

#include "tree.h"

int main(){
    int value, res, size, type;
    tree_t *tree = NULL;

    while(1){
        printf("1. Alocar memória para a árvore\n");
        printf("2. Inserir elemento na árvore\n");
        printf("3. Consultar o tamanho da árvore\n");
        printf("4. Remover o elemento da árvore\n");
        printf("5. Percorrer a árvore\n");
        printf("6. Desalocar a memória da árvore\n");
        printf("7. Buscar elemento na árvore\n");
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
                    case -1: printf("A árvore ainda não foi iniciada.\n"); break;
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

                res = disbranch(tree, value);

                switch(res){
                    case 0: printf("Elemento removido.\n"); break;
                    case 1: printf("Valor não encontrado.\n"); break;
                    case -1: printf("A árvore ainda não foi iniciada.\n"); break;
                }

                break;

            case 5:
                printf(
                    "Informe o tipo da impressão:\n"
                    "(0 - em ordem; 1 - pré-ordem; 2 - pós-ordem)\n"
                );

                scanf("%d", &type);

                if(showtree(tree, type) == -1){
                    printf("A árvore ainda não foi iniciada.\n");
                }

                break;

            case 6:
                if(cutdown(tree) == -1)
                    printf("A árvore ainda não foi iniciada.\n");
                else
                    printf("Memória desalocada com sucesso.\n");

                break;

            case 7:
                printf("Insira o valor a ser buscado: ");

                scanf("%d", &value);

                res = find(tree, value);

                switch(res){
                    case 0: printf("O elemento %d existe na árvore.\n", value); break;
                    case 1: printf("O elemento não foi encontrado.\n"); break;
                    case -1: printf("A árvore ainda não foi iniciada.\n"); break;
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