/*
******************************************************************************************************* 
* Filename     : StrFind.c
* Author       : Peterson
* Created      : 2013/02/19
* Description  : �ַ������ң���pStrSrc�д�nStartPos�±꿪ʼ����pStrSub���ַ���
*				���ز��ҵ������ַ�����λ��, ��ֵ��ʾû�ҵ�(ע:λ��Ϊ0��ʼ)
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
	// �����Ĵ���
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
