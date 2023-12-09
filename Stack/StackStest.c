#include "Stack.c"
#include <string.h>
/* 顺序栈测试示例 */
void *print(void *hs)
{
    return printf("%s\n", (char *)hs), NULL;
}
void *Destroy(void *hs)
{
    free(hs);
    return NULL;
}
int main(void)
{
    StackS *ps = StackSCreate(10);
    StackSPush(ps, "abc");
    StackSPush(ps, "defg");
    StackSForeach(ps, print);
    // ForeachS(ps, Destroy);
    StackSDestroy(ps);
    return 0;
}