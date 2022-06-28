#include "tree.h"
/**
 * @brief Create a Tree object
 *
 * @return Tree
 */
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
 * \brief
 *
 * \param pChildTree
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
static inline Trnode *makeNode(void)
{
    return calloc(1, sizeof(Trnode));
}
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
    if (pTree == NULL)
        return false;
    Trnode *pos = seekAddPosition(pTree, pItem, cmp);
    Trnode *node = makeNode();
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
}
/**
 * \brief 前序遍历
 *
 * \param pRoot
 * \param func
 * \createdtime by yingquelou at 2022-06-28 20:31:56
 */
void preorderTraversal(const Trnode *const pRoot, void (*func)(void *))
{
    if (!pRoot)
        return;
    func(pRoot->pItem);
    preorderTraversal(pRoot->left, func);
    preorderTraversal(pRoot->right, func);
}
/**
 * \brief 中序遍历
 *
 * \param pRoot
 * \param func
 * \createdtime by yingquelou at 2022-06-28 20:57:02
 */
void inorderTraversal(const Trnode *const pRoot, void (*func)(void *))
{
    if (!pRoot)
        return;
    inorderTraversal(pRoot->left, func);
    func(pRoot->pItem);
    inorderTraversal(pRoot->right, func);
}
/**
 * \brief 后序遍历
 * 
 * \param pRoot 
 * \param func 
 * \createdtime by yingquelou at 2022-06-28 21:31:49
 */
void postorderTraversal(const Trnode *const pRoot, void (*func)(void *))
{
    if (!pRoot)
        return;
    inorderTraversal(pRoot->left, func);
    inorderTraversal(pRoot->right, func);
    func(pRoot->pItem);
}