#ifndef __STACK_H__
#define __STACK_H__
/*
栈的实现(后进先出)
一、顺序栈  sequence stack  -->StackS
二、链栈    list stack      -->StackL
*/
/* stack.h –– 栈的接口 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#ifdef _MSC_VER
#ifdef stack_EXPORTS
#define STACK_API __declspec(dllexport)
#else
#define STACK_API __declspec(dllimport)
#endif
#else
#define STACK_API
#endif
#ifdef __cplusplus
extern "C"
{
#endif
    /* 一、顺序栈  sequence stack  -->StackS */
    typedef struct StackS
    {
        // 栈顶指针
        void **top;
        // 栈底指针
        void **base;
        // 栈的大小尺寸
        unsigned size;
    } StackS;
    /* 操作：   创建一个顺序(静态)栈                     */
    STACK_API StackS *StackSCreate(const unsigned stacksize);
    /**
     * \brief 检查栈是否为空
     * \param ps 栈
     * \return  栈若为空返回true,否则返回false
     * \date by yingquelou at 2023-05-21 18:52:55
     */
    STACK_API bool StackSEmpty(const StackS *const ps);
    STACK_API bool StackSFull(const StackS *const ps);
    STACK_API bool StackSPush(StackS *const ps, const void *const pData);
    /**
     * \brief 出栈
     *
     * \param ps 栈
     * \return  返回出栈的元素
     * \date by yingquelou at 2023-05-21 18:32:42
     */
    STACK_API void *StackSPop(StackS *const ps);
    typedef void *(*Func)(void *);
    /**
     * \brief 对栈中的每个元素执行某个操作
     *
     * \param ps 栈
     * \param fun 自定义操作
     * \date by yingquelou at 2023-05-21 18:59:20
     */
    STACK_API void StackSForeach(const StackS *const ps, const Func fun);
    /**
     * \brief 销毁栈
     * 注意:如果内存是动态分配的,在调用本函数前,
     * 请定义一个Func类型的函数使用Foreach进行恰当的内存释放
     * \param ps 由CreateStackS函数创建的栈,或其他自定义方式动态分配的栈
     * \date by yingquelou at 2023-05-21 17:34:26
     */
    STACK_API void StackSDestroy(StackS *ps);
    /* 二、链栈    list stack      -->StackL */
    typedef struct StackNodeL
    {
        void *pData;
        struct StackNodeL *Next;
    } StackNodeL, *StackL;
    /* 操作：   创建一个栈                     */
    STACK_API StackL *StackLCreate();
    /* 操作：   检查栈是否为空                  */
    /* 后置条件： 如果栈为空，该函数返回true；否则，返回false   */
    STACK_API bool StackLEmpty(const StackL *const ps);
    /* 操作：   把项压入栈顶                   */
    /* 前提条件： pData 指向待压入栈顶的项              */
    /* 当内存开辟失败返回false */
    STACK_API bool StackLPush(StackL *const ps, const void *const pData);
    /* 操作：   从栈顶删除项                   */
    /* 后置条件： 如果栈不为空，返回栈顶的项    */
    /*   如果该操作后栈中没有项，则该栈置空。        */
    /*   如果栈为空，栈不变，该函数返回NULL     */
    STACK_API void *StackLPop(StackL *const ps);
    /**
     * \brief 对栈中的每个元素执行某个操作
     *
     * \param ps 栈
     * \param fun 自定义操作
     * \date by yingquelou at 2023-05-21 18:59:20
     */
    STACK_API void StackLForeach(const StackL *const ps, const Func fun);
    /**
     * \brief 销毁栈
     * 注意:如果内存是动态分配的,在调用本函数前,
     * 请定义一个Func类型的函数使用Foreach进行恰当的内存释放
     * \param ps 由CreateStackL函数创建的栈
     * \date by yingquelou at 2023-05-21 17:34:26
     */
    STACK_API void StackLDestroy(StackL *ps);
#ifdef __cplusplus
}
#endif
#endif
