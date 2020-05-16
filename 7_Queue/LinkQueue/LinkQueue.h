/*
******************************************************************************************************* 
* Filename     : LinkQueue.h
* Author       : Peterson
* Created      : 2013/02/21
* Description  : ����ͷ�ļ������ø�����ʽ�����ʵ��
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

