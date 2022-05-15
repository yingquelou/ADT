#pragma once
#include <iostream>
/* 最小静态链表的默认值 */
#define MINSPACE 5
// 静态链表(本质上是一个数组)
// 由下标为0的结点管理已用结点
// 由下标为1的结点管理未用结点
// 不一定是0和1,好用就行
// 每一个此模板的类对象都是一个静态链表
template <typename T>
class staticList
{
public:
    // 类型别名
    typedef unsigned long long size_t;
    typedef long long subscript;
    typedef void (*function)(const T *);
    class Elem
    {
        friend class staticList;
        T *pData;
        subscript cur;
    };

private:
    size_t n;
    Elem *begin;

public:
    staticList() = delete;
    staticList(const size_t num = 3);

public:
    bool isEmpty();
    auto getNextAvailable() const -> size_t;
    bool insertFront(const T *pData) const;
    void show(function pf = nullptr);
};
