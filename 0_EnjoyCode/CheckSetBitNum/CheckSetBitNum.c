/*
******************************************************************************************************* 
* Filename     : CheckSetBitNum.c
* Author       : Peterson
* Created      : 2013/02/18
* Description  : ����һ���ֽ��byte�������ж���bit����1 
******************************************************************************************************** 
*/ 
#include <stdio.h>

unsigned int CheckSetBitNum(char log)
{
	int ret = 0;
	while(log)
	{
 		ret++;
 		log &= (log-1);//ÿһ�ΰ����ұߵ�һ��1ȥ��
 
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

	printf("%c����%d��λ����1\n", TestNum, CheckSetBitNum(TestNum));
}