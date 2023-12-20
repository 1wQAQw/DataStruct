#include "LinkList.h"
#include <stdlib.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 静态函数只在源文件（.c）中使用 */
/* 静态函数前置声明 */
static int LinkListAccordAppointValGetpos(LinkList * pList, ELEMENTTYPE val, int *pPos);

/* 链表初始化 */
int LinkListInit(LinkList **pList)
{
    int ret = 0;
    LinkList *list = (LinkList *)malloc(sizeof(LinkList) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list, 0, sizeof(LinkList) * 1);

    list->head = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list->head, 0, sizeof(LinkNode) * 1);
    list->head->data = 0;
    list->head->next = NULL;

    /* 初始化的时候，尾指针 = 头指针 */
    list->tail = list->head;

    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针 */
    *pList = list;
    return ret;
}

/* 链表头插 */
int LinkListHeadInsert(LinkList * pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int LinkListTailInsert(LinkList * pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, pList->len, val);
}

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTYPE val)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    if(pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(LinkNode) * 1);

    newNode ->data = val;

#if 1
    LinkNode * traveNode = pList->head;
#else
    LinkNode * traveNode = pList->head->next;
#endif
    int flag = 0;
    /* 这种情况下需要更改尾指针 */
    if(pos == pList->len)
    {
        traveNode = pList->tail;
        flag = 1;
    }
    else
    {
        while(pos)
        {
            traveNode = traveNode->next;
            pos--;
        }
    }
    newNode->next = traveNode->next;
    traveNode->next = newNode;
    if(flag == 1)
    {
        /* 尾指针更新 */
        pList->tail = newNode;
    }
    pList->len++;

    return ret;
}

/* 链表头删 */
int LinkListHeadDel(LinkList * pList)
{
    /* todo... */
    LinkListDelAppointData(pList, 1);
}

/* 链表尾删 */
int LinkListTailDel(LinkList * pList)
{
    LinkListDelAppointData(pList, pList->len);
}

/* 链表指定位置删 */
int LinkListDelAppointPos(LinkList * pList, int pos)
{
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    if(pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

#if 1
    LinkNode * travelNode = pList->head;
#else
    LinkNode * travelNode = pList->head->next;
#endif
    int flag = 0;
    /* 需要修改尾指针 */
    if (pos == pList->len)
    {
        flag = 1;
    }
    while (--pos)
    {
        /* 向后移动位置 */
        travelNode = travelNode->next;
        // pos--;
    }
    // 跳出循环找到的是那个节点
    LinkNode * needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;
    
    if(flag = 1)
    {
        /* 调整尾指针 */
        pList->tail = travelNode;
    }

    if(needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }
 

    /* 链表长度减减 */
    pList->len--;
}

static int LinkListAccordAppointValGetpos(LinkList * pList, ELEMENTTYPE val, int *pPos)
{
     /* 静态函数只给源文件的函数使用， 不需要判断合法性 */
#if 0
    LinkNode * travelNode = pList->head;
#else
    LinkNode * travelNode = pList->head->next;
#endif
    int pos = 1;
    while (travelNode != NULL)
    {
        if(travelNode->data == val)
        {
            *pPos = pos;
            return pos;
        }
        travelNode = travelNode->next;
        pos++;
    }

    *pPos = NOT_FIND;
    return NOT_FIND;
}
/* 链表删除指定的数据 */
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE val)
{
    int ret = 0;

    /* 元素在链表中的位置 */
    int pos = 0;
    /* 链表的长度 */
    int size = 0;
    while(LinkListGetLength(pList, &size) && pos != NOT_FIND)
    {
        /* 根据指定的元素得到在链表中所在的位置 */
        LinkListAccordAppointValGetpos(pList, val, &pos);
        LinkListDelAppointData(pList, pos);
    }


    return ret;
}

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    if(pSize)
    {
        *pSize = pList->len;
    }
    /* 返回链表长度 */
    return NOT_FIND;
}

/* 链表的销毁 */
int LinkListDestroy(LinkList * pList)
{
    /* 我们使用头删释放链表 */
    int size = 0;
    while(LinkListGetLenegth(pList, &size))
    {
        inkListHeadDel(pList);
    }

    if(pList->head != NULL)
    {
        free(pList->head);
        /* 指针设置为NULL */
        pList->head = NULL;
        pList->tail = NULL;
    }
}

/* 链表遍历接口 */
int LinkListForeach(LinkList * pList)
{
    if(pList == NULL)
    {
        return NULL_PTR;
    }

#if 0
    LinkNode * traveNode = pList->head; 
    while (traveNode->next != NULL)
    {
        traveNode = traveNode->next;
        printf("traveNode->data:%d\n", traveNode->data);
    }
#else
    LinkNode * traveNode = pList->head->next;
    while (traveNode != NULL)
    {
        printf("traveNode->data:%d\n", traveNode->data);
        traveNode = traveNode->next;
    }
#endif

   
}
