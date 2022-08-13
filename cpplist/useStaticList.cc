#include "staticList.cpp"
#define N 3
template <typename T>
void print(const T *pData)
{
    std::cout << *pData << std::endl;
}
int main(void)
{
    staticList<int> sL(N);
    for (int i = 0; i < N; ++i)
    {
        sL.insertFront(&i);
    }
    sL.show(print);
    std::cout<<sL.getNextAvailable();
    return 0;
}