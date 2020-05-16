/*
******************************************************************************************************* 
* Filename     : LinkQueue.c
* Author       : Peterson
* Created      : 2013/02/21
* Description  : 队列C文件，采用复用链式表代码实现
******************************************************************************************************** 
*/ 
#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"
#include "LinkQueue.h"

typedef struct _tag_LinkQueueNode
{
	LinkListNode header;
	void *item;
}TLinkQueueNode;

LinkQueue *LinkQueue_Create(void)//O(1)
{
	return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue *queue)//O(n)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue *queue)//O(n)
{
	while(LinkQueue_Lenght(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
}

int LinkQueue_Append(LinkQueue *queue, void *item)//O(n)
{
	TLinkQueueNode *node = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));
	int ret = (item != NULL) && (node != NULL);
	
	if (ret)
	{
		node->item = item;
		
		ret = LinkList_Insert(queue, (LinkListNode*)node, LinkList_Length(queue));
	}
	
	if (!ret)
	{
		free(node);
	}
	
	return ret;
}

void *LinkQueue_Retrieve(LinkQueue *queue)//O(1)
{
	TLinkQueueNode *node = (TLinkQueueNode*)LinkList_Delete(queue, 0);
	void *ret = NULL;
	
	if (node != NULL)
	{
		ret = node->item;
	
		free(node);
	}
	
	return ret;
}

void *LinkQueue_Header(LinkQueue *queue)//O(1)
{
	TLinkQueueNode *node = (TLinkQueueNode*)LinkList_Get(queue, 0);
	void *ret = NULL;

	if (node != NULL)
	{
		ret = node->item;
	}
	
	return ret;
}

int LinkQueue_Lenght(LinkQueue *queue)//O(1)
{
	return LinkList_Length(queue);
}
