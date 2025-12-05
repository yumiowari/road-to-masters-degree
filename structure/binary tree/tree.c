#include <stdlib.h> // malloc(), free()
#include <stdio.h> // printf(), scanf()
#include <limits.h> // INT_MIN, INT_MAX

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

// O(logn)
int branch(tree_t *tree, int value){
    if(!tree)return -1;

    if(getsize(tree) == 0){
    // 1ª inserção

        tree->root = grow(value);

        if(!tree->root)return 1;
    }else{
        node_t *node = tree->root;

        // critério de inserção: busca binária
        // nota: ao inserir desta forma, os valores menores vão para a subárvore da esquerda
        //       e os valores maiores vão para a subárvore da direita. Portanto, caracteriza
        //       uma Árvore Binária de Busca (BST)
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

// O(logn)
int disbranch(tree_t *tree, int value){
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

void prune(node_t *node){
    if(!node)return;

    prune(node->left);
    prune(node->right);

    free(node);
}

int cutdown(tree_t *tree){
    if(!tree)return -1;

    prune(tree->root);

    free(tree);

    tree = NULL;

    return 0;
}

void inorder(node_t *node){
    if(!node)return;

    inorder(node->left);        // nó filho da esquerda
    printf("%d ", node->value); // nó atual
    inorder(node->right);       // nó filho da direita
}

void preorder(node_t *node){
    if(!node)return;

    printf("%d ", node->value); // nó atual
    preorder(node->left);       // nó filho da esquerda
    preorder(node->right);      // nó filho da direita
}

void postorder(node_t *node){
    if(!node)return;

    postorder(node->left);      // nó filho da esquerda
    postorder(node->right);     // nó filho da direita
    printf("%d ", node->value); // nó atual
}

int showtree(tree_t *tree, int type){
    if(!tree)return -1;

    printf("É a árvore:\n");
    switch(type){
        case 0: inorder(tree->root); break;
        case 1: preorder(tree->root); break;
        case 2: postorder(tree->root); break;

        default:
            printf("Tipo inválido.\n");

            return 1;
    }
    printf("\n");

    return 0;
}

int find(tree_t *tree, int value){
    if(!tree)return -1;

    node_t *node = tree->root;

    while(node){
        if(value > node->value)
            node = node->right;
        else if(value < node->value)
            node = node->left;
        else // value == node->value
            return 0;
    }

    return 1;
}