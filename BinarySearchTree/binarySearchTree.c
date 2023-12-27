#include "binarySearchTree.h"
#include "doubleLinkListQueue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 状态码 */
enum STATUS_CODE
{
    NOT_FIND = -1, 
    NULL_PTR,
    ON_SUCCESS,
    MALLOC_ERROR,
    INVALID_ACCESS,
};
#if 0
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
#endif
/* 创建结点 */
static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parent);

/* 根据指定的值获取元素*/
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val);
/* 判断二叉搜索树度为2 */
static int binarySearchTreeHasTwochildeens(BSTreeNode *node);
/* 判断二叉搜索树度为1 */
static int binarySearchTreeHasOnechildeens(BSTreeNode *node);
/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodechildeens(BSTreeNode *node);
/* 前序遍历 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 中序遍历 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 后续遍历 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 获取当前结点的前驱结点 */
static BSTreeNode * bstreeNodepreDecessor(BSTreeNode *node);
/* 获取当前结点的后继结点 */
static BSTreeNode * bstreeNodepreSuccessor(BSTreeNode *node);
/* 层序获取树的深度 */
static int sequenceObtainHeight(BinarySearchTree *pBstree, int *pHight);
/* 获取高度递归 */
static int obtainHeight(BinarySearchTree *pBstree, BSTreeNode *node);

/* 二叉搜索树的初始化 */
int bianrySearchTreeInit(BinarySearchTree **pBstree,  int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE *val))
{
    int ret = 0;
    BinarySearchTree * bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    if(bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);
    /* 初始化树 */
    {
        bstree->root = NULL;
        bstree->size = 0;
        /* 钩子函数在这边赋值 */
        bstree->compareFunc = compareFunc;
        /* 钩子函数包装器 自定义打印 */
        bstree->printFunc = printFunc;
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
/* 判断二叉搜索树度为2 */
static int binarySearchTreeHasTwochildeens(BSTreeNode *node)
{
    return (node->left != NULL) && (node->right != NULL);
}

/* 判断二叉搜索树度为1 */
static int binarySearchTreeHasOnechildeens(BSTreeNode *node)
{
    return ((node->left == NULL) && (node->right != NULL)) || ((node->left != NULL) && (node->right == NULL));
}

/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodechildeens(BSTreeNode *node)
{
    return (node->left == NULL) && (node->right == NULL);
}

/* 获取当前结点的前驱结点 */
static BSTreeNode * bstreeNodepreDecessor(BSTreeNode *node)
{
    /* 度为2 */
    if(node->left != NULL)
    {
        BSTreeNode *travelNode = node->left;
        while(travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;
    }
    /* 程序到这个地方 说明一定没有左子树 那就需要父结点找 */
    while(node->parent != NULL && node == node->parent->left)
    {
        node = node->parent;
    }
    /* node->parent == NULL */
    /* node = node->parent->right */
    return node->parent;
}
/* 获取当前结点的后继结点 */
static BSTreeNode * bstreeNodepreSuccessor(BSTreeNode *node)
{
    if(node->right != NULL)
    {
        BSTreeNode *travelNode = node->right;
        while(travelNode->left != NULL)
        {
            travelNode = travelNode->left;
        }
        return travelNode;
    }
    /* 程序到这个地方 说明一定没有左子树 那就需要父结点找 */
    while(node->parent != NULL && node == node->parent->right)
    {
        node = node->parent;
    }
    /* node->parent == NULL */
    /* node = node->parent->right */
    return node->parent;
}

static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parent)
{
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if(newBstNode == NULL)
    {
        return NULL;
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
    newBstNode->parent = parent;
    return newBstNode;
}

/* 二叉搜索树的插入 */
int bianrySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;

    /* 空树 */
    if(pBstree->size == 0)
    {
        /* 更新树的结点 */
        (pBstree->size)++;

        pBstree->root->data = val;
        return ret;
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
        // printf("%d\n",cmp);
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
    else if(cmp > 0)
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

static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
        int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    /* 根左右 */   
    pBstree->printFunc(node->data);
    /* 左子树 */
    preOrderTravel(pBstree, node->left);
    /* 右子树 */
    preOrderTravel(pBstree, node->right);
}

/*二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    preOrderTravel(pBstree, pBstree->root);
    return ret;
}

static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    /* 左子树 */
    inOrderTravel(pBstree, node->left);
    /* 根结点 */
    pBstree->printFunc(node->data);
    /* 右子树 */
    inOrderTravel(pBstree, node->right);
}

/*二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
        inOrderTravel(pBstree, pBstree->root);
    return ret;
}

/* 后续遍历 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    /* 左子树 */
    postOrderTravel(pBstree, node->left);
    /* 右子树 */
    postOrderTravel(pBstree, node->right);
    /* 根结点 */
    pBstree->printFunc(node->data);
}

/*二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    postOrderTravel(pBstree,pBstree->root);
    return ret;
}

/*二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    DoubleLinkList * Queue = NULL;
    doubleLinkListQueueInit(&Queue);

    /* 根节点入队 */
    doubleLinkListQueuePush(Queue, pBstree->root);
    
    BSTreeNode *nodeval = NULL;
    while(!doubleLinkListQueueIsEmpty(Queue))
    {
        doubleLinkListQueueTop(Queue, (void **)&nodeval);
        #if 0
        printf("data:%d\n", nodeval->data);
        #else
        pBstree->printFunc(nodeval->data);
        #endif
        doubleLinkListQueuePop(Queue);
        /* 将左子树入队 */
        if(nodeval->left != NULL)
        {
            doubleLinkListQueuePush(Queue, nodeval->left);
        }
        /* 将右子树入队 */
        if(nodeval->right != NULL)
        {
            doubleLinkListQueuePush(Queue, nodeval->right);
        }
    }

    doubleLinkListQueueDestroy(Queue);
    return ret;
}

/* 根据指定的值获取二叉搜素树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    BSTreeNode * traveNode = pBstree->root;
    
    int cmp = 0;
    while(traveNode != NULL)
    {
        /* 比较大小 */
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
            /* 找到了 */
            return traveNode;
        }
    }
    return NULL;
}

/* 二叉搜索树是否包含指定的元素 */
int binarySearchTreeIsContainAppointval(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTreeNode(pBstree, val) == NULL ? 0 : 1;
}
/* 获取高度递归 */
static int obtainHeight(BinarySearchTree *pBstree, BSTreeNode *node)
{
    int left,right,MaxH;
	if(node)
    {
		left = obtainHeight(pBstree, node->left);
		right = obtainHeight(pBstree, node->right);
		MaxH=left > right ? left : right;
		return (MaxH+1);
	}
    else
    {
		return 0;
    }
}

static int sequenceObtainHeight(BinarySearchTree *pBstree, int *pHight)
{
    int ret = 0;
    if(pBstree==NULL)
    {
        return NULL_PTR;
    }
    if(pBstree->size == 0)
    {
        return ret;
    }
    DoubleLinkList * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);

    /* 树的高度（根节点入队高度为1） */
    doubleLinkListQueuePush(pQueue, pBstree->root);
    int height = 0;
    /* 树每一层的结点数量 */
    int leveSize = 1;
    BSTreeNode *nodeval = NULL;
    while(!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&nodeval);
        doubleLinkListQueuePop(pQueue);
        leveSize--;

        /* 将左子树入队 */
        if(nodeval->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, nodeval->left);
        }
        /* 将右子树入队 */
        if(nodeval->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, nodeval->right);
        }
        /* 树的当前层结束 */
        if(leveSize == 0)
        {
            height++;
            doubleLinkListQueueGetSize(pBstree, &leveSize);
        }
    }

    *pHight = height;

    doubleLinkListQueueDestroy(pQueue);
    return ret;
}
/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *Phight)
{   
    #if 1
    *Phight = obtainHeight(pBstree, pBstree->root);
    #else
    *Phight =sequenceObtainHeight(pBstree, pHight)
    #endif
    return 0;
}

/* 二叉搜索树的销毁 */
int binarySearchTreeDestroy(BinarySearchTree *pBstree)
{
    int ret = 0;
    if(pBstree == NULL)
    {
        return NULL_PTR;
    }

    DoubleLinkList * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);
    doubleLinkListQueuePush(pQueue, pBstree->root);
    BSTreeNode * travelNode = NULL;
    while(!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&travelNode);
        doubleLinkListQueuePop(pQueue);


        /* 将左子树入队 */
        if(travelNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->left);
        }
        /* 将右子树入队 */
        if(travelNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->right);
        }

        if(travelNode)
        {
            free(travelNode);
            travelNode = NULL;
        }
    }
    
    /* 释放队列 */
    doubleLinkListQueueDestroy(pQueue);
    
    /*释放树*/
    if(pBstree)
    {
        free(pBstree);
        pBstree = NULL;
    }
        
    return ret;
}
