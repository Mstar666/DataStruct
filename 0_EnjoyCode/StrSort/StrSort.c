/*
******************************************************************************************************* 
* Filename     : StrSort.c
* Author       : Peterson
* Created      : 2013/02/19
* Description  : �ַ����Ӵ�С���򣬲�������ָ�뷵�أ����㷨���������ݽ����Ĵ���
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
					imax = j;//ÿһ��ѭ���ҵ���������±�
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

	printf("����ǰ��%s\n", TestStr);

	printf("�����%s\n", StrSort(TestStr));
}