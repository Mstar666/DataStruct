/*
******************************************************************************************************* 
* Filename     : ReserList.c
* Author       : Peterson
* Created      : 2013/02/17
* Description  : 输入一个链表的头结点，从尾到头反转该链表，并返回反转后链表的头结点
******************************************************************************************************** 
*/ 
//链表结点定义如下：
#include <stdio.h>

typedef struct _LISTNODE{
	int m_nkey;
	struct _LISTNODE *m_pNext;
}ListNode;

ListNode *ReverList(ListNode *pHead)
{
	ListNode *pReserHead = NULL;
	ListNode *pNode = pHead;
	ListNode *pPrev = NULL;

	while(pNode != NULL)
	{
		ListNode *pNext = pNode->m_pNext;
		if (pNext == NULL)
		{
			pReserHead = pNode;
		}
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReserHead;
}

int main(void)
{
	ListNode *List;
	ListNode L1,L2,L3,L4;
	L1.m_pNext = &L2;
	L2.m_pNext = &L3;
	L3.m_pNext = &L4;
	L4.m_pNext = NULL;

	L1.m_nkey = 1;
	L2.m_nkey = 2;
	L3.m_nkey = 3;
	L4.m_nkey = 4;

	List = &L1;
	printf("反转前头结点中值:%d\n", List->m_nkey);

	List = ReverList(&L1);

	printf("反转后头结点中值:%d\n", List->m_nkey);

	return 0;
}