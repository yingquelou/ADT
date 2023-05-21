#include "Stack.c"
#include <string.h>
/* 顺序栈测试示例 */
void *print(void *hs)
{
    printf("%s\n", (char *)hs);
    return NULL;
}
void *Destroy(void *hs)
{
    free(hs);
    return NULL;
}
int main(void)
{
    StackS *ps = CreateStackS(10);
    FILE *f = fopen("int.txt", "r");
    char buffer[256] = {0}, *s;
    size_t n;
    while (fscanf(f, "%s", buffer) != EOF)
    {
        n = strlen(buffer);
        strncpy(s = calloc(n + 1, 1), buffer, n);
        if (!PushStackS(ps, s))
            fprintf(stderr, "%s --- false\n", s);
    }
    fclose(f);
    ForeachS(ps, print);
    ForeachS(ps, Destroy);
    DestroyStackS(ps);
    char str[]="vcsv";
    printf("%s\n", strset(str, 'a'));
    printf("%s\n", str);
    return 0;
}