#ifndef TREE_H
#define TREE_H

typedef struct node node_t;
typedef struct tree tree_t;

tree_t *plant();
// função para alocar a memória da árvore binária
//
// retorna
// ponteiro para o nó raiz - sucesso
// nulo - memória insuficiente/falha interna

int getsize(tree_t *tree);
// função para acessar a quantidade de elementos na árvore
//
// retorna -1 em caso de erro (árvore não alocada)

int branch(tree_t *tree, int value);
// função para inserir um elemento na árvore binária
//
// retorna...
// 0 - sucesso
// 1 - memória insuficiente
// -1 - árvore não iniciada

int cut(tree_t *tree, int value);
// função para remover um elemento da árvore binária
//
// retorna...
// 0 - sucesso
// 1 - valor não encontrado
// -1 - árvore não iniciada

#endif // TREE_H