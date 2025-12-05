#include <stdio.h> // printf(), scanf()
#include <limits.h> // INT_MIN
#include <stdbool.h> // true, false

#define QUEUE_S 100

typedef struct queue_t{
    int queue[QUEUE_S];
    int front;
    int rear;
}queue_t;

// 0(1)
void enqueue(queue_t *q, int v){
    q->queue[q->rear] = v;

    int next = (q->rear + 1) % QUEUE_S;

    if(next == q->front)q->front = (q->front + 1) % QUEUE_S;

    q->rear = next;
}

// 0(1)
bool isempty(queue_t q){
    return q.front == q.rear;
}

// 0(1)
int dequeue(queue_t *q){
    if(isempty(*q))return INT_MIN;

    int v = q->queue[q->front];

    q->front = (q->front + 1) % QUEUE_S;

    return v;
}

void printqueue(queue_t q){
    if(isempty(q)){
        printf("A fila está vazia.\n");

        return;
    }

    printf("É a fila: ");
    int i = q.front;
    while (i != q.rear) {
        printf("%d ", q.queue[i]);
        i = (i + 1) % QUEUE_S;
    }

    printf("\n");
}

int main(){
    queue_t queue;
    queue.front = 0;
    queue.rear = 0;
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

                enqueue(&queue, value);

                printf("Elemento inserido.\n");

                break;

            case 2:
                value = dequeue(&queue);

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