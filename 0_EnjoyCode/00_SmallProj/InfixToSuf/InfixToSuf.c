/*
******************************************************************************************************* 
* Filename     : InfixToSuf.c
* Author       : Peterson
* Created      : 2013/01/10
* Description  : ��׺���ʽת��׺���ʽ���㷨���裺 ������ͨ�ַ�ʱ���ԣ����������ʱѹ��ջ��
*				�������ҿۺ�ʱ��ջ�е���ջ�����ţ�Ȼ�����ƥ�䣬ʧ��ֹͣ���ɹ��������
******************************************************************************************************** 
*/ 
#include <stdio.h>
#include "LinkStack.h"

int isNumber(char c)
{
	return (('0' <= c) && (c <= '9'));
}

int isOperator(char c)
{
	return ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
}

int isLeft(char c)
{
	return (c == '(');
}

int isRight(char c)
{
	return (c == ')');
}

int Priority(char c)
{
	int ret = 0;

	if ((c == '+') || (c == '-'))
		ret = 1;

	if ((c == '/') || (c == '*'))
		ret = 2;

	return ret;
}

void output(char c)
{
	printf("%c", c);
}

void InfixToSuf(const char* exp)
{
	LinkStack *stack = LinkStack_Create();

	while(*exp != '\0')
	{
		if (isNumber(*exp))
		{
			output(*exp);
		}
		else if (isOperator(*exp))
		{
			while (Priority(*exp) <= Priority((char)LinkStack_Top(stack)))
			{
				char c = '\0';

				c = (char)LinkStack_Pop(stack);
				output(c);
			}
			LinkStack_Push(stack, (void*)(*exp));
		}
		else if (isLeft(*exp))
		{
			LinkStack_Push(stack, (void*)(*exp));
		}
		else if (isRight(*exp))
		{
			while(!isLeft((char)LinkStack_Top(stack)))
			{
				output((char)LinkStack_Pop(stack));
			}
			LinkStack_Pop(stack);
		}
		else 
		{
			printf("Invalid exp!\n");
			break;
		}
		exp++;
	}

	while ((*exp == '\0') && (LinkStack_Size(stack) != 0))
	{
		output((char)LinkStack_Pop(stack));
	}

	LinkStack_Destroy(stack);
}

int main()
{
    InfixToSuf("9+(3-1)*5+8/2");

    printf("\n");

    return 0;
}
