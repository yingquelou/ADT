#pragma once
#include <stdlib.h>
#include <stdbool.h>
/* 二叉树 */
typedef struct trnode
{
    void *pItem;
    struct trnode *left, *right;
} Trnode;
typedef struct tree
{
    Trnode *root;
    int size;
} Tree;
/**
 * \brief
 *
 * \param pTree 指向树
 * \return
 * \createdtime by yingquelou at 2022-06-28 11:06:39
 */
bool initTree(Tree *const pTree);
/**
 * \brief
 *
 * \param pTtree
 * \return
 * \createdtime by yingquelou at 2022-06-28 11:14:44
 */
bool isTreeEmpty(const Tree *const pTree);
/**
 * \brief
 *
 * \param pTree
 * \return
 * \createdtime by yingquelou at 2022-06-28 11:25:28
 */
bool clearTree(Tree *const pTree);
typedef int (__cdecl *CompareFunction)(const void *, const void *);
/**
 * \brief 
 * 
 * \param pTree 
 * \param pItem 
 * \param cmp 
 * \return  
 * \createdtime by yingquelou at 2022-06-28 18:45:30
 */
bool addItem(Tree *const pTree, void *const pItem, const CompareFunction cmp);