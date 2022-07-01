#include <iostream>
#include <Windows.h>
class base
{
public:
    virtual int add();
};
class A : public base
{
public:
    int add() { return 1; }
};
class B : public base
{
public:
    int add() { return 2; }
};
/**
 * \brief 
 * \param 
 * \return  yfdyt
 * \createdtime by yingquelou at 2022-07-01 21:04:40
 */
int call(base *b) { return b->add(); }
/**
 * \brief 
 * \return  
 * \createdtime by yingquelou at 2022-07-02 00:04:15
 */
int main(void)
{
    B b = B();
    A a = A();
    std::cout << call(&a) << std::endl
              << call(&b) << std::endl;
    return 0;
}