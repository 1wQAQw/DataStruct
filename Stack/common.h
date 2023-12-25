#ifndef __COMMON_H_
#define __COMMON_H_

typedef int ELEMENTTYPE;

/* 避免头文件重复定义 */
typedef struct dynamicArray
{
    ELEMENTTYPE *data;          /* s数组的空间 */
    int len;            /* 数组的大小 */
    int capactity;      /* 数组的容量 */
}dynamicArray;

#endif
