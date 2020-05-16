/*
******************************************************************************************************* 
* Filename     : LinkList.c
* Author       : Peterson
* Created      : 2013/02/17
* Description  : ���������ַ������Ƚ��������ַ����Ĵ�С��0����ȣ�1��pStr>pDeStr��-1��pStr<pDeStr
******************************************************************************************************** 
*/ 

#include <stdio.h>

#define  uint unsigned int

int StrCmp(const char *pStr, const char *pDeStr)
{
	int ret = 0;

	while(!(ret = *(uint *)pStr - *(uint *)pDeStr) && *pStr && *pDeStr)
	{
		pStr++;
		pDeStr++;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	
	return ret;
}

int main()
{
	int ret;
	char TestStr1[] = "abcdefgf1";
	char TestStr2[] = "abcdefgf";

	ret = StrCmp(TestStr1, TestStr2);
	
	if (0 == ret)
		printf("%s����%s\n", TestStr1, TestStr2);
	else if (1 == ret)
		printf("%s����%s\n", TestStr1, TestStr2);
	else if (-1 == ret)
		printf("%sС��%s\n", TestStr1, TestStr2);
	
	return 0;
}