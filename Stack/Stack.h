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
/* 一、顺序栈  sequence stack  -->StackS */
typedef struct ss
{
    const void **top;
    const void **base;
    unsigned maxlength;
} StackS;
typedef bool (*pFunc)(FILE *const, void *const);
/* 操作：   初始化栈                     */
/* 前提条件： ps 指向一个栈               */
bool InitStackS(StackS *ps, const unsigned maxlength);
bool IsFullStackS(const StackS *const ps);
bool PushStackS(StackS *const ps, const void *const pData);
bool IsEmptyStackS(const StackS *const ps);
bool PopStackS(StackS *const ps, const void **const ppData);
// 调用OutPut函数(需要根据结点元素类型定义的函数)将栈的内容输出到流out
// OutPut函数:只须定义单个元素的输出规则
void OutFromStackS(const StackS *ps, const pFunc OutPut, FILE *const out);
// 用于测试:调用InPut函数(需要根据结点元素类型定义的函数)从流in中读取数据到栈中
// ps最好是空栈
// 当栈满或数据读完时返回
// InPut函数:只须定义单个元素的读取(输入)规则;
void StreamToStackS(StackS *const ps, const pFunc InPut, FILE *const in);
/* 二、链栈    list stack      -->StackL */
typedef struct nodeL
{
    const void *pData;
    struct nodeL *Next;
} StackNodeL, *StackL;
/* 操作：   初始化栈                     */
/* 前提条件： ps 指向一个栈                   */
/* 后置条件： 该栈被初始化为空                 */
inline void InitStackL(StackL *const ps);
/* 操作：   检查栈是否为空                  */
/* 前提条件： ps 指向之前已被初始化的栈            */
/* 后置条件： 如果栈为空，该函数返回true；否则，返回false   */
bool IsEmptyStackL(const StackL *const ps);
/* 操作：   把项压入栈顶                   */
/* 前提条件： ps 指向之前已被初始化的栈            */
/*       pData 指向待压入栈顶的项              */
/* 当空间开辟失败返回true,否则返回false */
bool PushStackL(StackL *const ps, const void *const pData);
/* 操作：   从栈顶删除项                   */
/* 前提条件： ps 指向之前已被初始化的栈            */
/* 后置条件： 如果栈不为空，把栈顶的item拷贝到*pitem，    */
/*   如果该操作后栈中没有项，则重置该栈为空。        */
/*   如果删除操作之前栈为空，栈不变，该函数返回false     */
bool PopStackL(StackL *const ps, const void **const ppData);
/* 操作：   检查栈是否已满                  */
/* 前提条件： ps 指向之前已被初始化的栈            */
/* 后置条件： 如果栈已满，该函数返回true；否则，返回false   */
#endif