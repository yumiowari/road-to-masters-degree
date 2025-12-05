#include <stdio.h> // printf(), scanf()
#include <limits.h> // INT_MIN
#include <stdbool.h> // true, false

#define STACK_S 10

typedef struct stack_t{
    int stack[STACK_S];
    int top;
}stack_t;

// O(1)
int push(stack_t *s, int v){
    if(s->top + 1 == STACK_S)return INT_MIN;

    s->stack[++s->top] = v;

    return INT_MAX;
}

// O(1)
int pop(stack_t *s){
    return s->top == -1 ? INT_MIN : s->stack[s->top--];
}

// O(1)
bool isempty(stack_t s){
    return s.top >= 0 ? false : true;
}

void printstack(stack_t s){
    if(s.top == 1){
        printf("A pilha está vazia.\n");

        return;
    }

    printf("É a pilha: ");
    for(int i = 0; i <= s.top; ++i)
        printf("%d ", s.stack[i]);
    printf("\n");
}

int main(){
    stack_t stack;
    stack.top = -1;
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