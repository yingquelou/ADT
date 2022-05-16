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
typedef struct nodeL
{
    void *pData;
    struct nodeL *Next;
} * StackL, StackNodeL;
/* 操作：   初始化栈                     */
/* 前提条件： ps 指向一个栈                   */
/* 后置条件： 该栈被初始化为空                 */
void InitStackL(StackL *const ps);
/* 操作：   检查栈是否为空                  */
/* 前提条件： ps 指向之前已被初始化的栈            */
/* 后置条件： 如果栈为空，该函数返回true；否则，返回false   */
bool IsEmptyStackL(const StackL *const ps);
/* 操作：   把项压入栈顶                   */
/* 前提条件： ps 指向之前已被初始化的栈            */
/*       pData 指向待压入栈顶的项              */
/* 当空间开辟失败返回true,否则返回false */
bool PushStackL(StackL *const ps, void *const pData);
/* 操作：   从栈顶删除项                   */
/* 前提条件： ps 指向之前已被初始化的栈            */
/* 后置条件： 如果栈不为空，把栈顶的item拷贝到*pitem，    */
/*   如果该操作后栈中没有项，则重置该栈为空。        */
/*   如果删除操作之前栈为空，栈不变，该函数返回false     */
bool PopStackL(StackL *const ps, void **const ppData);
/* 操作：   检查栈是否已满                  */
/* 前提条件： ps 指向之前已被初始化的栈            */
/* 后置条件： 如果栈已满，该函数返回true；否则，返回false   */

#endif