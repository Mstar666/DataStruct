/*
******************************************************************************************************* 
* Filename     : Plalindrome.c
* Author       : Peterson
* Created      : 2013/02/18
* Description  : ����һ���ַ������ж����Ƿ�Ϊ�����ַ���
******************************************************************************************************** 
*/ 

#include <stdio.h>
#include <string.h>

#define BOOL  int
#define FALSE 0
#define TRUE  1

BOOL strPlalindRome(const char *Buffer, int size)
{
	BOOL ret = FALSE;
	char *front = Buffer;
	char *rear = front + strlen(Buffer) - 1;

	if (front != NULL)
	{
		while(front < rear)
		{
			if (*front != *rear)
				break;
			front++;
			rear--;
		}
		if (front >= rear)
			ret = TRUE;
	}
	return ret;
}

void main()
{
	BOOL bl = 0;
	char * TestStr = "abcdeffedcba";

	bl = strPlalindRome(TestStr, strlen(TestStr));
	if (bl == 0)
	{
		printf("�ַ���%s���ǻ���!\n",TestStr);
	}
	else
		printf("�ַ���%s�ǻ���!\n",TestStr);

}