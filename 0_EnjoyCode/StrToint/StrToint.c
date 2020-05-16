/*
******************************************************************************************************* 
* Filename     : StrToint.c
* Author       : Peterson
* Created      : 2013/02/17
* Description  : ����һ���ַ���������ǰ��Ŀո񣬲������ַ���ת��������
******************************************************************************************************** 
*/ 
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int my_atoi(char *pStr)
{
	int Integer = 0;
	int sign = 1;

	if (pStr != NULL)
	{
		while(*pStr == ' ')
			pStr++;

		if (*pStr == '-')
		{
			sign = -1;
			pStr++;
		}
		else if (*pStr == '+')
		{
			pStr++;
		}

		while(*pStr != '\0')//(*pStr >= '0' && *pStr <= '9')
		{
			Integer = Integer*10 + *pStr - '0';
			pStr++;
		}
		Integer = sign*Integer;
	}
	return Integer;
}

char *my_itoa(int num, char *pStr)
{
	int sign = 1;
	int temp = 0;
	int i = 0;
	char *pTemp = malloc(sizeof(strlen(pStr)));
	char *pBak = pTemp;
	if (pStr != NULL)
	{
		if (num < 0)
		{
			sign = -1;
		}
		while(num)
		{
			temp = num%10;
			*pTemp++ = temp + '0';
			num = num/10;
		}
		if (sign == -1)
		{
			pStr[i++] = '-';
		}

		while(pBak != pTemp)
		{
			pTemp--;
			pStr[i++] = *pTemp;
		}
		pStr[i] = '\0';
	}
	free(pBak);

	return pStr;
}


int main()
{
	char TestStr[] = "abcdefg";//"-0123456789";
	int Testnum = 456;

	printf("%d\n", my_atoi(TestStr));

	printf("%s\n", my_itoa(Testnum, TestStr));
	
	return 0;
}