/*
******************************************************************************************************* 
* Filename     : SearchLenStr.c
* Author       : Peterson
* Created      : 2014/02/26
* Description  : ��һ���ַ������ҵ����ܵ�������ַ������Ҹ��ַ�������ͬһ�ַ���ɵġ�
******************************************************************************************************** 
*/ 

#include <stdio.h>
#include <string.h>

char* SearchLenStr(const char *cpSource, char ch)
{
	char *cpTemp = NULL, *cpDest = NULL;
	int iTemp, iCount=0;
	while(*cpSource)
	{
		if(*cpSource == ch)
		{
			iTemp = 0;
			cpTemp = cpSource;
			while(*cpSource == ch) 
			{
				iTemp++;
				cpSource++;
			}

			if(iTemp > iCount) 
			{
				iCount = iTemp;
				cpDest = cpTemp;
			}

			if(*cpSource == '\0') 
				break;
		}
		cpSource++;
	}

	return cpDest;
}


void main()
{
	char Test[] = "ajjjjjbddjjgertyjtutjjjdsfsjjfdddd";

	printf("%s\n", SearchLenStr(Test, 'j'));

}