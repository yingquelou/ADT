#include "Stack.c"
#include <stdio.h>
#include <time.h>
void *print(void *hs)
{
    static int i = 1;
    if (i % 26)
        printf("%c ", *(char *)hs);
    else
        printf("%c\n", *(char *)hs);
    ++i;
    return NULL;
}
void *Destroy(void *hs)
{
    return free(hs), NULL;
}
#define count 90
int main(void)
{
    srand((unsigned)time(NULL));
    StackL *stack = StackLCreate();
    for (unsigned i = 0; i < count; i++)
    {
        char *pch;
        if (pch = malloc(1))
        {
            *pch = rand() % 26 + (rand() % 2 ? 'A' : 'a');
            if (StackLPush(stack, pch))
                continue;
            else
                break;
        }
    }
    StackLForeach(stack, print);
    StackLForeach(stack, Destroy);
    StackLDestroy(stack);
    return 0;
}