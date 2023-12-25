#ifndef __DYNAMIC_ARRAY_STACK_H_
#define __DYNAMIC_ARRAY_STACK_H_

#include "common.h"

/* 取别名 */
typedef dynamicArray dynamicArrayStack;

/* 栈的初始化 */
int dynamicArrayStackInit(dynamicArrayStack *pList);


/* 压栈 */
int dynamicArrayStackPush(dynamicArrayStack *pList, ELEMENTTYPE val);

/* 产看栈底元素 */
int dynamicArrayStackTop(dynamicArrayStack *pList, ELEMENTTYPE val);

/* 出栈 */
int dynamicArrayStackPop(dynamicArrayStack *pList);

/* 栈是否为空 */
int dynamicArrayStackEmpty(dynamicArrayStack *pList);

/* 获取栈的大小 */
int dynamicArrayStackGetSize(dynamicArrayStack *pList, int *pSize);

/* 栈的销毁 */
int dynamicArrayStackDestroy(dynamicArrayStack *pList);








#endif


