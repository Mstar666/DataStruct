/*
******************************************************************************************************* 
* Filename     : LinkQueue.h
* Author       : Peterson
* Created      : 2013/02/21
* Description  : 队列头文件，采用复用链式表代码实现
******************************************************************************************************** 
*/ 
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

typedef void LinkQueue;

LinkQueue *LinkQueue_Create(void);

void LinkQueue_Destroy(LinkQueue *queue);

void LinkQueue_Clear(LinkQueue *queue);

int LinkQueue_Append(LinkQueue *queue, void *item);

void *LinkQueue_Retrieve(LinkQueue *queue);

void *LinkQueue_Header(LinkQueue *queue);

int LinkQueue_Lenght(LinkQueue *queue);

int LinkQueue_Capacity(LinkQueue *queue);

#endif

