#include "Stack.h"
/* 一、顺序栈  sequence stack  -->StackS */
bool InitStackS(StackS *ps, const unsigned stacksize)
{
    if (ps->base = calloc(stacksize, sizeof(void *)))
    {
        ps->top = ps->base;
        ps->maxlength = stacksize;
        return true;
    }
    return false;
}
bool IsFullStackS(const StackS *const ps)
{
    if ((ps->top - ps->base) == ps->maxlength)
        return true;
    return false;
}
bool PushStackS(StackS *const ps, const void *const pData)
{
    if (IsFullStackS(ps))
        return false;
    *(ps->top++) = pData;
    return true;
}
bool IsEmptyStackS(const StackS *const ps)
{
    return ps->base == ps->top;
}
bool PopStackS(StackS *const ps, const void **const ppData)
{
    if (IsEmptyStackS(ps))
        return false;
    --ps->top;
    *ppData = *ps->top;
    *ps->top = NULL;
    return true;
}
void OutFromStackS(const StackS *ps, const pFunc OutPut, FILE *const out)
{
    if (IsEmptyStackS(ps))
        return;
    const void **cur = ps->top;
    while (cur != ps->base)
        // OutPut内部实现需要将第二个参数强制类型转换成一个指向元素的指针,
        //返回值不使用
        // 详解见示例
        OutPut(out, (void *)*--cur);
}
void StreamToStackS(StackS *const ps, const pFunc InPut, FILE *const in)
{
    // InPut内部实现需要将第二个参数强制类型转换成一个指向元素的指针的指针
    // 且元素空间须是动态分配的,且通过解引用这个二级指针传递元素空间的地址
    // InPut返回false要表示读取失败,返回true要表示读取成功
    // 详解见示例
    while (!IsFullStackS(ps) && InPut(in, ps->top++))
        continue;
}
/* 二、链栈    list stack      -->StackL */
inline void InitStackL(StackL *const ps)
{
    *ps = NULL;
}
bool IsEmptyStackL(const StackL *const ps)
{
    return *ps ? false : true;
}
bool PushStackL(StackL *const ps, const void *const pData)
{
    if (*ps)
    {
        StackNodeL *pNode = malloc(sizeof(StackNodeL));
        if (!pNode)
            return false;
        pNode->Next = *ps;
        pNode->pData = pData;
        *ps = pNode;
        return true;
    }
    else if (*ps = malloc(sizeof(StackNodeL)))
    {
        (*ps)->Next = NULL;
        (*ps)->pData = pData;
        return true;
    }
    return false;
}
bool PopStackL(StackL *const ps, const void **const ppData)
{
    if (IsEmptyStackL(ps))
        return false;
    *ppData = (*ps)->pData;
    StackNodeL *tmp = *ps;
    *ps = (*ps)->Next;
    free(tmp);
    return true;
}