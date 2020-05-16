#include <stdio.h>
#include <stdlib.h>
#include "StaticList.h"
#include <malloc.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct test
{
	int a;
	double b;
	char c[];
}Test;


int main(int argc, char *argv[])
{
    StaticList* list = StaticList_Create(10);
    
    int index = 0;
    
    int i = 0;
    int j = 1;
    int k = 2;
    int x = 3;
    int y = 4;
    int z = 5;

	char a[] = "hello world";
	
	Test *PntTest = (Test*)malloc(sizeof(Test) + strlen(a) + 1);
	


 	PntTest->a = 4;
 	PntTest->b = 3.5;
	strcpy( PntTest + 1, a );

	printf("%d %f %s %d\n",PntTest->a, PntTest->b, PntTest->c, sizeof(const));
	
	

    StaticList_Insert(list, &i, 0);
    StaticList_Insert(list, &j, 0);
    StaticList_Insert(list, &k, 0);
    
    for(index=0; index<StaticList_Length(list); index++)
    {
        int* p = (int*)StaticList_Get(list, index);
        if (p != NULL)
		{
			printf("%d\n", *p);
        }
    }
    return 0;
    printf("\n");
    
    while( StaticList_Length(list) > 0 )
    {
        int* p = (int*)StaticList_Delete(list, 0);
        if (p != NULL)
        {
			printf("%d\n", *p);
        }
    }
    
    printf("\n");
    
    StaticList_Insert(list, &x, 0);
    StaticList_Insert(list, &y, 0);
    StaticList_Insert(list, &z, 0);
    
    printf("Capacity: %d Length: %d\n", StaticList_Capacity(list), StaticList_Length(list));
    
    for(index=0; index<StaticList_Length(list); index++)
    {
        int* p = (int*)StaticList_Get(list, index);
        
        printf("%d\n", *p);
    }
    
    StaticList_Destroy(list);
    
//	return 0;
}
