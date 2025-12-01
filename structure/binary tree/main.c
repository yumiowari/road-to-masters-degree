#include <stdio.h>

#include "tree.h"

int main(){
    tree_t *tree = NULL;

    while(1){
        printf("1. Alocar memória para a árvore\n");
        printf("2. Inserir elemento na árvore\n");
        printf("3. Consultar o tamanho da árvore\n");
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
                printf("Insira o valor: ");
                int value; scanf("%d", &value);

                int res = branch(tree, value);

                switch(res){
                    case 0: printf("Elemento inserido.\n"); break;
                    case 1: printf("Memória insuficiente.\n"); break;
                    case -1: printf("A árvore ainda não foi alocada.\n"); break;
                }

                break;

            case 3:
                int size = getsize(tree);

                if(size >= 0)
                    printf("A árvore possui %d elementos.\n", size);
                else
                    printf("A árvore ainda não foi iniciada.\n");

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