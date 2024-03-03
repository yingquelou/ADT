#include "list.h"
#include <stdio.h>

void *print(void *str, void *arg)
{
    printf("%s", (char *)str);
    return NULL;
}
int main()
{
    List list = listInsertAfterNode(NULL, (void *)"dsd");
    listDestroy(list, print, NULL);
    return 0;
}
