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
    StackS *ps = CreateStackS(10);
    PushStackS(ps, "abc");
    PushStackS(ps, "defg");
    ForeachS(ps, print);
    // ForeachS(ps, Destroy);
    DestroyStackS(ps);
    return 0;
}