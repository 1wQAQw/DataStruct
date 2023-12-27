#ifndef __COMMON_H_
#define __COMMON_H_

#if 1
#define ELEMENTTYPE void*
#else
typedef void * ELEMENTTYPE;
#endif 

/* 避免头文件重复包含 */
typedef struct dynamicArray
{
    ELEMENTTYPE *data;  /* 数组的空间 */
    int len;            /* 数组的大小 */
    int capacity;       /* 数组的容量 */
} dynamicArray;

/* 链表结点取别名 */
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;

    struct DoubleLinkNode * prev;
    
    /* 指向下一个结点的指针 */
    struct DoubleLinkNode *next;  /* 指针的类型为什么是结点 */
    /* data */
}DoubleLinkNode;

/* 链表 */
typedef struct DoubleLinkList
{
    /* 链表的虚拟头节点 */
    DoubleLinkNode *head;
    DoubleLinkNode *tail;         /* 为什么尾指针不需要分配空间 */
    /* 链表长度 */
    int len;
}DoubleLinkList;

#endif  //__COMMON_H_