#ifndef __SINGLELINK_H__
#define __SINGLELINK_H__
//定义数据项
typedef char Data;
//定义节点
typedef struct node
{
    Data Date;
    struct node *Next;
} Node, *pNode;
#endif