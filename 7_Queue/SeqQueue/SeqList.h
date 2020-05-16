/*
******************************************************************************************************* 
* Filename     : LinkStack.h
* Author       : Peterson
* Created      : 2013/01/05
* Description  : 顺序表头文件，声明线性表的创建、销毁、清空、得到长度与容量、插入与获得pos位置元素等函数
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

