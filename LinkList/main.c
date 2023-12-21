#include <stdio.h>
#include <string.h>
#include "LinkList.h"

#define BUFFER_SIZE 10
typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;

/* 自定义打印 */
// int printStruct(void *arg)
// {
//     stuInfo *info = (stuInfo*)arg;

//     printf("age:%d\t, sex:%c\n", info->age, info->sex);
// }
int printBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\n", data);
}

int compareData(ELEMENTTYPE arg1, ELEMENTTYPE arg2)
{
    int num1 = *(int *)arg1;
    int num2 = *(int *)arg2;

    return num1 == num2 ? 1 : 0; 
}





int main()
{
 
    LinkList * list = NULL;
    /* 链表初始化 */
    LinkListInit(&list);

    /* 插入数据 */
#if 0
    //头插
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListHeadInsert(list, idx);
    }
#else
    //尾插
    int buffer[BUFFER_SIZE] = {1, 2, 3, 3, 4, 4, 5, 5, 6, 8};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListTailInsert(list, (void *)&buffer[idx]);
    }
#endif
    // stuInfo stu1, stu2, stu3;
    // memset(&stu1, 0, sizeof(stu1));
    // memset(&stu2, 0, sizeof(stu2));
    // memset(&stu3, 0, sizeof(stu3));

    // stu1.age = 10;
    // stu1.sex = 'm';

    // stu2.age = 20;
    // stu2.sex = 'f';

    // stu3.age = 30;
    // stu3.sex = 'm';

    // stuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};

    // for (int idx = 0; idx < BUFFER_SIZE; idx++)
    // {
    //     LinkListHeadInsert(list, (void *)&buffer[idx]);
    // }

    // int tmp = 21;
    // LinkListAppointPosInsert(list, 2, (void *)&tmp);

    int val = 5;
    LinkListDelAppointData(list, (void *)&val, compareData);
    /* 获取链表的长度 */
    int size = 0;
    LinkListGetLength(list, &size);
    printf("size:%d\n", size);

    // LinkListForeach(list, printStruct);
    LinkListForeach(list, printBasicData);




    return 0;
}