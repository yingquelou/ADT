#include "tree.c"
#include <stdio.h>
#include <ctype.h>
int cmp(const void *e1, const void *e2)
{
    return *(char *)e1 - *(char *)e2 /* < 0 ? -1 : 1 */;
}
/**
 * \brief
 *
 * \param pItem
 * \date by yingquelou at 2022-08-13 16:29:35
 */
void print(void *pItem)
{
    if (pItem)
        printf("%c", *(char *)pItem);
}
int main(void)
{
    Tree t;
    if (!initTree(&t))
        return 0;
    char *pCh;
    while (1 == scanf("%c", pCh = malloc(1)) && (isgraph(*pCh) ? 1 : (free(pCh), 0)))
    {
        addItem(&t, pCh, cmp);
    }
    preorderTraversal(t.root, print);
    puts("");
    inorderTraversal(t.root, print);
    puts("");
    postorderTraversal(t.root, print);
    printf("\n%d", t.size);
    puts("");
    clearTree(&t);
    return 0;
}
