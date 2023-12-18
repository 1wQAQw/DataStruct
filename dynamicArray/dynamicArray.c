#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
};

#define DEFAULT_SIZE 10

/* 动态数组初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }
    
    if(capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }

    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);

    pArray->len = 0;
    pArray->capactity = capacity;

    return ON_SUCCESS;
}

/* 动态数组插入数据(默认插入到数组末尾) */
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val);
/* 动态数组插入数据在指定位置插入 */
int dynamicArrayAppoitPosInserData(dynamicArray *pArry, int pos, ELEMENTTYPE val);

/* 动态数组修改指定位置的数据 */
int dynamicArrayModifAppointPosData(dynamicArray *pArry, int pos, ELEMENTTYPE val);

/* 动态数组的删除数据(默认下删除末尾的数据) */
int dynamicArrayDeleteData(dynamicArray *pArray);

/* 动态数组的指定位置删除 */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArry, int pos);

/* 动态数组删除指定的元素 */
int dynamicArrayDeleteAppointData(dynamicArray *pArry, int pos, ELEMENTTYPE val);

/* 动态数组的销毁 */
int dynamicArrayDestory(dynamicArray *pArray);

/* 获取数组的大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

/* 获取数组的容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pSize);
