/*
******************************************************************************************************* 
* Filename     : CircleList.h
* Author       : Peterson
* Created      : 2013/12/28
* Description  : 循环链表头文件，声明表的创建、销毁、清空、长度、(插入、获得、删除)pos位置的结点，
*				利用游标快速方便的获得当前结点、下一结点、删除指定结点等函数
******************************************************************************************************** 
*/ 
#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void CircleList;

typedef struct _tag_CircleListNode
{
    struct _tag_CircleListNode *next;
}CircleListNode;

CircleList* CircleList_Create();

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

CircleListNode* CircleList_Reset(CircleList* list);

CircleListNode* CircleList_Current(CircleList* list);

CircleListNode* CircleList_Next(CircleList* list);

#endif
