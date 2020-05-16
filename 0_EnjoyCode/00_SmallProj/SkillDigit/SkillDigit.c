/*
******************************************************************************************************* 
* Filename     : SkillDigit.c
* Author       : Peterson
* Created      : 2014/03/02
* Description  : �������֣���1,2,...,19,20��20�������ų�һ�ţ�ʹ�����ڵ���������֮��Ϊһ����������
*				��β������֮��ҲΪһ����������̴�ӡ�����е��ŷ���
******************************************************************************************************** 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int arrayA[20];//����ǰ������
int arrayB[20];//������ɺ������

//1��20����������ý������Ϊ������
int arrPrime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int isPrime(int n)
{
	int i, ret = 0;

	for (i = 0; i < 12; i++)
	{
		if (n == arrPrime[i])
		{
			ret = 1;
		}
	}

	return ret;
}

//���㷨�ľ��軹û����
void SkillDigit(int Pos)
{
	int i, j;

	for (i = (arrayB[Pos-1] % 2); i < 20; i += 2)
	{
		if (arrayA[i] != 0)
		{
			if (isPrime(arrayB[Pos-1] + arrayA[i]))
			{
				arrayB[Pos] = arrayA[i];
				arrayA[i] = 0;

				if (Pos == 19)
				{
					if (isPrime(arrayB[0] + arrayB[19]))
					{
						static int count = 0;
						for (j = 0; j < 20; j++)
						{
							printf("%d ", arrayB[j]);
						}
						count++;
						printf("   %d\n", count);
						getch();
					}
				}
				else
					SkillDigit(Pos + 1);
			}
			arrayA[i] = i + 1;
		}
	}
}

void main()
{
	int i;

	for (i = 0; i < 20; i++)
	{
		arrayA[i] = i + 1;
	}
	
	for (i = 0; i < 20; i++)
	{
		arrayB[0] = i + 1;
		arrayA[i] = 0;

		SkillDigit(1);
		arrayA[i] = i + 1;
	}
}




















