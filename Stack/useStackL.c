#include "Stack.c"
#include <stdio.h>
#include <time.h>
#define count 30
int main(void)
{
    srand((unsigned)time(NULL));
    StackL stack;
    InitStackL(&stack);
    for (unsigned i = 0; i < count; i++)
    {
        char *pch;
        if (pch = malloc(sizeof(char)))
        {
            *pch = rand() % 26 + (rand() % 2 ? 'A' : 'a');
            if (PushStackL(&stack, pch))
                continue;
        }
    }
    char *pch;
    while (PopStackL(&stack, (void *)&pch))
    {
        printf("%c ", *pch);
        free(pch);
    }
    puts("");
    return 0;
}