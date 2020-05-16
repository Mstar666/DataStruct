#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
    SeqList* list = SeqList_Create(10);
    int *pv = NULL;
	int m = 0;

    int i = 0;
    int j = 1;
    int k = 2;
    int x = 3;
    int y = 4;
    int z = 5;
    
    SeqList_Insert(list, &i, 0);
    SeqList_Insert(list, &j, 0);
    SeqList_Insert(list, &k, 0);
    SeqList_Insert(list, &x, 0);
    SeqList_Insert(list, &y, 0);
    SeqList_Insert(list, &z, 0);
    
    SeqList_Delete(list, SeqList_Length(list)-1);

    printf("Capatity = %d\tLength = %d\n", SeqList_Capacity(list), SeqList_Length(list));

	for (m = 0; m < SeqList_Length(list); m++)
	{
		pv = (int *)SeqList_Get(list, m);
		printf("%x\n", *pv);
	}

    SeqList_Destroy(list);
    
    return 0;
}
