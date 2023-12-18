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
int dynamicArrayInit();

/* 动态数组插入数据(默认插入到数组末尾) */
int dynamicArrayInsertData();

/* 动态数组插入数据在指定位置插入 */
int dynamicArrayAppoitPosInserData();

/* 动态数组修改指定位置的数据 */
int dynamicArrayModifAppointPosData();

/* 动态数组的删除数据(默认下删除末尾的数据) */
int dynamicArrayDeleteData();

/* 动态数组的指定位置删除 */
int dynamicArrayDeleteAppointPosData();

/* 动态数组的销毁 */
int dynamicArrayDestory();

/* 获取数组的大小 */
int dynamicArrayGetSize();

/* 获取数组的容量 */
int dynamicArrayGetCapacity();

#endif //__DYNAMIC_ARRAY_H_

