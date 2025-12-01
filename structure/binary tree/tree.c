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
        node_t *aux = tree->root;

        // busca binária
        while(1){
            if(aux->value >= value){
            // vai para a esquerda

                if(aux->left){
                    aux = aux->left;
                }else{
                    aux->left = grow(value);

                    if(!aux->left)
                        return 1;
                    else break;
                }
            }else{
            // vai para a direita

                if(aux->right){
                    aux = aux->right;
                }else{
                    aux->right = grow(value);

                    if(!aux->right)
                        return 1;
                    else break;
                }
            }
        }
    }

    tree->size++;

    return 0;
}