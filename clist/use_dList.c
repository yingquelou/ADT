#include "list.c"
const size_t N = 3;
int main(void)
{
    dList h = initListD();
    Data a;
    for (size_t i = 0; i < N; ++i)
    {
        if (1 == scanf("%d", &a.t))
            insertListBackD(h, &a);
    }
    TraverseListD(h, printData);
    return 0;
}