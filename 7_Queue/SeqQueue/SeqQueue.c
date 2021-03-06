/*
******************************************************************************************************* 
* Filename     : SeqQueue.c
* Author       : Peterson
* Created      : 2013/02/21
* Description  : 队列C文件，采用复用顺序表代码实现
******************************************************************************************************** 
*/ 
#include "SeqList.h"
#include "SeqQueue.h"

SeqQueue *SeqQueue_Create(int capacity)//O(1)
{
	return SeqList_Create(capacity);
}

void SeqQueue_Destroy(SeqQueue *queue)//O(1)
{
	SeqList_Destroy(queue);
}

void SeqQueue_Clear(SeqQueue *queue)//O(1)
{
	SeqQueue_Clear(queue);
}

int SeqQueue_Append(SeqQueue *queue, void *item)//O(1)
{
	return SeqList_Insert(queue, item, SeqList_Length(queue));
}

void *SeqQueue_Retrieve(SeqQueue *queue)//O(n)
{
	return SeqList_Delete(queue, 0);
}

void *SeqQueue_Header(SeqQueue *queue)//O(1)
{
	return SeqList_Get(queue, 0);
}

int SeqQueue_Lenght(SeqQueue *queue)//O(1)
{
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue *queue)//O(1)
{
	return SeqList_Capacity(queue);
}