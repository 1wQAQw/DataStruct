#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#define ELEMENTTYPE void*

typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode *left;    /* 左子树 */
    struct BSTreeNode *right;   /* 右子树 */

    #if 1
    struct BSTreeNode *parent;  /* 父结点 */
    #endif
}BSTreeNode;

typedef struct BinarySearchTree
{
    /* 根结点 */
    BSTreeNode * root;

    /* 数的结点 */
    int size;

    /* 钩子函数比较器 放到这个 */
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);

    /* 钩子函数 包装器实现自定义打印函数接口 */
    int (*printFunc)(ELEMENTTYPE *val);
}BinarySearchTree;

/* 二叉搜索树的初始化 */
int bianrySearchTreeInit(BinarySearchTree **pBstree,  int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE *val));

/* 二叉搜索树的插入 */
int bianrySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val);

/*二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree);

/*二叉搜索树的前序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree);

/*二叉搜索树的前序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree);

/*二叉搜索树的前序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树是否包含指定的元素 */
int binarySearchTreeIsContainAppointval(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *pHight);

/* 二叉搜索树的删除 */
int binarySearchTreeDelete(BinarySearchTree *pBstree);

/* 二叉搜索树的销毁 */
int binarySearchTreeDestroy(BinarySearchTree *pBstree);
#endif
