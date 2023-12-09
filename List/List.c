#include <stdio.h>
#include <stdlib.h>
#include "list.h"
struct node
{
	// 数据域类型的指针
	void *data;
	// 指针域
	ListNode *prev;
	ListNode *next;
	// 以上三个指针都应指向动态分配的对象
};
ListNode *listBegin(ListNode *node)
{
	ListNode *begin = NULL;
	while (node)
	{
		begin = node;
		node = node->prev;
	}
	return begin;
}
ListNode *listEnd(ListNode *node)
{
	ListNode *end = NULL;
	while (node)
	{
		end = node;
		node = node->next;
	}
	return end;
}
ListNode *listInsertAfterNode(ListNode *node, void *d)
{
	ListNode *cur = malloc(sizeof(ListNode));
	cur->data = d;
	if (node)
	{
		cur->next = node->next;
		cur->prev = node;

		node->next = cur;

		if (cur->next)
			cur->next->prev = cur;
	}
	else
	{
		cur->next = NULL;
		cur->prev = NULL;
	}
	return cur;
}
ListNode *listInsertBeforeNode(ListNode *node, void *d)
{
	if (!node)
		return listInsertAfterNode(NULL, d);
	if (node->prev)
		return listInsertAfterNode(node->prev, d);
	else
	{
		node->prev = listInsertAfterNode(NULL, d);
		node->prev->next = node;
		return node->prev;
	}
}
ListNode *listPushBack(List head, void *d)
{
	return listInsertAfterNode(listEnd(head), d);
}
ListNode *listPushFront(List head, void *d)
{
	return listInsertBeforeNode(listBegin(head), d);
}
void listForEach(ListNode *node, listOperator func, void *arg)
{
	node = listBegin(node);
	while (node)
	{
		func(node->data, arg);
		node = node->next;
	}
}
List listMap(ListNode *node, listOperator func, void *arg)
{
	node = listBegin(node);
	ListNode *list = NULL;
	while (node)
	{
		list = listPushBack(list, func(node->data, arg));
		node = node->next;
	}
	return list;
}
void listDestroy(ListNode *node, listOperator func, void *arg)
{
	node = listBegin(node);
	ListNode *destroy = NULL;
	while (node)
	{
		if (func)
			func(node->data, arg);
		destroy = node;
		node = node->next;
		free(destroy);
	}
}
ListNode *listSearch(ListNode *node, listOperator func, void *arg)
{
	if (!node || !func)
		return NULL;
	node = listBegin(node);
	while (node)
	{
		if (func(node->data, arg))
			node = node->next;
		else
			break;
	}
	return node;
}
ListNode *listDeleteNode(ListNode *node, void **pData)
{
	if (!node)
	{
		*pData = NULL;
		return NULL;
	}
	ListNode *front = node->prev;
	if (front)
	{
		front->next = node->next;
		if (front->next)
			front->next->prev = front;
	}
	else
		front = node->next;
	*pData = node->data;
	node->next = NULL;
	node->prev = NULL;
	node->data = NULL;
	free(node);
	return front;
}
ListNode *listPopFront(ListNode *node, void **pData)
{
	return listDeleteNode(listBegin(node), pData);
}
ListNode *listPopBack(ListNode *node, void **pData)
{
	return listDeleteNode(listEnd(node), pData);
}
