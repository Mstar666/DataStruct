/*
******************************************************************************************************* 
* Filename     : CircleList.h
* Author       : Peterson
* Created      : 2013/12/30
* Description  : 循环链表头文件，声明链表创建、销毁、清空、获取长度、获取pos位置结点、插入
				删除pos位置结点、方便获取当前位置、前一个、下一个结点、删除指定结点等函数
******************************************************************************************************** 
*/ 
#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

typedef void DLinkList;

typedef struct _tag_DLinkListNode
{
    struct _tag_DLinkListNode* next;
    struct _tag_DLinkListNode* pre;
}DLinkListNode;

DLinkList* DLinkList_Create();

void DLinkList_Destroy(DLinkList* list);

void DLinkList_Clear(DLinkList* list);

int DLinkList_Length(DLinkList* list);

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);

DLinkListNode* DLinkList_Reset(DLinkList* list);

DLinkListNode* DLinkList_Current(DLinkList* list);

DLinkListNode* DLinkList_Next(DLinkList* list);

DLinkListNode* DLinkList_Pre(DLinkList* list);

#endif
