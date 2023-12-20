#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 16
#define DEFAULT_SIZE 2
    /* 结构体 */
    /* 什么叫结构体 将不同类型的属性封装成一个类型 */
    /* 2. 怎样定义结构体 */
    typedef struct stuInfo
    {
        int age;
        int height;
        int weight;
        char sex;
        char name[BUFFER_SIZE];
        char *address;
    }stuInfo;
    /* 结构体会默认进行字节对齐：读取速度块（但是浪费空间）*/
    /* 结构体的【位域】到网络编程的时候再研究 */
    /* 什么叫变长结构体 */

    /* 函数：结构体函数 */

    /* 传入参数：不改变变量 */
int printStruct(const stuInfo *stu)
    {
        /* 结构体必须用指针 节省空间 */
        int ret = 0;
        int len = sizeof(stu);
        printf("len:%d\n", len);

        return 0;
    }

int printStructBuffer(const stuInfo *stu, int stuSize)
{
    for(int idx = 0; idx = stuSize; idx++)
    {
       printf("stu.age:%d\t, stu.height: %d\t, stu.sex:%d\t stu.name:%d\n",
                stu[idx].age, stu[idx].height, stu[idx].sex,stu[idx].name);
    }

}


int main()
{

#if 1
    /* 3.怎样使用结构体 */   
    stuInfo stu;
    stu.age = 10;
    stu.height = 50;
    stu.sex = 'm';
    stu.height = 100;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);
    //printf("stu.age:%d\t, stu.height: %d\t, stu.sex:%d\t stu.name:%d\n, ");
#endif

#if 0
    /* 怎样使用结构体 */
    int desk;
    int blackboard;
    int light;
#endif

#if 0
    /* 4.结构体大小 */
    // int len = sizeof(stu);
    // printf("len:%d\n",len);

    /* 5.结构体数组*/
    /* 数组：
        1.一块连续的地址
        2.存放的是同一种数据类型
    */
    stuInfo buffer[BUFFER_SIZE];
    buffer[0].age = 10;
    buffer[0].height = 30;
    buffer[0].sex = 'm';
    buffer[0].height = 130;
    strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name) - 1);
    printf("stu.age:%d\t, stu.height: %d\t, stu.sex:%d\t stu.name:%d\n",
                buffer[0].age, buffer[0].height = 10, buffer[0].sex = 10, buffer[0].height = 10, buffer[0].name);

    buffer[1].age = 20;
    buffer[1].height = 50;
    buffer[1].sex = 'f';
    buffer[1].height = 160;
    strncpy(buffer[1].name, "zhangsan", sizeof(buffer[1].name) - 1);
    printf("stu.age:%d\t, stu.height: %d\t, stu.sex:%d\t stu.name:%d\n",
                buffer[0].age, buffer[0].height = 10, buffer[0].sex = 10, buffer[0].height = 10, buffer[0].name);
#endif
    /* 结构体指针 */
    stu.age = 10;
    stu.height = 30;
    stu.sex = 'm';
    stu.height = 130;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);

    /* 回顾指针 */
    int a = 5;
    int *p = &a;



    /* 结构体指针 */
    stuInfo * info = &stu;
    /* 结构体指针 读数据 或者写数据. 都是用->*/
    info->age = 30;
    printf("info->:%d\n", info->age);
    printf("stu.age:%d\n", stu.age);

#if 1

    stuInfo buffer[BUFFER_SIZE];
    buffer[0].age = 10;
    buffer[0].height = 30;
    buffer[0].sex = 'm';
    buffer[0].height = 130;
    strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name) - 1);

    buffer[1].age = 20;
    buffer[1].height = 50;
    buffer[1].sex = 'f';
    buffer[1].height = 160;
    strncpy(buffer[1].name, "zhangsan", sizeof(buffer[1].name) - 1);
#endif







 return 0;
}