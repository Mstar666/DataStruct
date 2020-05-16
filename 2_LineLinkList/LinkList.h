/*
******************************************************************************************************* 
* Filename     : LinkList.h
* Author       : Peterson
* Created      : 2013/01/06
* Description  : 单链表头文件，声明单链表的创建、销毁、清空、长度、(插入、获得、删除)pos位置的结点等函数
******************************************************************************************************** 
*/ 
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef void LinkList;

typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode *next;
}LinkListNode;

LinkList* LinkList_Create();

void LinkList_Destroy(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delete(LinkList* list, int pos);

#endif
