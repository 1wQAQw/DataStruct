#ifndef __DOUBLEDoubleLinkList__
#define __DOUBLEDoubleLinkList__

// #define ELEMENTTYPE void*

#include "common.h"
// /* 链表结点取别名 */
// typedef struct DoubleLinkNode
// {
//     ELEMENTTYPE data;

//     struct DoubleLinkNode * prev;
    
//     /* 指向下一个结点的指针 */
//     struct DoubleLinkNode *next;  /* 指针的类型为什么是结点 */
//     /* data */
// }DoubleLinkNode;



// /* 链表 */
// typedef struct DoubleLinkList
// {
//     /* 链表的虚拟头节点 */
//     DoubleLinkNode *head;
//     DoubleLinkNode *tail;         /* 为什么尾指针不需要分配空间 */
//     /* 链表长度 */
//     int len;
// }DoubleLinkList;

/* 链表初始化 */
int DoubleLinkListInit(DoubleLinkList **pList);

/* 链表头插 */
int DoubleLinkListHeadInsert(DoubleLinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int DoubleLinkListTailInsert(DoubleLinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int DoubleLinkListAppointPosInsert(DoubleLinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int DoubleLinkListHeadDel(DoubleLinkList * pList);

/* 链表尾删除 */
int DoubleLinkListTailDel(DoubleLinkList * pList);

/* 链表指定位置删 */
int DoubleLinkListDelAppointPos(DoubleLinkList * pList, int pos);

/* 删除链表的指定数据 */
int DoubleLinkListDelAppointData(DoubleLinkList * pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 获取链表的长度 */
int DoubleLinkListGetLength(DoubleLinkList * pList, int *pSize);

/* 链表的销毁 */
int DoubleLinkListDestory(DoubleLinkList * pList);

/* 链表遍历接口 */
int DoubleLinkListForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));

/* 链表从后往前遍历 */
int DoubleLinkListReverserForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));

/* 获取链表 头位置值 s*/
int DoubleLinkListGetHeadVal(DoubleLinkList *pList, ELEMENTTYPE *pVal);

/* 获取链表 尾位置值 */
int DoubleLinkListGetTailVal(DoubleLinkList *pList, ELEMENTTYPE *pVal);

/* 获取链表 指定位置的值 */
int DoubleLinkListGetAppointPosVal(DoubleLinkList *pList, int pos, ELEMENTTYPE *pVal);


#endif