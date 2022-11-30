#include <stdio.h>
#include <stdlib.h>

/* 初始化线性表结构体 */
typedef int E;

struct list {
    E *array;           /* 线性表底层数组 */
    int capacity;       /* 线性表容量 */
    int size;           /* 线性表元素数量 */
};

typedef struct list * listArray;

/*
*   brief: 初始化
*/
int initList(listArray list)
{
    list->array = (E *)malloc(sizeof(E) * 10);
    if (list->array == NULL)
    {
        return -1;
    }
    list->capacity = 10;
    list->size = 0;

    return 0;
};

/*
*   brief: 插入元素
*/
int insertList(listArray list, E element, int index)
{
    /* 判断index是否在list内，[1, list->capacity] */
    if (index < 1 || index > list->size + 1)
    {
        return -1;
    }
    /* 判断list是否超过容量 */
    if (list->size == list->capacity)
    {
        E *newArray = (E *)realloc(list->array, sizeof(E) * list->capacity * 2);
        if (newArray == NULL)
        {
            return -2;
        }
        list->array = newArray;
        list->capacity *= 2; 
    }
    
    /* 先将数据后移一位 */
    for (int i = list->size; i > index - 1; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = element;
    list->size++;

    return 0;
}

/*
*   brief: 删除元素
*/
int deleteList(listArray list, int index)
{
    /* 判断是否在list内部 */
    if (index < 1 || index > list->size)
    {
        return -1;
    }
    
    /* 将数组前移一位 */
    for (int i = index; i < list->size; i++)
    {
        list->array[i - 1] = list->array[i];
    }
    list->size--;

    return 0;
}

/*
*   brief: 获取list长度
*/
int getListSize(listArray list)
{
    return list->size;
}

/*
*   brief: 获取list指定位置元素
*/
E* getListElement(listArray list, int index)
{
    /* 参数判断 */
    if (index < 1 || index > list->size)
    {
        return NULL;
    }
    
    return &(list->array[index-1]);
}

/*
*   brief: 获取list指定元素的位置
*/
int findListIndex(listArray list, E element)
{
    /* 参数判断 */
    if (list == NULL)
    {
        return -1;
    }
    
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == element)
        {
            return i+1;
        }
    }
    
    return 0;
}

/*
*   brief: 打印线性表内容
*/
void printList(listArray list)
{
    if (list == NULL || list->size == 0)
    {
        printf("linear list is null!");
    }

    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

/*
*   brief: 测试函数
*/
int main(void)
{
    struct list list;
    if (initList(&list) == 0)
    {
        for (int i = 1; i <= 30; i++)
        {
            insertList(&list, i, i);
        }
        printList(&list);
        printf("list size: %d\n", list.size);

        deleteList(&list, 10);    
        printList(&list);
        printf("list size: %d\n", list.size);
    } else
    {
        printf("liner list init failed!");
    }
    
}

