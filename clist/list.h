#ifndef _LIST_
#define _LIST_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// 数据域的结构
// 需要按照特定的应用场景进行更改
typedef struct
{
	/* you'll define the element'struct that you want here */
	int t;
} Data;
// 当结点间的数据域具有某种偏序关系时的比较函数的类型
// 对不同的偏序关系要设计相应的比较函数,以供Lqsort排序使用
typedef int (*CompareFunction)(void const *, void const *);
typedef bool (*Function)(const Data *);
// 定义单链表
typedef struct list
{
	// 数据域类型的指针
	Data *pE;
	// 指针域
	struct list *next;
	// 以上两个指针都应指向动态分配的对象
} * list, listNode;
// 定义双向链表	doubly linked list
typedef struct dList
{
	// 数据域类型的指针
	Data *pE;
	// 指针域
	struct dList *prev;
	struct dList *next;
	// 以上三个指针都应指向动态分配的对象
} * dList, dListNode;
/* --要分别定义的函数-- */
// 当前的比较函数,不同的偏序关系要区别设计
int dataCompare(const void *, const void *);
// 对不同应用下的数据域,此打印函数要进行相应的设计、更改
void printData(const Data *);
/* ------------------ */

// 单链表初始化————创建了只含头结点的单链表,头结点数据域为空
// 除以上用法外,其实亦可用于创建可空结点
// 成功返回指向头节点的指针,否则返回空指针
list initList(void);
// 创建单向循环链表——会创建一个指针域指向自身的结点,同时结点的数据域为空
// 当把此结点接在某单链表末尾时,会为该单链表创建一个环
// 命名意义:循环链表=>`circular linked list`
// 以`C`为后缀的是循环版本,下同
list initListC(void);
// 以`D`为后缀的是双向链表版本,下同
dList initListD(void);
// 链表存在的话返回其尾结点，否则返回空指针
listNode *end(list);
dListNode *endD(dList);
// 在某个有效结点之后插入一个新的结点用于放置某个有效数据,成功返回true,否则返回false
bool insertNodeBack(listNode *, Data *);
bool insertNodeBackC(listNode *, Data *);
bool insertNodeBackD(dListNode *, Data *);
// 在链表末尾增加结点用以存放新的有效数据
bool insertListBack(list, Data *);
bool insertListBackD(dList, Data *);
// 检查某单链表的某一结点之后是否有环
// 如果有,返回其入环结点,否则返回空指针
// 如果该链表有环(即此时返回值非空),且返回值与传入的参数相等时,说明相应结点在环上
listNode *hasCycle(listNode *);
// 返回某个数据所在结点的前驱结点,失败返回空指针
listNode *searchPrior(list, Data *);
// 仅纯环可用
listNode *searchPriorC(list);
// 遍历链表,对各结点的数据域调用某个函数做某种工作
// 比如:调用特定的的打印函数显示链表的内容
void TraverseList(list, void (*)(const Data *));
void TraverseListC(list, void (*)(const Data *));
void TraverseListD(dList, void (*)(const Data *));
// 从某链表的某结点开始查找第一个满足要求的结点
// 成功返回指向该结点的指针,否则返回空指针
listNode *search(listNode *, const Function);
// 返回单链表长度
size_t getListLength(list);
// 仅纯环可测其长
size_t getListLengthC(list);
// 调用某个比较函数排序链表
bool Lqsort(const list, const CompareFunction);
// 反转链表
// 原链表的头节点依旧是反转链表的头节点
bool reverseList(const list *);
// 清空单链表——会保留头结点
bool clearList(list);
bool clearListC(list);
/** 
 * 销毁单链表——连头结点也会被销毁
 */
bool DestroyList(list *);
/**
 * @brief 
 * @param
 * @return true 
 * @return false 
 */
bool DestroyListC(list *);
bool DestroyListD(dList *);
#endif