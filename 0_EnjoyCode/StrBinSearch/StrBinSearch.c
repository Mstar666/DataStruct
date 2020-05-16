/*
******************************************************************************************************* 
* Filename     : StrBinSearch.c
* Author       : Peterson
* Created      : 2013/02/19
* Description  : 折半查找，在一个字符串中查找一个字符，查到返回下标，没查到返回-1
******************************************************************************************************** 
*/ 

#include <stdio.h>
#include <string.h>

int StrBinSearch(const char *pStrSrc, char chFind)
{
	int max, mid, min=0;
	int nFind = -1;
	if ((pStrSrc != NULL) && (chFind != '\0'))
	{
		max = strlen(pStrSrc)-1;
		while(max >= min)
		{
			mid = (min + max)/2;
			if (pStrSrc[mid] == chFind)
			{
				nFind = mid;
				break;
			}
			else if (pStrSrc[mid] > chFind)
			{
				max = mid - 1;
			}
			else if (pStrSrc[mid] < chFind)
			{
				min = mid + 1;
			}
		}
	}
	return nFind;
}

void main()
{
	int isFind;
	char *TestStr = "abcdefghijklmn";

	isFind = StrBinSearch(TestStr, 'n');

	if (isFind == -1)
	{
		printf("No Found!\n");
	}
	else
		printf("Is Find:%d\n", isFind);
}
