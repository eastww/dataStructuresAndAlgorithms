#include <stdio.h>
#include <stdlib.h>

/* 定义双向链表结构体 */
typedef int E;

struct listNode {
    E element;
    struct listNode *next;
    struct listNode *prev;
};

typedef struct listNode *list;

/*
*   brief: 初始化
*/
int initList(list head)
{
    head->next = NULL;
    head->prev = NULL;

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
    
    list node = (list)malloc(sizeof(struct listNode));
    if (node == NULL)
    {
        return -1;
    }
    node->element = element;

    if (head->next != NULL)
    {
        head->next->prev = node;
        node->next = head->next;
    } else
    {
        node->next = NULL;
    }

    head->next = node;
    node->prev = head;

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
    if (head->next->next != NULL)
    {
        head->next = head->next->next;
        head->next->prev = head;
    } else
    {
        head->next = NULL;
    }
    free(tmp);

    return 0;
}

/*
*   brief: 打印链表
*/
void printList(list head)
{
    int count = 0;
    /* 顺序打印 */
    while (head->next)
    {
        head = head->next;
        printf("%d ", head->element);
        count++;
    }
    printf("\n");
    printf("listNode amount is %d.\n", count);

    /* 逆序打印 */
    while (head->prev)
    {
        printf("%d ", head->element);
        head = head->prev;
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

        deleteList(&head, 3);
        printList(&head);
    } else 
    {
        printf("listNode init failed!\n");
    }
    
}