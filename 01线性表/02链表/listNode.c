#include <stdio.h>
#include <stdlib.h>

/* 定义链表结构体 */
typedef int E;

struct listNode {
    E element;
    struct listNode *next;
};

typedef struct listNode *list;

/*
*   brief: 初始化
*/
int initList(list head)
{
    head->next = NULL;

    return 0;
}

/*
*   brief: 链表插入
*/
int insertList(list head, E element, int index)
{
    /* 参数判断 */
    if (index < 1)
    {
        return -1;
    }
    
    /* 寻找要插入的前继节点 */
    while (--index)
    {
        head = head->next;
        if (head == NULL)
        {
            return -2;
        } 
    }
    
    list node = (list)malloc(sizeof(struct listNode));\
    if (node == NULL)
    {
        return -1;
    }
    node->element = element;
    node->next = head->next;
    head->next = node;

    return 0;
}

/*
*   brief: 链表删除
*/
int deleteList(list head, int index)
{
    /* 参数判断 */
    if (index < 1)
    {
        return -1;
    }

    /* 寻找要删除的前继节点 */
    while (--index)
    {
        head = head->next;
        if (head == NULL)
        {
            return -2;
        } 
    }

    /* 删除节点位置为空 */
    if (head->next == NULL)
    {
        return -3;
    }
    
    list tmp = head->next;
    head->next = head->next->next;
    free(tmp);

    return 0;
}

/*
*   brief: 获取链表指定位置元素
*/
E* getListElement(list head, int index)
{
    /* 参数判断 */
    if (index < 1)
    {
        return NULL;
    }

    head = head->next;

    while (--index)
    {
        head = head->next;
        if (head == NULL)
        {
            return NULL;
        }    
    }
    
    return &head->element;
}

/*
*   brief: 获取链表指定元素的位置
*/
int getListIndex(list head, E element)
{
    int index = 0;
    
    while (head->next != NULL)
    {
        head = head->next;
        index++;
        if (head->element == element)
        {
            return index;
        }
    }
    
    return -1;
}

/*
*   brief: 获取链表长度
*/
int getListSize(list head)
{
    int size = 0;

    while (head->next != NULL)
    {
        head = head->next;
        size++;
    }
    
    return size;
}

/*
*   brief: 打印链表
*/
void printList(list head)
{
    int count = 0;
    /* 头节点为空 */
    head = head->next;
    while (head)
    {
        printf("%d ", head->element);
        head = head->next;
        count++;
    }
    printf("\n");
    printf("listNode amount is %d.\n", count);
}

/*
*   brief: 初始化，用于测试程序
*/
int main(void)
{
    struct listNode head;

    if (initList(&head) == 0)
    {
        insertList(&head, 111, 1);
        insertList(&head, 222, 2);
        insertList(&head, 333, 3);
        printList(&head);
        printf("wanted element in %d.\n", getListIndex(&head, 212));
        printf("liseNode amount is %d.\n", getListSize(&head));

        E *element = getListElement(&head, 4);
        if (element)
        {
            printf("element is %d\n", *element);
        }
        deleteList(&head, 3);
        printList(&head);
    } else 
    {
        printf("listNode init failed!\n");
    }
    
}