#define N 7
#include "MY_SIZEOF.h"
#include<stdlib.h>
typedef enum
{
	male,
	female
}SEX;
typedef struct
{
	char* Name;
	SEX Sex;
	size_t Age;
}Stu;
typedef struct noknow
{
	Stu *student;
	struct noknow* Next;
}Form;
int main(void)
{
	Form* temp, * head = NULL, * Linshi;
	temp = malloc(sizeof(Form));
	if (!temp)
		exit(EXIT_FAILURE);
	printf("%p ", temp);
	head = temp;
	size_t i;
	temp = malloc(sizeof(Form));
	if (!temp)
		exit(EXIT_FAILURE);
	printf("%p ", temp);
	head->Next = temp;
	Linshi = temp;
	/*for (i = 0; i < 2; i++)
		printf("%9c",' ');*/
	for (i = 0; i <N; i++)
	{
		temp = malloc(sizeof(Form));
		if (!temp)
			exit(EXIT_FAILURE);
		Linshi->Next = temp;
		printf("%p ", temp);
		Linshi = Linshi->Next;
		Linshi->Next = NULL;
	}
	printf("\n");
	temp = head;
	while (temp)
	{
		printf("%p ", temp);
		temp = temp->Next;
	}
	printf("\n");
	printf("%d", sizeof(*temp));
	return 0;
}