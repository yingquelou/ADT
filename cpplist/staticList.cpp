#include "staticList.h"
template <class T>
staticList<T>::staticList(const size_t num)
{

    if ((num + 2) >= MINSPACE && (begin = new Elem[n = num + 2]))
    {
        begin[0].cur = 0;
        begin[0].pData = nullptr;
        for (size_t i = 1; i < (n - 1); ++i)
        {
            begin[i].pData = nullptr;
            begin[i].cur = i + 1;
        }
        begin[n - 1].pData = nullptr;
        begin[n - 1].cur = 0;
    }
    else
    {
        n = 0;
        begin = nullptr;
    }
}
template <class T>
bool staticList<T>::isEmpty()
{
    if (n < MINSPACE || begin[0].cur == 0)
        return true;
    return false;
}
template <class T>
auto staticList<T>::getNextAvailable() const -> staticList<T>::size_t
{
    if (n < MINSPACE || begin[1].cur == 0)
        // 此时表明已无可用结点
        return 0;
    else
        return begin[1].cur;
}
template <class T>
bool staticList<T>::insertFront(const T *pData) const
{
    if (pData)
        if (auto i = getNextAvailable())
            if (T *pD = new T)
            {
                *pD = *pData;
                begin[1].cur = begin[i].cur;
                begin[i].pData = pD;
                begin[i].cur = begin[0].cur;
                begin[0].cur = i;
                return true;
            }
    return false;
}
template <class T>
void staticList<T>::show(staticList<T>::function pf)
{
    if (!isEmpty())
        for (auto i = begin[0].cur; i; i = begin[i].cur)
            if (pf)
                pf(begin[i].pData);
            else
                std::cout << *(begin[i].pData) << std::ends;
}