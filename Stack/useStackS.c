#include "Stack.c"
/* 顺序栈测试示例 */
#define count 6
bool readElem(FILE *const in, void *ppElem)
{
    int *pElem = NULL;
    if (in && ppElem && (pElem = malloc(sizeof(int))) && 1 == fscanf(in, "%d", pElem))
    {
        *(int **)ppElem = pElem;
        return true;
    }
    else if (pElem)
    {
        free(pElem);
        pElem = NULL;
    }
    return false;
}
bool printElem(FILE *const out, void *pElem)
{
    if (out && pElem && 1 == fprintf(out, "%d\n", *(int *)pElem))
        return true;
    return false;
}
int main(void)
{
    StackS s;
    InitStackS(&s, count);
    StreamToStackS(&s, readElem, fopen("int.txt", "r"));
    OutFromStackS(&s, printElem, fopen("int copy.txt", "w"));
    return 0;
}