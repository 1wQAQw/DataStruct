#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_

typedef int ELEMENTTYPE;

/* 避免头文件重复定义 */
typedef struct dynamicArray
{
    ELEMENTTYPE *data;          /* s数组的空间 */
    int len;            /* 数组的大小 */
    int capactity;      /* 数组的容量 */
}dynamicArray;


/* API：appliction program interface */
/* 动态数组初始化 */
int dynamicArrayInit(dynamicArray *pArray);

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

/* 动态数组的销毁 */
int dynamicArrayDestory(dynamicArray *pArray);

/* 获取数组的大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

/* 获取数组的容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pSize);

#endif //__DYNAMIC_ARRAY_H_

