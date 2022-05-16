#include "List.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
bool IsListFull(pNode *pList);
static Node *TellmeNode(const Data item, Node *node);
static void SetItemToNode(const Data item, Node *const node);
static unsigned TellmeListLength(const Node *List);
void initlink(pNode *pList)
{
    *pList = NULL;
}
void InsertNode(Data item, pNode *pList)
{
    Node *tmp1, *tmp2;
    assert(IsListFull(pList));
    tmp1 = (Node *)malloc(sizeof(Node));
    SetItemToNode(item, tmp1);
    if (tmp2 = TellmeNode(item, *pList))
    {
        tmp1->Next = tmp2->Next;
        tmp2->Next = tmp1;
    }
    else
    {
        tmp1->Next = *pList;
        *pList = tmp1;
    }
}
void ShowList1(const Node *head)
{
    while (head)
    {
        printf("%c", head->Date);
        head = head->Next;
    }
    puts("");
}
void ShowList2(const Node *head)
{
    if (!head)
        return;
    else
        ShowList2(head->Next);
    printf("%c", head->Date);
}
void FreeList(pNode *pList)
{
    Node *tmp;
    while (*pList)
    {
        tmp = (*pList)->Next;
        free(*pList);
        *pList = tmp;
    }
}
//针对不同DAT须有不同实现
static void SetItemToNode(const Data item, Node *const node)
{
    node->Date = item;
}
//针对不同DAT须有不同实现
static Node *TellmeNode(const Data item, Node *node)
{
    Node *tmp = NULL;
    while (node && item >= node->Date)
    {
        tmp = node;
        node = node->Next;
    }
    return tmp;
}
static unsigned TellmeListLength(const Node *List)
{
    unsigned length = 0;
    while (List)
    {
        length++;
        List = List->Next;
    }
    return length;
}
bool IsListFull(pNode *pList)
{
    Node *tmp;
    if (tmp = (Node *)malloc(sizeof(Node)))
    {
        free(tmp);
        return true;
    }
    return false;
}