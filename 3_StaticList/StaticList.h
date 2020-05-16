/*
******************************************************************************************************* 
* Filename     : StaticList.h
* Author       : Peterson
* Created      : 2013/12/27
* Description  : 静态链表头文件，声明表的创建、销毁、清空、长度、(插入、获得、删除)pos位置的结点等函数
******************************************************************************************************** 
*/ 
#ifndef _STATICLIST_H_
#define _STATICLIST_H_

typedef void StaticList;
typedef void StaticListNode;

StaticList* StaticList_Create(int capacity);

void StaticList_Destroy(StaticList* list);

void StaticList_Clear(StaticList* list);

int StaticList_Length(StaticList* list);

int StaticList_Capacity(StaticList* list);

int StaticList_Insert(StaticList* list, StaticListNode* node, int pos);

StaticListNode* StaticList_Get(StaticList* list, int pos);

StaticListNode* StaticList_Delete(StaticList* list, int pos);

#endif

