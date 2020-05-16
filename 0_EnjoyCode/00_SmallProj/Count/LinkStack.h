/*
******************************************************************************************************* 
* Filename     : LinkStack.h
* Author       : Peterson
* Created      : 2013/01/10
* Description  : 链式栈头文件，声明栈的创建、销毁、清空、入栈、出栈、获得栈顶元素与栈大小等函数
******************************************************************************************************** 
*/ 
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

typedef void LinkStack;

LinkStack* LinkStack_Create();

void LinkStack_Destroy(LinkStack* stack);

void LinkStack_Clear(LinkStack* stack);

int LinkStack_Push(LinkStack* stack, void* item);

void* LinkStack_Pop(LinkStack* stack);

void* LinkStack_Top(LinkStack* stack);

int LinkStack_Size(LinkStack* stack);

#endif
