#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

#define DEFAULT_SIZE 10


static int expandDynamicCapacity(dynamicArray *pArray);
static int shrinkDynamicCapacity(dynamicArray *pArray);


/* 动态数组初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }
    
    /* 避免传入非法值 */
    if(capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }

    /* 分配空间 */
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);
    /* 初始化动态数组的参数属性 */
    pArray->len = 0;
    pArray->capacity = capacity;

    return ON_SUCCESS;
}



/* 动态数组插入数据(默认插入到数组末尾) */
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val)
{
    return dynamicArrayAppoitPosInserData(pArray, pArray->len, val);

}

/* 动态数组扩容*/
static int expandDynamicCapacity(dynamicArray *pArray)
{
    int ret = 0;

    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);
    
    /* 备份指针 */
    ELEMENTTYPE * tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 把以前的数据全部拷贝过来 */
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    /* 释放以前的内存 避免内存泄漏 */
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }
    
    /* 更新长度 */
    pArray->capacity = needExpandCapacity; 
    return ret;
}


/* 动态数组插入数据在指定位置插入 */
int dynamicArrayAppoitPosInserData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 判断位置的合法性 */
    if(pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }
    #if 1
    if((pArray->len + (pArray->len >> 1)) >= pArray->capacity)
    {
        /* 开始扩容 */
        expandDynamicCapacity(pArray);
    }
    #else
    /* */
    if(pArray->len == pArray->capacity)

    #endif

    for(int idx =pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }

    /* 找到对应的值 写入到数组中 */
    pArray->data[pos] = val;

    /* 数组的大小加一 */
    (pArray->len)++;


}
/* 动态数组修改指定位置的数据 */
int dynamicArrayModifAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 判断位置的合法性 */
    if(pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 更新位置的数据*/
    pArray->data[pos] = val;

    return ON_SUCCESS;
}

/* 动态数组的删除数据(默认下删除末尾的数据) */
int dynamicArrayDeleteData(dynamicArray *pArray)
{
    dynamicArrayDeleteAppointPosData(pArray, pArray->len - 1);
    return ON_SUCCESS;
}



int shrinkDynamicCapacity(dynamicArray *pArray)
{
    int needExpandCapacity = pArray->capacity - (pArray->capacity >> 1);
    
    /* 备份指针 */
    ELEMENTTYPE * tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 把以前的数据全部拷贝过来 */
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    /* 释放以前的内存 避免内存泄漏 */
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }
    
    /* 更新长度 */
    pArray->capacity = needExpandCapacity;
    return ON_SUCCESS;
}
/* 动态数组的指定位置删除 */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    if(pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 缩容*/
    if(pArray->len > pArray->capacity >> 1)
    {
        shrinkDynamicCapacity(pArray);
    }

    /* 数据前移 */
    for(int idx =pos; idx < pArray->len; idx++)
    {
        pArray->data[idx] == pArray->data[idx + 1];
    }
    /* 更新数组的大小 */
    (pArray->len)--;
    return ON_SUCCESS;

}

/* 动态数组删除指定的元素 */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
#if 0
        for(int idx = 0; idx < pArray->len; idx++)
        {
            if(val ==pArray->data[idx)
            {
                ynamicArrayDeleteAppointPosData(pArray, idx); 
            }
        }
#else
    for(int idx = pArray->len - 1; idx >= 0; idx--)
    {
        if(val == pArray->data[idx])
        {
            ynamicArrayDeleteAppointPosData(pArray, idx); 
        }
    }
#endif
    return ON_SUCCESS;
}



/* 动态数组的销毁 */
int dynamicArrayDestory(dynamicArray *pArray)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }
    if(pArray->data != NULL)
    {
        free(pArray->data);
        pArray->data =NULL;
    }
    return ON_SUCCESS;
}

/* 获取数组的大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize)
{
    if(pArray == NULL || pSize == NULL)
    {
        return NULL_PTR;
    }

    /* 解引用 */
    if(pSize == NULL)
    {
        *pSize = pArray->len;

    }

    return ON_SUCCESS;

}

/* 获取数组的容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity)
{
    if(pArray == NULL )
    {
        return NULL_PTR;
    }

    /* 解引用 */
    if(pCapacity == NULL)
    {
        *pCapacity = pArray->len;

    }
    
    return ON_SUCCESS;

}