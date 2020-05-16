/*
******************************************************************************************************* 
* Filename     : SeqQueue.h
* Author       : Peterson
* Created      : 2013/02/21
* Description  : ����ͷ�ļ������ø���˳������ʵ��
******************************************************************************************************** 
*/ 
#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_

typedef void SeqQueue;

SeqQueue *SeqQueue_Create(int capacity);

void SeqQueue_Destroy(SeqQueue *queue);

void SeqQueue_Clear(SeqQueue *queue);

int SeqQueue_Append(SeqQueue *queue, void *item);

void *SeqQueue_Retrieve(SeqQueue *queue);

void *SeqQueue_Header(SeqQueue *queue);

int SeqQueue_Lenght(SeqQueue *queue);

int SeqQueue_Capacity(SeqQueue *queue);

#endif

