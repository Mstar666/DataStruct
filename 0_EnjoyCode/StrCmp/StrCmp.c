/*
******************************************************************************************************* 
* Filename     : LinkList.c
* Author       : Peterson
* Created      : 2013/02/17
* Description  : 输入两个字符串，比较这两个字符串的大小，0：相等；1：pStr>pDeStr；-1：pStr<pDeStr
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
		printf("%s等于%s\n", TestStr1, TestStr2);
	else if (1 == ret)
		printf("%s大于%s\n", TestStr1, TestStr2);
	else if (-1 == ret)
		printf("%s小于%s\n", TestStr1, TestStr2);
	
	return 0;
}