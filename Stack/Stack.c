#include "Stack.h"
/* 一、顺序栈  sequence stack  -->StackS */
StackS *CreateStackS(const unsigned stacksize)
{
    StackS *ps = NULL;
    if (ps = malloc(sizeof(StackS)))
    {
        if (ps->base = calloc(stacksize, sizeof(void *)))
        {
            ps->top = ps->base;
            ps->size = stacksize;
        }
        else
        {
            free(ps);
            ps = NULL;
        }
    }
    return ps;
}
bool IsFullStackS(const StackS *const ps)
{
    if ((ps->top - ps->base) == ps->size)
        return true;
    return false;
}
bool PushStackS(StackS *const ps, const void *const pData)
{
    if (IsFullStackS(ps))
        return false;
    *ps->top++ = (void *)pData;
    return true;
}
bool IsEmptyStackS(const StackS *const ps)
{
    return ps->base == ps->top;
}
void *PopStackS(StackS *const ps)
{
    if (IsEmptyStackS(ps))
        return NULL;
    return *--ps->top;
}
void ForeachS(const StackS *const ps, const Func fun)
{
    if (IsEmptyStackS(ps))
        return;
    void **cur = ps->top;
    while (cur != ps->base)
        fun(*--cur);
}
void DestroyStackS(StackS *ps)
{
    if (ps)
    {
        if (ps->size)
            free(ps->base);
        free(ps);
    }
}
/* 二、链栈    list stack      -->StackL */
bool IsEmptyStackL(const StackL *const ps)
{
    return ps ? (*ps ? false : true) : true;
}
StackL *CreateStackL()
{
    return calloc(1, sizeof(StackL));
}
bool PushStackL(StackL *const ps, const void *const pData)
{
    if (!ps)
        return false;
    if (*ps)
    {
        StackNodeL *pNode = malloc(sizeof(StackNodeL));
        if (!pNode)
            return false;
        pNode->Next = *ps;
        pNode->pData = (void *)pData;
        *ps = pNode;
        return true;
    }
    else if (*ps = malloc(sizeof(StackNodeL)))
    {
        (*ps)->Next = NULL;
        (*ps)->pData = (void *)pData;
        return true;
    }
    return false;
}
void *PopStackL(StackL *const ps)
{
    if (IsEmptyStackL(ps))
        return NULL;
    StackNodeL *tmp = *ps;
    *ps = (*ps)->Next;
    void *pData = tmp->pData;
    free(tmp);
    return pData;
}
void ForeachL(const StackL *const ps, const Func fun)
{
    if (IsEmptyStackL(ps))
        return;
    StackNodeL *cur = *ps;
    while (cur)
    {
        fun(cur->pData);
        cur = cur->Next;
    }
}
void DestroyStackL(StackL *ps)
{
    if (ps)
    {
        StackNodeL *tmp, *cur = *ps;
        while (cur)
        {
            tmp = cur;
            cur = cur->Next;
            free(tmp);
        }
        *ps = NULL;
    }
}