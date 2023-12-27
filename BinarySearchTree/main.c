#include "binarySearchTree.h"
#include <stdio.h>

#define BUFFER_SIZE 10

int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    int num1 = *(int *)val1;
    int num2 = *(int *)val2;
    return num1 - num2;
}
int printFunc(ELEMENTTYPE *val)
{
    printf("val:%d\t", *(int *)val);
}


int main()
{
    BinarySearchTree *testTree = NULL;
    bianrySearchTreeInit(&testTree, compareFunc, printFunc);

    int buffer[BUFFER_SIZE] = {7, 6, 25, 46, 12, 34, 45, 13, 11, 20};
    int idx = 0;
    for(idx = 0; idx < BUFFER_SIZE; idx++)
    {
        bianrySearchTreeInsert(testTree, (void *)&buffer[idx]);
    }
    printf("size:%d\n", testTree->size);

    /* 前序遍历 */
    binarySearchTreePreOrderTravel(testTree);
    printf("\n");
    /* 中序遍历 */
    binarySearchTreeInOrderTravel(testTree);
    printf("\n");
    /* 层序遍历 */
    binarySearchTreeLevelOrderTravel(testTree);
    printf("\n");
    /* 后续遍历 */
    binarySearchTreePostOrderTravel(testTree);
    printf("\n");

    int hight = 0;
    binarySearchTreeGetHeight(testTree, &hight);
    printf("hight:%d\n", hight);

    return 0;
}