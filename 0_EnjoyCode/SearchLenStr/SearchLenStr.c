/*
******************************************************************************************************* 
* Filename     : SearchLenStr.c
* Author       : Peterson
* Created      : 2014/02/26
* Description  : 在一个字符串中找到可能的最长的子字符串，且该字符串是由同一字符组成的。
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