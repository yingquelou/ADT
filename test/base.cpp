#include <iostream>
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
int call(base *b) { return b->add(); }
int main(void)
{
    B b = B();
    A a = A();

    std::cout << call(&a) << std::endl
              << call(&b) << std::endl;
    return 0;
}