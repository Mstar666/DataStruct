/*
******************************************************************************************************* 
* Filename     : SeqStack.c
* Author       : Peterson
* Created      : 2013/01/09
* Description  : 顺序栈C文件，栈是一种特殊的线性表，只能在表的一端进行操作，采用代码复用，实现高效化
*				顺序栈用表头做栈顶比用表尾做栈顶效率高，因为从表头插入时不需要遍历链表
******************************************************************************************************** 
*/ 
#include "SeqStack.h"
#include "SeqList.h"

SeqStack* SeqStack_Create(int capacity)
{
    return SeqList_Create(capacity);
}

void SeqStack_Destroy(SeqStack* stack)
{
    SeqList_Destroy(stack);
}

void SeqStack_Clear(SeqStack* stack)
{
    SeqList_Clear(stack);
}

int SeqStack_Push(SeqStack* stack, void* item)
{
    return SeqList_Insert(stack, item, SeqList_Length(stack));
}

void* SeqStack_Pop(SeqStack* stack)
{
    return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

void* SeqStack_Top(SeqStack* stack)
{
    return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

int SeqStack_Size(SeqStack* stack)
{
    return SeqList_Length(stack);
}

int SeqStack_Capacity(SeqStack* stack)
{
    return SeqList_Capacity(stack);
}
