#include "List.h"
#include <stdlib.h>
List *listCreate()
{
    return calloc(1, sizeof(List));
}
bool listIsEmpty(List *pl)
{
    return pl ? (*pl ? false : true) : true;
}
Node *listLastNode(List *pl)
{
    if (!pl)
        return NULL;
    Node *cur = *pl, *last = NULL;
    while (cur)
    {
        last = cur;
        cur = cur->Next;
    }
    return last;
}
Node *nodeCreate(const void *Data)
{
    Node *node = malloc(sizeof(Node));
    if (node)
    {
        node->Date = (void *)Data;
        node->Next = NULL;
    }
    return node;
}
bool listPush(List *pl, const void *Data)
{
    if (!pl || !Data)
        return false;
    Node *cur = nodeCreate(Data);
    if (!cur)
        return false;
    Node *last = listLastNode(pl);
    if (last)
        last->Next = cur;
    else
        *pl = cur;
    return true;
}
void listForeach(List *pl, Func fun)
{
    if (!pl || !fun)
        return;
    Node *cur = *pl;
    while (cur)
    {
        fun(cur->Date);
        cur = cur->Next;
    }
}
void listDestroy(List *pl)
{
    if (!pl)
        return;
    Node *cur = *pl, *tmp = NULL;
    while (cur)
    {
        tmp = cur;
        cur = cur->Next;
        free(tmp);
    }
    *pl = NULL;
}
size_t listLength(const List *pl)
{
    if (!pl)
        return 0;
    Node *cur = *pl;
    size_t lg = 0;
    while (cur)
    {
        ++lg;
        cur = cur->Next;
    }
    return lg;
}
void listQsort(List *pl, const Comparator cmp)
{
    size_t lg = listLength(pl);
    if (lg < 2)
        return;
    void **arr = malloc(sizeof(void *) * lg);
    size_t i;
    Node *cur;
    for (i = 0, cur = *pl; cur; ++i, cur = cur->Next)
        arr[i] = cur->Date;
    qsort(arr, lg, sizeof(void *), cmp);
    for (i = 0, cur = *pl; cur; ++i, cur = cur->Next)
        cur->Date = arr[i];
}
