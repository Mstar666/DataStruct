/*
******************************************************************************************************* 
* Filename     : CircleList.h
* Author       : Peterson
* Created      : 2013/12/28
* Description  : ѭ������ͷ�ļ���������Ĵ��������١���ա����ȡ�(���롢��á�ɾ��)posλ�õĽ�㣬
*				�����α���ٷ���Ļ�õ�ǰ��㡢��һ��㡢ɾ��ָ�����Ⱥ���
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
