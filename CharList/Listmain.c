#include "List.c"
#include <ctype.h>
int main(void)
{
    Node *head;
    initlink(&head);
    Data ch;
    while ((isalpha(ch = getchar()) || ch == '\''))
    {
        InsertNode(ch, &head);
    }
    ShowList1(head);
    ShowList2(head);
    printf("\n%p\n", head);
    FreeList(&head);
    printf("%p\n", head);
    return 0;
}