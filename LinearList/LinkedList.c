#include<stdio.h>
#include<stdlib.h>

typedef int E;

struct listNode {
    E element;
    struct listNode *next;
};

typedef struct listNode *Node;

void initList(Node node) {
    node->next = NULL;
}

/**
 * 插入方法
 * 时间复杂度O(n)
 * @param head
 * @param element
 * @param index
 * @return
 */
_Bool insertList(Node head, E element, int index) {
    if (index < 0) return 0;
    for (int i = 0; i < index; ++i) {
        head = head->next;
        if (head == NULL) return 0;
    }
    Node node = malloc(sizeof(struct listNode));
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

/**
 * 删除方法
 * 时间复杂度O(n)
 * @param head
 * @param index
 * @return
 */
_Bool deleteList(Node head, int index) {
    if (index < 0) return 0;
    for (int i = 0; i < index; ++i) {
        head = head->next;
        if (head == NULL) return 0;
    }
    Node temp = head->next;
    head->next = head->next->next;
    free(temp);
    return 1;
}

void printList(Node head) {
    while (head->next) {
        head = head->next;
        printf("%d\n", head->element);
    }
}

/**
 * 获取元素
 * 时间复杂度O(n)
 * @param head
 * @param index
 * @return
 */
E *getList(Node head, int index) {
    for (int i = 0; i < index + 1; ++i) {
        head = head->next;
        if (head == NULL) return NULL;
    }
    return &head->element;
}

int findList(Node head, E element) {
    int i = 0;
    while (head != NULL) {
        if (head->element == element) return i - 1;//将位序变更为次序
        head = head->next;
        i++;
    }
    return i;
}

int sizeList(Node head) {
    int i = 0;
    while (head->next) {
        head = head->next;
        i++;
    }
    return i;
}

int main() {
    struct listNode head;
    initList(&head);
    for (int i = 0; i < 3; ++i) {
        insertList(&head, i * 100, i);
    }
    deleteList(&head, 1);
    printList(&head);
    printf("结果为:%d\n", *getList(&head, 1));
    printf("%d\n", findList(&head, 100));
    printf("%d", sizeList(&head));
}