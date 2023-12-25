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
/* 静态函数前置声明 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
#if 0
    if(val1 < val2)
    {
        return -1;
    }
    else if(val1 >val2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#else
    return val1 - val2;
#endif

}

/* 创建结点 */
static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parentNode)
{
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if(newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }   
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根节点 */
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }

    newBstNode->data = val;
    newBstNode->parent = parentNode;
    return newBstNode;
}

/* 根据指定的*/
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的初始化 */
int bianrySearchTreeInit(BinarySearchTree **pBstree,  int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
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
        /* 钩子函数在这边赋值 */
        bstree->compareFunc = compareFunc;
    }

    #if 0
        bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
        if(bstree->root == NULL)
        {
            return MALLOC_ERROR;
        }   
        /* 清除脏数据 */
        memset(bstree->root, 0, sizeof(BSTreeNode) * 1);
        /* 初始化根节点 */
        {
            bstree->root->data = 0;
            bstree->root->left = NULL;
            bstree->root->right = NULL;
            bstree->root->parent = NULL;
        }
    #else
        bstree->root = createBSTreeNewNode(0, NULL);
        if (bstree->root == NULL)
        {
            return MALLOC_ERROR;
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
        cmp = pBstree->compareFunc(val, traveNode->data);
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
    #if 0
    /* 分配新结点 */
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if(newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }   
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根节点 */
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    /* 新结点赋值 */
    newBstNode->data = val;
    #else
        BSTreeNode * newBstNode = createBSTreeNewNode(val, parentNode);
    #endif

    /* 挂在左子树 */
    if(cmp < 0)
    {
        parentNode->left =  newBstNode;
    }
    else
    {
        /* 挂在右子树 */
        parentNode->right = newBstNode;
    }
    #if 0
    /* 新结点的partent指针赋值 */
    newBstNode->parent = parentNode;
    #endif


    (pBstree->size)++;
    return ret;
}

/*二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    
    return ret;
}

/*二叉搜索树的前序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    
    return ret;
}

/*二叉搜索树的前序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    
    return ret;
}

/*二叉搜索树的前序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    
    return ret;
}

/* 根据指定*/
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    BSTreeNode * traveNode = pBstree->root;
    
    int cmp = 0;
    while(traveNode != NULL)
    {
        cmp = pBstree->compareFunc(val, traveNode->data);
        if(cmp < 0)
        {
            traveNode = traveNode->left;
        }
        else if(cmp > 0)
        {
            traveNode = traveNode->right;
        }
        else
        {
            return traveNode;
        }
    }
    return NULL;
}

/* 二叉搜索树是否包含指定的元素 */
int binarySearchTreeIsContainAppointval(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;

    return ret;
}