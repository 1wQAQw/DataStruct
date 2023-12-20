#ifndef __LINKLIST__
#define __LINKLIST__

#define ELEMENTTYPE int

/* 链表结点取别名 */
typedef struct LinkNode
{
    ELEMENTTYPE *data;

    /* 指向下一个结点的指针 */
    struct LinkNode *ptr;  /* 指针的类型为什么是结点 */
    /* data */
}LinkNode;

/* 链表 */
typedef struct LinKList
{
    /* 链表的虚拟头节点 */
    LinkNode *head;

    /* 链表长度 */
    int len;
}LinkList;

/* 链表初始化 */
int LinkListInit();

/* 链表头插 */
int LinkListHeadInsert();

/* 链表尾插 */
int LinkListTailInsert();

/* 链表指定位置插入 */
int LinkListAppointPosInsert();

/* 链表头删 */
int LinkListHeadDel();

/* 链表尾删除 */
int LinkListTailDel();

/**/
int LinkListDelAppoinPos();

/*删除链表的*/
int LinkListDelAppointData();

/* 获取链表的长度 */
int LinkListGetLenegth();

int LinkListDestory();


#endif