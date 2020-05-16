/*
******************************************************************************************************* 
* Filename     : EigQueen.c
* Author       : Peterson
* Created      : 2014/03/02
* Description  : 这是经典的把皇后问题，任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法。
* 采用递归加回溯法，确定一个位置只要判断水平、垂直、斜方向无其它皇后即可，如果有则回退再寻
******************************************************************************************************** 
*/ 
#include <stdio.h>

#define N 8

typedef struct _tag_Pos
{
    int ios;
    int jos;
} Pos;

static int count = 0;
static char board[N+2][N+2];
//分别表示斜\、水平、斜/的偏移量
static Pos pos[] = {{-1, -1}, {-1, 0}, {-1, 1}};

//初始化8*8方格，用'#'做边界
void init()
{
    int i = 0;
    int j = 0;
    
    for(i=0; i<N+2; i++)
    {
        board[0][i] = '#';
        board[N+1][i] = '#';
        board[i][0] = '#';
        board[i][N+1] = '#';
    }
    
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            board[i][j] = '|';
        }
    }
}

//打印方格
void display()
{
    int i = 0;
    int j = 1;
    
    for(i=0; i<N+2; i++)
    {
        for(j=0; j<N+2; j++)
        {
            printf("%c", board[i][j]);
        }
        
        printf("\n");
    }
}

//检测该位置是否可放
int check(int i, int j)
{
    int ret = 1;
    int p = 0;
    
    for(p=0; p<3; p++)//分别判断三个方向有无其它皇后
    {
        int ni = i;
        int nj = j;
        
        while(ret && (board[ni][nj] != '#'))
        {
            ni = ni + pos[p].ios;
            nj = nj + pos[p].jos;
            
            ret = ret && (board[ni][nj] != '*');
        }
    }
    
    return ret;
}

//寻找递归函数，结束的条件是查找下标超出边界
void find(int i)
{
    int j = 0;
    
    if( i > N )
    {
        count++;
        
        printf("Solution: %d\n", count);
        
        display();
        
     //   getchar();
    }
    else
    {
        for(j=1; j<=N; j++)
        {
            if(check(i, j))//判断该位置能否放
            {
                board[i][j] = '*';
                
                find(i+1);//接着寻找下一个位置
                
                board[i][j] = '|';//递归返回则清空位置or回溯
            }
        }
    }
}

void main(void)
{
    init();
    find(1);
}

