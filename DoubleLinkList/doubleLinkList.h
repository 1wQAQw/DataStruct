#ifndef __DOUBLELINKLIST__
#define __DOUBLELINKLIST__

#define ELEMENTTYPE void*

/* 链表结点取别名 */
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;

    struct DoubleLinkNode * prev;
    
    /* 指向下一个结点的指针 */
    struct DoubleLinkNode *next;  /* 指针的类型为什么是结点 */
    /* data */
}DoubleLinkNode;

typedef struct  DoubleLinNode
{
    DoubleLinkNode node;

}DoubleLinNode;



/* 链表 */
typedef struct LinKList
{
    /* 链表的虚拟头节点 */
    DoubleLinkNode *head;
    DoubleLinkNode *tail;         /* 为什么尾指针不需要分配空间 */
    /* 链表长度 */
    int len;
}LinkList;

/* 链表初始化 */
int LinkListInit(LinkList **pList);

/* 链表头插 */
int LinkListHeadInsert(LinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int LinkListTailInsert(LinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int LinkListHeadDel(LinkList * pList);

/* 链表尾删除 */
int LinkListTailDel(LinkList * pList);

/* 链表指定位置删 */
int LinkListDelAppointPos(LinkList * pList, int pos);

/* 删除链表的指定数据 */
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize);

/* 链表的销毁 */
int LinkListDestory(LinkList * pList);

/* 链表遍历接口 */
int LinkListForeach(LinkList * pList, int (*printFunc)(ELEMENTTYPE));

#endif