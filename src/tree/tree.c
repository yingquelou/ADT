#include "tree.h"
#include <stdio.h>
#include <assert.h>
static FILE *errorFile;
static void initLog()
{
    errorFile = fopen("errorLog.txt", "a+");
    assert(errorFile != NULL);
}
bool initTree(Tree *const pTree)
{
    initLog();
    if (pTree == NULL)
    {
        fprintf(errorFile, reportExceptions(NullPointerException));
        // printf(reportExceptions(NullPointerException));
        return false;
    }
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
 * \param pChildTree 指向某个子树
 * \date by yingquelou at 2022-06-28 11:54:04
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
    fclose(errorFile);
    return true;
}
/**
 * \brief 由addItem调用,动态分配存放元素的节点
 * \retval 返回分配好的节点的指针
 * \date by yingquelou at 2022-07-01 23:10:58
 */
static inline Trnode *makeNode(void)
{
    return calloc(1, sizeof(Trnode));
}
/**
 * \brief 由addItem调用时,用以确定某个元素的插入位置;
 * \b 由deleteItem调用时,用以确定待删除元素的位置;
 * \param pTree 指向树
 * \param pItem 指向待处理元素(应是动态分配的)
 * \param cmp 用于比较元素的函数的指针
 * \retval \b 如果树中已有相同的元素,childNode指向该元素所在节点,parentNode指向相应的父节点
 * \retval \b 如果树中没有相同的元素,childNode为空,
 * \b 此时若parentNode非空,由addItem调用时,新元素将被插入parentNode节点之后,若parentNode为空,由deleteItem调用时,新元素将被插入根节点
 * \retval NULL 当参数不合法时返回NULL;当树是空树时亦返回NULL;
 * \date by yingquelou at 2022-07-01 20:56:14
 */
static struct pair
{
    Trnode *parentNode;
    Trnode *childNode;
} * seekItem(const Tree *const pTree, const void *const pItem, const CompareFunction cmp)
{
    if (pTree == NULL || pTree->size < 1 || pItem == NULL || cmp == NULL)
        return NULL;
    struct pair *ret = calloc(1, sizeof(struct pair));
    if (ret == NULL)
    {
        fprintf(errorFile, "%s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
        return NULL;
    }
    Trnode *cur = pTree->root, *keep = NULL;
    while (cur)
    {
        ret->parentNode = keep;
        keep = cur;
        int flog = cmp(pItem, cur->pItem);
        if (flog > 0)
            cur = cur->right;
        else if (flog == 0)
        {
            ret->childNode = cur;
            break;
        }
        else
            cur = cur->left;
    }
    if (cur == NULL)
        ret->parentNode = keep;
    return ret;
}
bool addItem(Tree *const pTree, void *const pItem, const CompareFunction cmp)
{
    if (pTree == NULL || pItem == NULL || cmp == NULL)
        return false;
    struct pair *si = seekItem(pTree, pItem, cmp);
    Trnode *node = makeNode();
    if (node == NULL)
    {
        fprintf(errorFile, "%s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
        return false;
    }
    node->pItem = pItem;
    if (si)
    {
        if (si->childNode == NULL)
        {
            if (cmp(pItem, si->parentNode->pItem) > 0)
                si->parentNode->right = node;
            else
                si->parentNode->left = node;
            ++pTree->size;
            free(si);
            return true;
        }
        free(si);
    }
    else
    {
        pTree->root = node;
        ++pTree->size;
        return true;
    }
    return false;
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
/**
 * \brief 删除某个树的节点
 * \param ptr 指向目标节点的父节点指针成员的地址
 * \date by yingquelou at 2022-07-02 22:11:29
 */
static void deleteNode(Trnode **const ptr)
{
    Trnode *temp;
    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
    }
    else /* 被删除的节点有两个子节点 */
    {
        /* 找到重新连接右子树的位置 */
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
    }
    free(temp->pItem);
    free(temp);
}
bool deleteItem(Tree *const pTree, void *const pItem, const CompareFunction cmp)
{
    if (pTree == NULL || pItem == NULL || cmp == NULL)
        return false;
    struct pair *si = seekItem(pTree, pItem, cmp);
    if (si)
    {
        if (si->childNode == NULL)
            return false;
        if (si->parentNode == NULL)
        {
            Trnode temp;
            temp.left = si->childNode;
            temp.right = NULL;
            temp.pItem = NULL;
            deleteNode(&(temp.left));
            pTree->root = temp.left;
        }
        else
        {
            if (si->parentNode->left == si->childNode)
                deleteNode(&(si->parentNode->left));
            else
                deleteNode(&(si->parentNode->right));
        }
        --pTree->size;
        return true;
    }
    else
        return false;
}