#include "tree.c"
#include <stdio.h>
#include <ctype.h>
int cmp(const void *e1, const void *e2)
{
    return *(char *)e1 - *(char *)e2 /* < 0 ? -1 : 1 */;
}
void print(void *pItem)
{
    printf("%c\t", *(char *)pItem);
}
int main(void)
{
    Tree t;
    initTree(&t);
    char *pCh;
    while (1 == scanf("%c", pCh = malloc(1)) && isgraph(*pCh))
    {
        addItem(&t, pCh, cmp);
    }
    preorderTraversal(t.root, print);
    puts("");
    inorderTraversal(t.root, print);
    puts("");
    postorderTraversal(t.root, print);
    clearTree(&t);
    return 0;
}