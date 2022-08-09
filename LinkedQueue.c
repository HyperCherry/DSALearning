#include<stdio.h>
#include<stdlib.h>

typedef int E;

struct LNode {
    E element;
    struct LNode *next;
};

typedef struct LNode *Node;

struct Queue {
    Node front, rear;
};

typedef struct Queue *LinkedQueue;

_Bool initQueue(LinkedQueue queue) {
    Node node = malloc(sizeof(struct LNode));
    if (node == NULL) return 0;
    queue->front = queue->rear = node;
    return 1;
}

_Bool offerQueue(LinkedQueue queue, E element) {
    Node node = malloc(sizeof(struct LNode));
    if (node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

void printQueue(LinkedQueue queue) {
    printf(">>>");
    Node node = queue->front->next;
    while (node != NULL) {
        printf("%d ", node->element);
        node = node->next;
    }
    printf(">>>");
}

_Bool isEmpty(LinkedQueue queue) {
    return queue->front == queue->rear;
}

E pollQueue(LinkedQueue queue) {
    E e = queue->front->next->element;
    Node node = queue->front->next;
    queue->front = queue->front->next;
    if (queue->rear == node) queue->rear = queue->front;
    return e;
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 10; ++i) {
        offerQueue(&queue, i * 10);
    }
//    printQueue(&queue);
    printf(">>>");
    while (!isEmpty(&queue)) {
        printf("%d ", pollQueue(&queue));
    }
    printf(">>>");
}