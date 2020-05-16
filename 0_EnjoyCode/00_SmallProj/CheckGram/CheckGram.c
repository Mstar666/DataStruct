/*
******************************************************************************************************* 
* Filename     : CheckGram.c
* Author       : Peterson
* Created      : 2014/03/02
* Description  : C/C++Դ�����У�����﷨�Ƿ�ƥ��, ����ƥ��, �������ƥ�仡���ڵ��к�
*				����ַ�ɨ��Դ���룬������۷��ͽ���ѹ��ջ�������ҿ۷��͵���ջ��Ԫ��
******************************************************************************************************** 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

int isLeft(char c)
{
	int ret = 0;

	switch(c)
	{
		case '{':
		case '[':
		case '(':
		case '<':
		case '\"':
		case '\'':
			ret = 1;break;
		default:
			ret = 0;break;
	}

	return ret;
}

int isRight(char c)
{
	int ret = 0;
	
	switch(c)
	{
		case '}':
		case ']':
		case ')':
		case '>':
		case '\"':
		case '\'':
			ret = 1;break;
		default:
			ret = 0;break;
	}
	
	return ret;
}

int match(char left, char right)
{
	int ret = 0;
	
	switch(left)
	{
		case '{':
			ret = ('}' == right);break;
		case '[':
			ret = (']' == right);break;
		case '(':
			ret = (')' == right);break;
		case '<':
			ret = ('>' == right);break;
		case '\"':
			ret = ('\"' == right);break;
		case '\'':
			ret = ('\'' == right);break;
		default:
			ret = 0;break;
	}
	
	return ret;
}

int CheckGram(const char* code)
{
	LinkStack *stack = LinkStack_Create();
	int i = 0;
	int ret = 0;

	while(code[i] != '\0')
	{
		if (isLeft(code[i]))
		{
			LinkStack_Push(stack, (void*)(code[i]));
		}
		if (isRight(code[i]))
		{
			char leftchar = (char)LinkStack_Pop(stack);

			if ((leftchar == '\0') || !match(leftchar, code[i]))
			{
				ret = 0;
				printf("��%d���ַ���%c��ƥ��\n", i,code[i]);
				break;
			}
		}
		i++;
	}
	
	if ((LinkStack_Size(stack) == 0) && (code[i] == '\0'))
	{
		printf("�﷨���ͨ��!\n");
		ret = 1;
	}
	else
	{
		printf("���﷨����!\n");
		ret = 0;
	}

	LinkStack_Destroy(stack);

	return ret;
}

int main(int argc, char *argv[])
{
 //   const char* code = "#include <stdio.h> int main() { int a[5][5]; int (*p)[4]; p = a[0]; printf(\"%d\\n\", &p[3][3] - &a[3][3]); return 0; }";
    const char* code = " printf() (";

    CheckGram(code);
    
	return 0;
}
