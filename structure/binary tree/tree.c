#include <stdlib.h> // malloc(), free()
#include <stdio.h> // printf(), scanf()

#include "tree.h"

struct node{
    int value;

    struct node *left;  // lower than value
    struct node *right; // greater than value
};

struct tree{
    struct node *root;

    int size;
};

tree_t *plant(){
    tree_t *seed = (tree_t*) malloc(sizeof(tree_t));
    if(!seed)return NULL;
    seed->root = NULL;
    seed->size = 0;

    return seed;
}

node_t *grow(int value){
    node_t *leaf = (node_t*) malloc(sizeof(node_t));
    if(!leaf)return NULL;
    leaf->value = value;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
}

int getsize(tree_t *tree){
    return tree ? tree->size : -1;
}

// O(log n)
int branch(tree_t *tree, int value){
    if(!tree)return -1;

    if(getsize(tree) == 0){
    // 1ª inserção

        tree->root = grow(value);

        if(!tree->root)return 1;
    }else{
        node_t *node = tree->root;

        // busca binária
        while(1){
            if(node->value >= value){
            // vai para a esquerda

                if(node->left){
                    node = node->left;
                }else{
                    node->left = grow(value);

                    if(!node->left)
                        return 1;
                    else break;
                }
            }else{
            // vai para a direita

                if(node->right){
                    node = node->right;
                }else{
                    node->right = grow(value);

                    if(!node->right)
                        return 1;
                    else break;
                }
            }
        }
    }

    tree->size++;

    return 0;
}

int cut(tree_t *tree, int value){
    if(!tree)return -1;

    node_t *node = tree->root;
    node_t *prev = NULL;

    // busca binária para o nó a ser removido
    while(1){
        if(!node)return 1;
        // ^ o valor não existe na árvore.

        else if(node->value > value)prev = node, node = node->left ? node->left : NULL;
        // ^ vai para a esquerda

        else if(node->value < value)prev = node, node = node->right ? node->right : NULL;
        // ^ vai para a direita

        else if(node->value == value){
        // ^ encontrou o nó a ser removido

            // caso 1: nó folha
            if(!node->left && !node->right){
                if(!prev){
                    tree->root = NULL; // removendo a raiz
                }else if(prev->left == node){
                    prev->left = NULL;
                }else{
                    prev->right = NULL;
                }

                free(node);
                tree->size--;

                return 0;
            }

            // caso 2: nó com 1 filho
            if((!node->left && node->right) || (node->left && !node->right)){
                node_t *child = node->left ? node->left : node->right;

                if(!prev){
                    tree->root = NULL; // ...
                }else if(prev->left == node){
                    prev->left = child;
                }else if(prev->right == node){
                    prev->right = child;
                }

                free(node);
                tree->size--;

                return 0;
            }

            // caso 3: nó com 2 filhos
            if(node->left && node->right){
                // encontra o sucessor (menor nó da subárvore da direita)
                node_t *succ_parent = node;
                node_t *succ = node->right;

                while(succ->left){
                    succ_parent = succ;
                    succ = succ->left;
                }

                node->value = succ->value;
                // nota: não precisa verificar se o nó a ser removido é o nó raiz
                //       uma vez que o nó não é removido diretamente, mas somente
                //       substituído pelo sucessor na subárvore na direita.

                // remove o nó sucessor da árvore
                if(succ_parent->left == succ)
                    succ_parent->left = succ->right;
                else
                    succ_parent->right = succ->right;

                free(succ);
                tree->size--;

                return 0;
            }
        }
    }
}