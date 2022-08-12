#include<stdio.h>
#include<stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct ListNode *Node;

void initList(Node head) {
    head->next = NULL;
    head->prev = NULL;
}

/**
 * 插入元素
 * 时间复杂度O(n)
 * @param head
 * @param element
 * @param index
 * @return
 */
_Bool insertList(Node head, E element, int index) {
    if (index < 0) return 0;
    while (index--) {
        head = head->next;
    }
    Node node = malloc(sizeof(struct ListNode));
    node->element = element;
    if (head->next) {
        node->next = head->next;
        node->next->prev = node;
    } else {
        node->next = NULL;
    }
    head->next = node;
    node->prev = head;
    return 1;
}

void printList(Node head) {
    do {//do-while内的内容至少会被执行一次
        head = head->next;
        printf("%d -> ", head->element);
    } while (head->next != NULL);
    printf("\n");
    do {
        printf("%d -> ", head->element);
        head = head->prev;
    } while (head->prev != NULL);
}

int main() {
    struct ListNode head;
    initList(&head);
    for (int i = 0; i < 5; ++i)
        insertList(&head, i * 100, i);
    printList(&head);
}