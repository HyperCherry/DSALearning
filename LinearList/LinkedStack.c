#include<stdio.h>
#include<stdlib.h>

typedef int E;

struct ListNode{
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

void initStack(Node head){
    head->next=NULL;
}

_Bool pushStack(Node head,E element){
    Node node = malloc(sizeof(struct ListNode));
    if(node == NULL) return 0;
    node->next = head->next;
    head->next=node;
    node->element=element;
    return 1;
}

void printStack(Node head){
    printf("| ");
    head = head->next;
    while (head){
        printf("%d ", head->element);
        head = head->next;
    }
    printf("\n");
}

E popStack(Node head){
    Node top = head->next;
    head->next = top->next;
    E e = top->element;
    free(top);
    return e;
}

_Bool isEmpty(Node head){
    return head->next == NULL;
}

int main(){
    struct ListNode head;
    initStack(&head);
    for (int i = 0; i < 3; ++i) {
        pushStack(&head, i*100);
    }
    printStack(&head);
    while(!isEmpty(&head)){
        printf("%d  ", popStack(&head));
    }
}