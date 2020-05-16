#include <stdio.h>

void Virlle(int n)
{
	int i = 0, j = 0;

	if ((3 < n) && (n < 20))
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				if ((i == 0) || (i == n-1) || (j == 0) || (j == n-1))
				{
					printf("X");
				}
				else if ((i == 1) || (i == n-2) || (j == 1) || (j == n-2))
				{
					printf("Y");
				}
				else
					printf("%d", i-2);
			}
			printf("\n");
		}
	}
}

void main()
{
	Virlle(13);
}