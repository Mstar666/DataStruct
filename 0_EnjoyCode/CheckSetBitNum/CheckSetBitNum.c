/*
******************************************************************************************************* 
* Filename     : CheckSetBitNum.c
* Author       : Peterson
* Created      : 2013/02/18
* Description  : 计算一个字节里（byte）里面有多少bit被置1 
******************************************************************************************************** 
*/ 
#include <stdio.h>

unsigned int CheckSetBitNum(char log)
{
	int ret = 0;
	while(log)
	{
 		ret++;
 		log &= (log-1);//每一次把最右边的一个1去掉
 
// 		if (log & 0x01)
// 		{
// 			log = log >> 1;
// 			ret++;
// 		}
// 		else
// 			log = log >> 1;
	}
	return ret;
}

void main()
{
	char TestNum = '0';

	printf("%c中有%d个位被置1\n", TestNum, CheckSetBitNum(TestNum));
}