#include "DoubleLinkListQueue.h"



/* 队列初始化*/
int doubleLinkListQueueInit(DoubleLinkListQueue *pQueue)
{
    return DoubleLinkListInit(pQueue);
}

/* 队列入队 */
int doubleLinkListQueuePush(DoubleLinkListQueue *pQueue, ELEMENTTYPE val)
{
    return DoubleLinkListTailInsert(pQueue, val);
}

int doubleLinkListQueueTop(DoubleLinkListQueue *pQueue, ELEMENTTYPE val)
{
    return doubleLinkListGetHeadVal(pQueue, val);
}

int doubleLinkListQueueRear(DoubleLinkListQueue *pQueue, ELEMENTTYPE val)
{
    return 0;
}

int doubleLinkListQueuePop(DoubleLinkListQueue *pQueue)
{
    return 0;
}

int doubleLinkListQueueGetSize(DoubleLinkListQueue *pQueue, int *pSize)
{
    return DoubleLinkListGetLength(pQueue, pSize);
}

int doubleLinkListQueueIsEmpty(DoubleLinkListQueue *pQueue)
{
    int size = 0;
    DoubleLinkListGetLength(pQueue, &size);
    return size == 0 ? 1 : 0;
}

int doubleLinkListQueueDestroy(DoubleLinkListQueue *pQueue)
{
    return doubleLinkListDestory(pQueue);
}
