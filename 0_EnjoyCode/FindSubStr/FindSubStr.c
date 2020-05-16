/*
******************************************************************************************************* 
* Filename     : StrFind.c
* Author       : Peterson
* Created      : 2013/02/19
* Description  : 字符串查找，在pStrSrc中从nStartPos下标开始查找pStrSub子字符串
*				返回查找到的子字符串的位置, 负值表示没找到(注:位置为0起始)
******************************************************************************************************** 
*/ 

#include <stdio.h>
#include <windows.h>

int StrFind(const char *pStrSrc, const char *pStrSub, int nStartPos);

int main()
{
	char	pStrA[] = "This is ffstring find function!";
	char	pStrB[] = "find";
	int	nFind;
	
	nFind = StrFind(pStrA, pStrB, 0);
	if (nFind < 0)
		printf("Can't find sub string.\n");
	else
		printf("StrFind : %d\n", nFind);
	
	return 0;
}

int StrFind(const char *pStrSrc, const char *pStrSub, int nStartPos)
{
	int	nFind = -1;
	// 添加你的代码
	int nSub = 0;
	int i;
	
	while(nStartPos != 0)
	{
		if(*pStrSrc != '\0')
			pStrSrc++;
		nStartPos--;
	}
	if(*pStrSub != '\0')
	{
		while(*pStrSrc != '\0')
		{
			while((*pStrSrc != '\0') && (*pStrSrc != *pStrSub)) 
			{
				pStrSrc++;
				nSub++;
			}
			
			i=0;
			
			while(pStrSrc[i] && pStrSub[i] && pStrSrc[i] == pStrSub[i]) 
			{
				i++;
			}	
			
			if (pStrSub[i] == '\0') 
			{
				nFind = 1;
				break; 
			}
			else 
			{
				pStrSrc++;
				nSub++;
			}
			
		}
		
	}	
	return nFind * nSub;
}
