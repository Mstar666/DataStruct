/*
******************************************************************************************************* 
* Filename     : main.c
* Author       : Peterson
* Created      : 2013/02/17
* Description  : 编写一个函数，作用是把一个char组成的字符串循环右移n位(steps)	
******************************************************************************************************** 
*/ 
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void LoopMove(char *pStr, int steps)
{
	int n=0;
	if ((pStr != NULL) && (steps < strlen(pStr)))
	{
		char *pBak = malloc(sizeof(char)*strlen(pStr));
		n = strlen(pStr) - steps;
		strcpy(pBak, pStr+n);
		strcpy(pBak+steps, pStr);
		*(pBak + strlen(pStr)) = '\0';
		strcpy(pStr, pBak);
	}
}

int main()
{
	char TestStr[] = "abcdefghijklmnop";

	printf("Test PreStr:%s\n", TestStr);
	LoopMove(TestStr, 5);
	printf("LoopMove String:%s\n", TestStr);

	return 0;
}