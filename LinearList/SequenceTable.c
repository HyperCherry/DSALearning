#include <stdlib.h>
#include <stdio.h>

typedef int E;

struct List {
    E *array;
    int capacity;
    int size;
};

typedef struct List *ArrayList;

int initList(ArrayList list) {
    list->array = malloc(sizeof(E) * 10);
    if (list->array == NULL) return 0;
    list->size = 0;
    list->capacity = 10;
    return 1;
}

/**
 * 插入方法
 * 时间复杂度:O(n)
 * @param list
 * @param element
 * @param index
 * @return
 */
int insertList(ArrayList list, E element, int index) {
    if (index > list->size + 1 || index < 0) return 0;//检查非法位置
    if (list->size == list->capacity) {
        int newCapacity = list->capacity * (list->capacity >> 1);
        E *newArray = realloc(list->array, newCapacity * sizeof(E));
        if (newArray == NULL) return 0;
        list->array = newArray;
        list->capacity = newCapacity;
    }
    for (int i = list->size; i > index; --i)
        list->array[i + 1] = list->array[i];
    list->array[index] = element;
    list->size++;
    return 1;
}

void printList(ArrayList list) {
    printf("循环遍历开始\n");
    for (int i = 0; i < list->size; ++i)
        printf("%d\n", list->array[i]);
    printf("循环遍历结束\n");
}

/**
 * 删除方法
 * 时间复杂度O(n)
 * @param list
 * @param index
 * @return
 */
int deleteList(ArrayList list, int index) {
    if (index < 0 || index > list->size - 1) return 0;
    for (int i = index + 1; i < list->size; ++i)
        list->array[i - 1] = list->array[i];
    list->size--;
    return 1;
}

/**
 * 获取列表大小
 * @param list
 * @return
 */
int sizeList(ArrayList list) {
    return list->size;
}

/**
 * 获取元素
 * 时间复杂度:O(1)
 * @param list
 * @param element
 * @return
 */
int findList(ArrayList list, E element) {
    for (int i = 0; i < list->size; ++i)
        if (list->array[i] == element) return i;
    return -1;
}

/**
 * 获取指定位置元素
 * @param list
 * @param index
 * @return
 */
E *getList(ArrayList list, int index) {
    if (index < 0 || index > list->size - 1) return NULL;
    return &list->array[index];
}

int main() {
    struct List list;
    if (initList(&list)) {
        for (int i = 0; i < 30; ++i)
            insertList(&list, i * 10, i);
        deleteList(&list, 26);
        printList(&list);
        printf("%d\n", *getList(&list, 3));
        printf("%d", findList(&list, 30));
    } else {
        printf("程序初始化失败");
    }
    return 0;
}