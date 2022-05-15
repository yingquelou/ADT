// #include <stdio.h>
#include "list.c"
#include <time.h>
int main(void)
{
	srand((unsigned)time(NULL));
	list head = initList();
	list tmp = head;
	Data *pitem;
	size_t i;
	pitem = malloc(sizeof(Data));
	for (i = 0; i < 3; ++i)
	{
		pitem->t = rand() % 11;
		insertNodeBack(tmp, pitem);
		tmp = tmp->next;
	}
	/* Lqsort(head, dataCompare);
	TraverseList(head, printData);
	puts(""); */
	/* if (reverseList(&head))
	{
		TraverseList(head, printData);
		puts("");
	} */
	Data a;
	a.t = 78;
	list b = searchPrior(head, &a);
	/* if (b)
		printf("%p ", b); */
	// DestroyList(&head);
	end(head)->next = initListC();
	insertNodeBackC(hasCycle(head), &a);
	TraverseListC(head, printData);
	printf("\t%zd\n%", getListLengthC(head));
	DestroyListC(&head);
	return 0;
}