#include <stdio.h>
#include <stdlib.h>
typedef int Data;
typedef struct tree
{
    Data data;
    struct tree *root, *left, *right;
} Node, *pTree;
static Node *cur = NULL;
void initTree(pTree *root)
{
    *root = NULL;
}
//数据域比较函数,请根据具体问题修改
static bool isSame(const Data *A, const Data *B)
{
    if (*A == *B)
        return 1;
    return 0;
}
Node *findRoom(const Node *root)
{
    if (!root)
        return NULL;
    else
    {
        const Node *tmp = root;
        findRoom(root->left);
    }
}
void insert(const Data *pData, pTree root)
{
    if (!pData)
        exit(EXIT_FAILURE);
    Node *tmp = NULL;
    if (tmp = (Node *)malloc(sizeof(Node)))
    {
        tmp->data = *pData;
    }
}
