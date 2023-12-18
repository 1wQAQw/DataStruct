#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_

typedef int ELEMENTTYPE;

/* 避免头文件重复定义 */
typedef struct dynamicArray
{
    int *data;          /* s数组的空间 */
    int len;            /* 数组的大小 */
    int capactity;      /* 数组的容量 */
}dynamicArray;



#endif //__DYNAMIC_ARRAY_H_

