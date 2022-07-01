#include "tree.h"
bool initTree(Tree *const pTree)
{
    if (pTree == NULL)
        return false;
    pTree->root = NULL;
    pTree->size = 0;
    return true;
}
bool isTreeEmpty(const Tree *const pTree)
{
    if (pTree == NULL || pTree->size == 0)
        return true;
    return false;
}
/**
 * \brief 由clearTree调用,以后序遍历的方式销毁某个子树
 * \param pChildTree 指向可以代表某个子树的节点
 * \createdtime by yingquelou at 2022-06-28 11:54:04
 */
static void destroyChildTree(Trnode *const pChildTree)
{
    if (pChildTree == NULL)
        return;
    destroyChildTree(pChildTree->left);
    destroyChildTree(pChildTree->right);
    free(pChildTree->pItem);
    free(pChildTree);
}
bool clearTree(Tree *const pTree)
{
    if (pTree == NULL)
        return false;
    if (pTree->size == 0)
        return true;
    destroyChildTree(pTree->root);
    pTree->root = NULL;
    pTree->size = 0;
    return true;
}
/**
 * \brief 由addItem调用,动态分配存放元素的节点
 * \retval 返回分配好的节点的指针
 * \createdtime by yingquelou at 2022-07-01 23:10:58
 */
static inline Trnode *makeNode(void)
{
    return calloc(1, sizeof(Trnode));
}
/**
 * \brief 由addItem调用,用以确定某个元素的插入位置
 * \param pTree 指向树
 * \param pItem 指向待插入元素(应是动态分配的)
 * \param cmp 用于比较元素的函数的指针
 * \retval 返回插入位置——待插入元素的父节点;
 * \retval NULL 当pTree为空指针是返回NULL;当树是空树时亦返回NULL。
 * \createdtime by yingquelou at 2022-07-01 20:56:14
 */
static Trnode *seekAddPosition(const Tree *const pTree, const void *const pItem, const CompareFunction cmp)
{
    if (pTree == NULL || pTree->size < 1)
        return NULL;
    Trnode *cur = pTree->root, *keep;
    while (cur)
    {
        keep = cur;
        int flog = cmp(pItem, cur->pItem);
        if (flog > 0)
        {
            cur = cur->right;
        }
        else if (flog == 0)
            return NULL;
        else
        {
            cur = cur->left;
        }
    }
    return keep;
}
bool addItem(Tree *const pTree, void *const pItem, const CompareFunction cmp)
{
    if (pTree == NULL || pItem == NULL || cmp == NULL)
        return false;
    Trnode *pos = seekAddPosition(pTree, pItem, cmp);
    Trnode *node = makeNode();
    if (node == NULL)
        return false;
    node->pItem = pItem;
    if (pTree->size == 0)
    {
        pTree->root = node;
    }
    else if (pos)
    {
        if (cmp(pItem, pos->pItem) > 0)
            pos->right = node;
        else
            pos->left = node;
    }
    ++pTree->size;
    return true;
}
void preorderTraversal(const Trnode *const pRoot, void (*func)(void *))
{
    if (!pRoot)
        return;
    func(pRoot->pItem);
    preorderTraversal(pRoot->left, func);
    preorderTraversal(pRoot->right, func);
}
void inorderTraversal(const Trnode *const pRoot, void (*func)(void *))
{
    if (!pRoot)
        return;
    inorderTraversal(pRoot->left, func);
    func(pRoot->pItem);
    inorderTraversal(pRoot->right, func);
}
void postorderTraversal(const Trnode *const pRoot, void (*func)(void *))
{
    if (!pRoot)
        return;
    postorderTraversal(pRoot->left, func);
    postorderTraversal(pRoot->right, func);
    func(pRoot->pItem);
}