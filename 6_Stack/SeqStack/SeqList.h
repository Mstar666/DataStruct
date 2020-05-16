/*
******************************************************************************************************* 
* Filename     : LinkStack.h
* Author       : Peterson
* Created      : 2013/01/05
* Description  : ˳���ͷ�ļ����������Ա��Ĵ��������١���ա��õ���������������������posλ��Ԫ�صȺ���
******************************************************************************************************** 
*/ 
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);

void SeqList_Destroy(SeqList* list);

void SeqList_Clear(SeqList* list);

int SeqList_Length(SeqList* list);

int SeqList_Capacity(SeqList* list);

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

SeqListNode* SeqList_Get(SeqList* list, int pos);

SeqListNode* SeqList_Delete(SeqList* list, int pos);

#endif
