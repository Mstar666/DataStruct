/*
******************************************************************************************************* 
* Filename     : LinkStack.c
* Author       : Peterson
* Created      : 2013/01/10
* Description  : 链式栈C文件，栈是一种特殊的线性表，只能在表的一端进行操作，采用代码复用，实现高效化
******************************************************************************************************** 
*/ 
#include <stdio.h>
#include <malloc.h>
#include "LinkStack.h"
#include "LinkList.h"

typedef struct _tag_LinkStackNode
{
    LinkListNode header;
    void* item;
} TLinkStackNode;

LinkStack* LinkStack_Create()// O(1)
{
    return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack) // O(1)
{
    LinkStack_Clear(stack);
    LinkList_Destroy(stack);
}

void LinkStack_Clear(LinkStack* stack) // O(n)
{
    while( LinkStack_Size(stack) > 0 )
    {
        LinkStack_Pop(stack);
    }
}

int LinkStack_Push(LinkStack* stack, void* item) // O(n)
{
    TLinkStackNode* node = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
    int ret = (node != NULL) && (item != NULL);
    
    if( ret )
    {
        node->item = item;
        
        ret  = LinkList_Insert(stack, (LinkListNode*)node, 0);
    }
    
    if( !ret )
    {
        free(node);
    }
    
    return ret;
}

void* LinkStack_Pop(LinkStack* stack) // O(1)
{
    TLinkStackNode* node = (TLinkStackNode*)LinkList_Delete(stack, 0);
    void* ret = NULL;
    
    if( node != NULL )
    {
        ret = node->item;
        
        free(node);
    }
    
    return ret;
}

void* LinkStack_Top(LinkStack* stack) // O(1)
{
    TLinkStackNode* node = (TLinkStackNode*)LinkList_Get(stack, 0);
    void* ret = NULL;
    
    if( node != NULL )
    {
        ret = node->item;
    }
    
    return ret;
}

int LinkStack_Size(LinkStack* stack) // O(1)
{
    return LinkList_Length(stack);
}
