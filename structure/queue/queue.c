#include <stdio.h> // printf(), scanf()
#include <limits.h> // INT_MIN
#include <stdbool.h> // true, false

#define QUEUE_SIZE 100

typedef struct queue_t{
    int queue[QUEUE_SIZE];
    int qty;
}queue_t;

int push(queue_t *q, int value){
    if(q->qty == QUEUE_SIZE){ // tratamento circular
        for(int i = 0; i < q->qty; ++i) // left shift
            q->queue[i] = q->queue[i + 1];

        q->qty--;
    }

    q->queue[q->qty++] = value;

    return INT_MAX;
}

int pop(queue_t *q){
    if(q->qty == 0)return INT_MIN;

    int value = q->queue[0];

    for(int i = 0; i < q->qty; ++i) // left shift
        q->queue[i] = q->queue[i + 1];

    q->qty--;

    return value;
}

bool isempty(queue_t q){
    return q.qty > 0 ? false : true;
}

void printqueue(queue_t q){
    if(q.qty == 0){
        printf("A fila está vazia.\n");

        return;
    }

    printf("É a fila: ");
    for(int i = 0; i < q.qty; ++i)
        printf("%d ", q.queue[i]);
    printf("\n");
}

int main(){
    queue_t queue;
    queue.qty = 0;
    int op;
    int value;

    while(1){
        printf("1. Enfileirar elemento\n");
        printf("2. Desenfileirar elemento\n");
        printf("3. Verificar comprimento\n");
        printf("4. Exibir fila\n");
        printf("\n0. Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Insira o elemento: ");
                scanf("%d", &value);

                if(push(&queue, value) == INT_MAX)
                    printf("Elemento inserido.\n");
                else
                    printf("A fila está cheia.\n");

                break;

            case 2:
                value = pop(&queue);

                if(value > INT_MIN)
                    printf("É o elemento na frente da fila: %d\n", value);
                else
                    printf("A fila está vazia.\n");

                break;

            case 3:
                if(isempty(queue) == true)
                    printf("A fila está vazia.\n");
                else
                    printf("Há elementos na fila.\n");

                break;

            case 4:
                printqueue(queue);

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