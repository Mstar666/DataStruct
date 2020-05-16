/*
******************************************************************************************************* 
* Filename     : StrSort.c
* Author       : Peterson
* Created      : 2013/02/19
* Description  : 字符串从大到小排序，并将输入指针返回，该算法减少了数据交换的次数
******************************************************************************************************** 
*/ 

#include <stdio.h>
#include <string.h>

char *StrSort(char *pStrSrc)
{
	int i, j, imax, temp;

	if (pStrSrc != NULL)
	{
		int nLen = strlen(pStrSrc);
		for(i = 0; i < nLen-1; i++)
		{
			for (imax = i, j = i+1; j < nLen; j++)
			{
				if (pStrSrc[imax] < pStrSrc[j])
				{
					imax = j;//每一次循环找到最大数的下标
				}
			}
			if (i != imax)
			{
				temp = pStrSrc[i];
				pStrSrc[i] = pStrSrc[imax];
				pStrSrc[imax] = temp;
			}
		}
	}
	return pStrSrc;
}

void main()
{
	char TestStr[] = "abcdefghijklmnopqrstuvwxyz";

	printf("排序前：%s\n", TestStr);

	printf("排序后：%s\n", StrSort(TestStr));
}