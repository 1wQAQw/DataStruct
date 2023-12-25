#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#define ELEMENTTYPE int

typedef struct BSTreeNote
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
}BinarySearchTree;

/* 二叉搜索树的初始化 */
int bianrySearchTreeInit(BinarySearchTree **pBstree);

/* 二叉搜索树的插入 */
int bianrySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val, int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/*二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel();

/*二叉搜索树的前序遍历 */
int binarySearchTreeInOrderTravel();

/*二叉搜索树的前序遍历 */
int binarySearchTreePostOrderTravel();

/*二叉搜索树的前序遍历 */
int binarySearchTreeLevelOrderTravel();

/* 二叉搜索树是否包含指定的元素 */
int binarySearchTreeIsContainAppointval(BinarySearchTree *pBstree, ELEMENTTYPE val);

#endif
