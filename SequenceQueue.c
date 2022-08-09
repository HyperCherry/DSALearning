#include<stdio.h>
#include<stdlib.h>

typedef int E;

struct Queue {
    E *array;
    int capacity;
    int front, rear;
};

typedef struct Queue *ArrayQueue;

_Bool initQueue(ArrayQueue queue) {
    queue->array = malloc(sizeof(E) * 10);
    if (queue->array == NULL) return 0;
    queue->capacity = 10;
    queue->rear = queue->front = 0;
    return 1;
}

_Bool offerQueue(ArrayQueue queue, E element) {
    if ((queue->rear + 1) % queue->capacity == queue->front) return 0;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    return 1;
}

void printQueue(ArrayQueue queue) {
    printf(">>>");
    int i = queue->front;
    while (i != queue->rear) {//先移动，再查询
        i = (i + 1) % queue->capacity;
        printf("%d ", queue->array[i]);
    }
    printf(">>>");
}

_Bool isEmpty(ArrayQueue queue) {
    return queue->rear == queue->front;
}

E poolQueue(ArrayQueue queue) {
    queue->front = (queue->front + 1) % 10;
    return queue->array[queue->front];
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 5; ++i) {
        offerQueue(&queue, i * 100);
    }
//    printQueue(&queue);
    printf(">>>");
    while (!isEmpty(&queue)) {
        printf("%d ", poolQueue(&queue));
    }
    printf(">>>");
}