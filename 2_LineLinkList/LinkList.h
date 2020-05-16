/*
******************************************************************************************************* 
* Filename     : LinkList.h
* Author       : Peterson
* Created      : 2013/01/06
* Description  : ������ͷ�ļ�������������Ĵ��������١���ա����ȡ�(���롢��á�ɾ��)posλ�õĽ��Ⱥ���
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
