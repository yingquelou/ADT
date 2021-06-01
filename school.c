#include "school.h"
enum Sex
{
	male,
	famale
};
#pragma pack(4)
typedef struct student
{

	char Name[MAX];
	enum Sex sex;
	char Calss[MAX];
	int Age;
	char Tel[MAX];
}Stu;
#pragma pack()