/*
******************************************************************************************************* 
* Filename     : Count.h
* Author       : Peterson
* Created      : 2014/03/02
* Description  : 由后缀表达式得到计算结果
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
		if (isNumber(*exp))//如果是数字就入栈
		{
			LinkStack_Push(stack, (void*)*exp);
		}
		else if (isOperator(*exp))//如果是操作符则弹出左右操作数进行计数
		{
			char rightnum = (char)LinkStack_Pop(stack);
			char leftnum = (char)LinkStack_Pop(stack);

			ret = express(value(leftnum), value(rightnum), *exp); 
			LinkStack_Push(stack, (void*)(ret + '0'));//再将计算结果入栈
		}
		else
		{
			printf("Invalid express!");
			break;
		}
		exp++;
	}
	if((LinkStack_Size(stack) == 1))//最后栈中保留的是计算结果
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
