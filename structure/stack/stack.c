#include <stdio.h> // printf(), scanf()
#include <limits.h> // INT_MIN
#include <stdbool.h> // true, false

#define STACK_SIZE 100

typedef struct stack_t{
    int stack[STACK_SIZE];
    int qty;
}stack_t;

int push(stack_t *s, int value){
    if(s->qty == STACK_SIZE)return INT_MIN;

    // right shift
    for(int i = s->qty; i > 0; --i)
        s->stack[i] = s->stack[i - 1];

    s->stack[0] = value;

    s->qty++;

    return INT_MAX;
}

int pop(stack_t *s){
    if(s->qty == 0)return INT_MIN;

    int value = s->stack[0];

    // left shift
    for(int i = 0; i < s->qty; ++i)
        s->stack[i] = s->stack[i + 1];

    s->qty--;

    return value;
}

bool isempty(stack_t s){
    return s.qty > 0 ? false : true;
}

void printstack(stack_t s){
    if(s.qty == 0){
        printf("A pilha está vazia.\n");

        return;
    }

    printf("É a pilha: ");
    for(int i = 0; i < s.qty; ++i)
        printf("%d ", s.stack[i]);
    printf("\n");
}

int main(){
    stack_t stack;
    stack.qty = 0;
    int op;
    int value;

    while(1){
        printf("1. Empilhar elemento\n");
        printf("2. Desempilhar elemento\n");
        printf("3. Verificar altura\n");
        printf("4. Exibir pilha\n");
        printf("\n0. Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Insira o elemento: ");
                scanf("%d", &value);

                if(push(&stack, value) == INT_MAX)
                    printf("Elemento inserido.\n");
                else
                    printf("A pilha está cheia.\n");

                break;

            case 2:
                value = pop(&stack);

                if(value > INT_MIN)
                    printf("É o elemento no topo da pilha: %d\n", value);
                else
                    printf("A pilha está vazia.\n");

                break;

            case 3:
                if(isempty(stack) == true)
                    printf("A pilha está vazia.\n");
                else
                    printf("Há elementos na pilha.\n");

                break;

            case 4:
                printstack(stack);

                break;

            case 0:
                printf("Encerrando aplicação...\n");

                return 0;

            default:
                printf("Opção inválida.\n");

                break;
        }
    }

    return 0;
}