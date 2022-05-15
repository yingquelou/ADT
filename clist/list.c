#include "list.h"
/* start: must be changed */
/* In different application scenarios, you have to change the function*/
int dataCompare(const void *left, const void *right)
{
	return (*(Data **)left)->t - (*(Data **)right)->t;
}
void printData(const Data *d)
{
	if (d)
		printf("%d\n", d->t);
}
/* end: must be changed */
list initList(void)
{
	list ret;
	if (ret = malloc(sizeof(listNode)))
	{
		ret->pE = NULL;
		ret->next = NULL;
		return ret;
	}
	else
		return NULL;
}
list initListC(void)
{
	list ret = initList();
	if (ret)
	{
		ret->next = ret;
		return ret;
	}
	else
		return NULL;
}
dList initListD(void)
{
	dList ret;
	if (ret = malloc(sizeof(dListNode)))
	{
		ret->pE = NULL;
		ret->prev = NULL;
		ret->next = NULL;
		return ret;
	}
	else
		return NULL;
}
listNode *end(list L)
{
	if (L)
	{
		list tmp = L->next;
		while (tmp)
		{
			L = tmp;
			tmp = tmp->next;
		}
	}
	return L;
}
dListNode *endD(dList L)
{
	if (L)
	{
		dList tmp = L->next;
		while (tmp)
		{
			L = tmp;
			tmp = tmp->next;
		}
	}
	return L;
}
listNode *searchPrior(list head, Data *e)
{
	if (head && e)
	{
		listNode *prior = head;
		head = head->next;
		while (head && !dataCompare(&e, &head->pE))
		{
			prior = head;
			head = head->next;
		}
		if (head)
			return prior;
	}
	return NULL;
}
listNode *searchPriorC(list head)
{
	if (head && hasCycle(head))
	{
		listNode *run = head;
		while (run->next != head)
			run = run->next;
		return run;
	}
	else
		return NULL;
}
bool insertNodeBack(listNode *pNode, Data *pE)
{
	if (pNode && pE)
	{
		listNode *node;
		Data *d;
		if ((node = malloc(sizeof(listNode))) && (d = malloc(sizeof(Data))))
		{
			*d = *pE;
			node->pE = d;
			node->next = pNode->next;
			pNode->next = node;
			return true;
		}
		else if (!d)
			free(node);
	}
	return false;
}
bool insertNodeBackC(listNode *pNode, Data *pE)
{
	if (pNode)
	{
		if (pNode->pE)
		{
			if (insertNodeBack(pNode, pE))
				return true;
		}
		else if (pE)
		{
			Data *d;
			if (d = malloc(sizeof(Data)))
			{
				*d = *pE;
				pNode->pE = d;
				return true;
			}
		}
	}
	return false;
}
bool insertNodeBackD(dListNode *pNode, Data *d)
{
	if (pNode && d)
	{
		dListNode *tmp = malloc(sizeof(dListNode));
		Data *td = malloc(sizeof(Data));
		if (td && tmp)
		{
			*td = *d;
			tmp->pE = td;
			tmp->prev = pNode;
			tmp->next = pNode->next;
		}
		else
		{
			if (td)
				free(td);
			return false;
		}
		if (pNode->next)
		{
			pNode->next->prev = tmp;
			pNode->next = tmp;
			return true;
		}
		else
		{
			if (pNode->pE)
				pNode->next = tmp;
			else
			{
				pNode->pE = td;
				free(tmp);
			}
			return true;
		}
	}
	return false;
}
listNode *search(listNode *pNode, const Function cmp)
{
	if (cmp)
		while (pNode)
		{
			if (cmp(pNode->pE))
				return pNode;
			else
				pNode = pNode->next;
		}
	return NULL;
}
listNode *hasCycle(listNode *pNode)
{
	if (pNode)
	{
		listNode *slow = pNode, *fast = pNode;
		while (slow && fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				// 当能进入此处,说明有环
				fast = pNode;
				while (fast != slow)
				{
					slow = slow->next;
					fast = fast->next;
				}
				return fast;
			}
		}
	}
	return NULL;
}
bool insertListBack(list head, Data *pE)
{
	listNode *last = end(head);
	if (last && insertNodeBack(last, pE))
		return true;
	return false;
}
bool insertListBackD(dList head, Data *d)
{
	dListNode *last = endD(head);
	if (last && insertNodeBackD(last, d))
		return true;
	else
		return false;
}
void TraverseList(list head, void (*func)(const Data *))
{
	while (head)
	{
		if (head->pE)
			func(head->pE);
		head = head->next;
	}
}
void TraverseListC(list head, void (*func)(const Data *))
{
	list keep = hasCycle(head);
	if (keep)
	{
		func(head->pE);
		if (head != keep)
			do
			{
				head = head->next;
				func(head->pE);
				if (head->next)
					puts("");
			} while (keep != head);
		for (head = head->next; head != keep; head = head->next)
		{
			func(head->pE);
			if (head->next)
				puts("");
		}
	}
	else
		TraverseList(head, func);
}
void TraverseListD(dList head, void (*func)(const Data *))
{
	while (head)
	{
		if (head->pE)
			func(head->pE);
		head = head->next;
	}
}
size_t getListLength(list head)
{
	size_t ret = 0;
	while (head)
	{
		++ret;
		head = head->next;
	}
	return ret;
}
size_t getListLengthC(list head)
{
	list keep = hasCycle(head);
	if (keep)
	{
		size_t ret = 1;
		if (head != keep)
			do
			{
				head = head->next;
				++ret;
			} while (keep != head);
		for (head = head->next; head != keep; head = head->next)
			++ret;
		return ret;
	}
	else
		return getListLength(head);
}
bool Lqsort(const list head, const CompareFunction _CompareFunction)
{
	size_t length = getListLength(head) - 1;
	Data **el;
	if (head && (el = malloc(sizeof(Data *) * length)))
	{
		listNode *start = head->next;
		for (size_t i = 0; i < length; ++i)
		{
			el[i] = start->pE;
			start = start->next;
		}
		qsort(el, length, sizeof(Data *), _CompareFunction);
		start = head->next;
		for (size_t i = 0; i < length; ++i)
		{
			start->pE = el[i];
			start = start->next;
		}
		return true;
	}
	else
		return false;
}
bool reverseList(const list *pHead)
{
	list cur, moved, nextmoved;
	if (pHead && *pHead)
		cur = (*pHead)->next;
	else
		return false;
	if (cur && cur->next)
	{
		moved = cur->next;
		cur->next = NULL;
		while (moved)
		{
			nextmoved = moved->next;
			moved->next = cur;
			cur = moved;
			moved = nextmoved;
		}
		(*pHead)->next = cur;
		return true;
	}
	return false;
}
bool clearList(list head)
{
	if (head)
	{
		list tmp = head->next, del;
		head->next = NULL;
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
			if (del->pE)
				free(del->pE);
			free(del);
		}
		return true;
	}
	else
		return false;
}
bool clearListC(list head)
{
	listNode *e = searchPriorC(head);
	if (e)
	{
		e->next = NULL;
		clearList(head);
		free(head->pE);
		head->pE = NULL;
		return true;
	}
	else
		return false;
}
bool DestroyListC(list *pHead)
{
	listNode *hc = hasCycle(*pHead);
	if (hc)
	{
		clearListC(hc);
		if (hc == *pHead)
		{
			free(hc);
			*pHead = NULL;
			return true;
		}
	}
	if (DestroyList(pHead))
		return true;
	else
		return false;
}
bool DestroyList(list *pHead)
{
	if (!pHead)
		return false;
	clearList(*pHead);
	free(*pHead);
	*pHead = NULL;
	return true;
}