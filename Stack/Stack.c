#include "Stack.h"
void InitStackL(StackL *const ps)
{
    *ps = NULL;
}
bool IsEmptyStackL(const StackL *const ps)
{
    return *ps ? false : true;
}
bool PushStackL(StackL *const ps, void *const pData)
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
bool PopStackL(StackL *const ps, void **const ppData)
{
    if (IsEmptyStackL(ps))
        return false;
    *ppData = (*ps)->pData;
    StackNodeL *tmp = *ps;
    *ps = (*ps)->Next;
    free(tmp);
    return true;
}