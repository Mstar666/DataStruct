/*
******************************************************************************************************* 
* Filename     : CheckGram.c
* Author       : Peterson
* Created      : 2014/03/02
* Description  : C/C++源代码中，检查语法是否匹配, 若不匹配, 则输出不匹配弧所在的列号
*				逐个字符扫描源代码，遇到左扣符就将其压入栈，遇到右扣符就弹出栈顶元素
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
				printf("第%d个字符：%c不匹配\n", i,code[i]);
				break;
			}
		}
		i++;
	}
	
	if ((LinkStack_Size(stack) == 0) && (code[i] == '\0'))
	{
		printf("语法检查通过!\n");
		ret = 1;
	}
	else
	{
		printf("有语法错误!\n");
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
