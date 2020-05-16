/*
******************************************************************************************************* 
* Filename     : Count.h
* Author       : Peterson
* Created      : 2014/03/02
* Description  : �ɺ�׺���ʽ�õ�������
******************************************************************************************************** 
*/ 
#include <stdio.h>
#include "LinkStack.h"

int isNumber(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int value(char c)
{
	return (c - '0');
}

int express(int left, int right, char op)
{
	int ret = 0;

	if(op == '+')
		ret = left + right;

	if(op == '-')
		ret = left - right;

	if(op == '*')
		ret = left * right;

	if(op == '/')
		ret = left / right;

	return ret;
}

int compute(const char* exp)
{
	LinkStack *stack = LinkStack_Create();
	int ret = 0;

	while (*exp != '\0')
	{
		if (isNumber(*exp))//��������־���ջ
		{
			LinkStack_Push(stack, (void*)*exp);
		}
		else if (isOperator(*exp))//����ǲ������򵯳����Ҳ��������м���
		{
			char rightnum = (char)LinkStack_Pop(stack);
			char leftnum = (char)LinkStack_Pop(stack);

			ret = express(value(leftnum), value(rightnum), *exp); 
			LinkStack_Push(stack, (void*)(ret + '0'));//�ٽ���������ջ
		}
		else
		{
			printf("Invalid express!");
			break;
		}
		exp++;
	}
	if((LinkStack_Size(stack) == 1))//���ջ�б������Ǽ�����
	{
		ret = value((char)LinkStack_Pop(stack));
	}
	else
	{
		printf("Invalid express!");
	}
	
	LinkStack_Destroy(stack);
	return ret;
}	

int main()
{
    printf("9 + (3 - 1) * 5 + 8 / 2 = %d\n", compute("931-5*+82/+"));
    
    return 0;
}
