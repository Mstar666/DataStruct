/*
******************************************************************************************************* 
* Filename     : CircleList.h
* Author       : Peterson
* Created      : 2013/12/30
* Description  : ѭ������ͷ�ļ������������������١���ա���ȡ���ȡ���ȡposλ�ý�㡢����
				ɾ��posλ�ý�㡢�����ȡ��ǰλ�á�ǰһ������һ����㡢ɾ��ָ�����Ⱥ���
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
