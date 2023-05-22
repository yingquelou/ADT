/* 测试 */
#include "List.c"
#include <stdio.h>
void *print(void *hs)
{
    return printf("%s ", (char *)hs), NULL;
}
#include <string.h>
int cmp(const void *lhs, const void *rhs)
{
    return -strcmp((char *)lhs, (char *)rhs);
}
int main(void)
{
    List *pL = listCreate();
    listPush(pL, "abcd");
    listPush(pL, "abc");
    listPush(pL, "ab");
    listForeach(pL, print);
    puts("");
    listQsort(pL, cmp);
    listForeach(pL, print);
    listDestroy(pL);
    return 0;
}