#include <stdio.h>
#include <string.h>
#include <malloc.h>

void ReverseStr(char *str)
{
	int i = 0, j;
	char temp;
	if (str != NULL)
	{
		int nlen = strlen(str)-1;
		for (j = nlen; j > i; j--)
		{
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			i++;
		}
	}
}

void main()
{
	char Test[] = "abcdefgh";

	printf("%s\n", Test);

	ReverseStr(Test);

	printf("%s\n", Test);

}
