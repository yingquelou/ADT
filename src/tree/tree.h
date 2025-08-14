#pragma once
#ifndef TREE_H
#define TREE_H 1
#include <stdlib.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C"
{
#endif
#ifdef _MSC_VER
#ifdef tree_EXPORTS
#define TREE_API __declspec(dllexport)
#else
#define TREE_API __declspec(dllimport)
#endif
#else
#define TREE_API
#endif
// used as a parameter of `fprintf` or `printf`,
// such as fprintf(filename,reportExceptions(e))
// or printf(reportExceptions(e)).
// tip: The `e` must be a character string.
#define reportExceptions(e)       \
"%s %s %s %s:%d:%s\n", \
__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, e
#define NullPointerException "NullPointerException"

// 节点类型
typedef struct trnode
{
    void *pItem;
    struct trnode *left, *right;
} Trnode;
// 树类型——存放根节点及实时节点数量
typedef struct tree
{
    Trnode *root;
    int size;
} Tree;
/**
 * \brief 初始化树
 *
 * \param pTree 指向要被初始化的树
 * \retval true 成功
 * \retval false 失败
 * \date by yingquelou at 2022-06-28 11:06:39
 */
TREE_API bool initTree(Tree *const pTree);
/**
 * \brief 检查树是否为空
 * \param pTree 指向树
 * \retval true 树为空
 * \retval false 树非空
 * \date by yingquelou at 2022-06-28 11:14:44
 */
TREE_API bool isTreeEmpty(const Tree *const pTree);
/**
 * \brief 清空树,效果等同于调用initTree后的状态
 * \param pTree 指向已初始化的树
 * \retval true 成功
 * \retval false pTree为NULL或树为空
 * \date by yingquelou at 2022-06-28 11:25:28
 */
TREE_API bool clearTree(Tree *const pTree);
/* 节点元素的比较函数指针类型 */
typedef int (*CompareFunction)(const void *, const void *);
/**
 * \brief 向树中添加元素
 *
 * \param pTree 指向已初始化的树
 * \param pItem 指向待插入元素(应是动态分配的)
 * \param cmp 节点元素的比较函数
 * \retval true 成功
 * \retval false 参数不合法或内部实现中内存开辟失败时
 * \date by yingquelou at 2022-06-28 18:45:30
 */
TREE_API bool addItem(Tree *const pTree, void *const pItem, const CompareFunction cmp);
/**
 * \brief 以前序遍历的方式对树中的每个元素应用某个函数,例如显示元素内容
 * \param pRoot 指向树的根节点
 * \param func 指向某个函数,该函数只有一个参数,且必须是指向元素类型的指针
 * \date by yingquelou at 2022-06-28 20:31:56
 */
TREE_API void preorderTraversal(const Trnode *const pRoot, void (*func)(void *));
/**
 * \brief 以中序遍历的方式对树中的每个元素应用某个函数,例如显示元素内容
 * \param pRoot 指向树的根节点
 * \param func 指向某个函数,该函数只有一个参数,且必须是指向元素类型的指针
 * \date by yingquelou at 2022-06-28 20:57:02
 */
TREE_API void inorderTraversal(const Trnode *const pRoot, void (*func)(void *));
/**
 * \brief 以后序遍历的方式对树中的每个元素应用某个函数,例如显示元素内容
 * \param pRoot 指向树的根节点
 * \param func 指向某个函数,该函数只有一个参数,且必须是指向元素类型的指针
 * \date by yingquelou at 2022-06-28 21:31:49
 */
TREE_API void postorderTraversal(const Trnode *const pRoot, void (*func)(void *));
/**
 * \brief 删除树中的某个元素
 * \param pTree 指向树
 * \param pItem 指向处理元素
 * \param cmp 节点元素的比较函数
 * \retval true 成功
 * \retval false 参数不合法或要删除的元素不存在
 * \date by yingquelou at 2022-07-02 21:59:47
 */
TREE_API bool deleteItem(Tree *const pTree, void *const pItem, const CompareFunction cmp);
#ifdef __cplusplus
}
#endif
#endif
