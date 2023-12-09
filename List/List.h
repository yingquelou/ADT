#pragma once
#ifndef LISTD_H
#define LISTD_H 1
#ifdef __cplusplus
extern "C"
{
#endif
	// 定义双向链表	doubly linked list
	typedef struct node *List, ListNode;
	// 链表存在的话返回其首节点，否则返回空指针
	ListNode *listBegin(ListNode *);
	// 链表存在的话返回其尾结点，否则返回空指针
	ListNode *listEnd(ListNode *);
	/**
	 * \brief 在链表某个结点之后插入一个新的结点用于放置某个数据
	 * \param node 当参数为NULL时,函数等同于创建一个节点(也可以认为是只含有首元节点的新链表)
	 * \param d 指向待插入的数据
	 * \return 新的结点
	 * \date by yingquelou at 2023-09-17 10:38:23
	 */
	ListNode *listInsertAfterNode(ListNode *node, void *d);
	/**
	 * \brief 在链表某个结点之前插入一个新的结点用于放置某个数据
	 * \param node 当参数为NULL时,函数等同于创建一个节点(也可以认为是只含有首元节点的新链表)
	 * \param d 指向待插入的数据
	 * \return 新的结点
	 * \date by yingquelou at 2023-09-17 10:38:23
	 */
	ListNode *listInsertBeforeNode(ListNode *node, void *d);
	/**
	 * \brief 在链表末尾插入一个新的结点用于放置某个有效数据
	 *
	 * \return  成功返回该新节点,否则返回NULL
	 * \date by yingquelou at 2023-09-14 20:10:19
	 */
	ListNode *listPushBack(List, void *);
	ListNode *listPushFront(List, void *);
	typedef void *(*listOperator)(void *, void *);
	/**
	 * \brief 遍历链表,对各结点的数据域调用某个函数做某种操作
	 * 本函数的第三个参数会被转发给操作子的第二个参数
	 * 操作子的第一个参数用于接收数据
	 * 注意:本函数的第一个参数可以不是链表头结点,
	 * 但依旧是对整个链表进行操作
	 * \date by yingquelou at 2023-09-14 20:17:55
	 */
	void listForEach(ListNode *, listOperator, void *);
	/**
	 * \brief 在映射规则(listOperator)的作用下,将原链表映射为新链表
	 * 借用数学上的映射概念:listOperator的第一个参数接受原像,listOperator的返回值即为像
	 * \return 新链表
	 * \date by yingquelou at 2023-10-03 20:13:23
	 */
	List listMap(ListNode *, listOperator, void *);
	/**
	 * \brief 销毁链表
	 * 行为与ListDForEach函数相同,但同时进行链表的销毁
	 * 当第二个参数为NULL时,表示只销毁链表本身,此时第三个参数无意义
	 * \date by yingquelou at 2023-09-14 20:47:49
	 */
	void listDestroy(ListNode *, listOperator, void *);
	/**
	 * \brief 返回第一个满足要求(能令操作子返回NULL)的节点.
	 * 本函数的第三个参数会被转发给操作子的第二个参数
	 * 操作子的第一个参数用于接收数据域指针
	 * 在listDSearch的实现中,不会对操作子的返回值进行任何解引用操作
	 * \return 未找到返回NULL
	 * \date by yingquelou at 2023-09-15 18:31:24
	 */
	ListNode *listSearch(ListNode *, listOperator, void *);
	/**
	 * \return 当被删除节点为NULL时返回NULL,表示删除失败;
	 * 被删除节点保存的数据将通过第二个参数返回
	 * 当被删除节点非NULL时,返回其前向节点;若前向节点为空则返回后向节点
	 *
	 * \date by yingquelou at 2023-09-14 21:27:00
	 */
	ListNode *listDeleteNode(ListNode *, void **);
	ListNode *listPopFront(ListNode *, void **);
	ListNode *listPopBack(ListNode *node, void **pData);
#endif
#ifdef __cplusplus
}
#endif