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
	int i = 0;
    /* 判断index是否在list内，[0, list->capacity] */
    if (index < 0 || index > list->capacity + 1)
    {
        return -1;
    }
    /* 判断list是否超过容量 */
    if (list->size == list->capacity)
    {
        realloc(list->array, sizeof(E) * list->capacity * 2);
        list->capacity *= 2; 
    }
    
    /* 先将数据后移一位 */
    for (i = list->size; i > index - 1; i--)
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

/*
*   brief: 打印线性表内容
*/
void printList(listArray list)
{
	int i = 0;
    if (list == NULL || list->size == 0)
    {
        printf("linear list is null!");
    }

    for (i = 0; i < list->size; i++)
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
        insertList(&list, 111, 1);
		printList(&list);
		insertList(&list, 222, 2);
		printList(&list);
		insertList(&list, 333, 3);
		printList(&list); 
    } else
    {
        printf("liner list init failed!");
    }
    
}

