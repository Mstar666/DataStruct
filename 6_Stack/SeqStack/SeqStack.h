/*
******************************************************************************************************* 
* Filename     : SeqStack.h
* Author       : Peterson
* Created      : 2013/01/09
* Description  : 顺序栈头文件，声明顺序栈的创建、销毁、清空、入栈、出栈、获得栈大小与容量等函数
******************************************************************************************************** 
*/ 
#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

typedef void SeqStack;

SeqStack* SeqStack_Create(int capacity);

void SeqStack_Destroy(SeqStack* stack);

void SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack, void* item);

void* SeqStack_Pop(SeqStack* stack);

void* SeqStack_Top(SeqStack* stack);

int SeqStack_Size(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);

#endif
