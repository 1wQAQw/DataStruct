#include "binarySearchTree.h"
#include <stdio.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 二叉搜索树的初始化 */
int bianrySearchTreeInit(BinarySearchTree **pBstree)
{
    int ret = 0;
    BinarySearchTree * bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    if(bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(bstree, 0, sizeof(BinarySearchTree));
    /* 初始化树 */
    {
        bstree->root = NULL;
        bstree->size = 0;

    }

    #if 1
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    /* 清除脏数据 */
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根节点 */
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;
    }
    #endif

    *pBstree = bstree;
    return ret;
}

/* 二叉搜索树的插入 */
int bianrySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;

    /* 空树 */
    if(pBstree->size== 0)
    {
        /* 更新树的结点 */
        (pBstree->size)++;

        pBstree->root->data = val;
    }

    /* traveNode 指向跟结点 */
    BSTreeNode * traveNode = pBstree->root;
    BSTreeNode * parentNode = pBstree->root;

    /* 确定符号：到底放在左边还是右边 */
    int cmp = 0;
    while(traveNode != NULL)
    {
        parentNode = traveNode;
        cmp = val - traveNode->data;
        /* 插入元素 < 遍历到的结点 */
        if(cmp < 0)
        {
            traveNode = traveNode->left;
        }
        else if(cmp > 0)
        {
            traveNode = traveNode->right;   /* 插入元素 > 遍历到的结点 */
        }
        else
        {
            /* 插入元素 = 遍历到的结点 */
            return ret;
        }

    }
    
    if(cmp < 0)
    {
        parentNode->left =  (val的结点)
    }
    else
    {
        parentNode->right = (val的结点)
    }





    return ret;
}

