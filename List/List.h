#ifndef LIST_H
#define LIST_H 1
#include <stdbool.h>
// 单向链表(无头节点)
typedef struct node
{
    void *Date;
    struct node *Next;
} Node, *List;
// 创建链表
extern List *listCreate();
// 检查链表是否为空
extern bool listIsEmpty(List *);
// 返回链表最后一个有效节点
extern Node *listLastNode(List *);
// 为放置给定数据项创建一个节点
extern Node *nodeCreate(const void *);
// 在链表末端插入一个放置给定数据项的节点
extern bool listPush(List *, const void *);
typedef void *(*Func)(void *);
// 对链表中的每一个数据项执行某种操作
extern void listForeach(List *, Func);
/**
 * \brief 销毁链表
 * 注意:当链表中的数据项是动态分配时,则在调用本函数之前,
 * 请定义某种操作而使用listForeach函数销毁数据项
 * \date by yingquelou at 2023-05-22 18:53:54
 */
extern void listDestroy(List *);
typedef unsigned long long size_t;
extern size_t listLength(const List *);
typedef int (*Comparator)(const void *, const void *);
// 快速排序
extern void listQsort(List *, const Comparator);
#endif
