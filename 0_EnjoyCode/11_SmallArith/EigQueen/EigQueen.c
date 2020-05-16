/*
******************************************************************************************************* 
* Filename     : EigQueen.c
* Author       : Peterson
* Created      : 2014/03/02
* Description  : ���Ǿ���İѻʺ����⣬���������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϣ����ж����ְڷ���
* ���õݹ�ӻ��ݷ���ȷ��һ��λ��ֻҪ�ж�ˮƽ����ֱ��б�����������ʺ󼴿ɣ�������������Ѱ
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
//�ֱ��ʾб\��ˮƽ��б/��ƫ����
static Pos pos[] = {{-1, -1}, {-1, 0}, {-1, 1}};

//��ʼ��8*8������'#'���߽�
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

//��ӡ����
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

//����λ���Ƿ�ɷ�
int check(int i, int j)
{
    int ret = 1;
    int p = 0;
    
    for(p=0; p<3; p++)//�ֱ��ж������������������ʺ�
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

//Ѱ�ҵݹ麯���������������ǲ����±곬���߽�
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
            if(check(i, j))//�жϸ�λ���ܷ��
            {
                board[i][j] = '*';
                
                find(i+1);//����Ѱ����һ��λ��
                
                board[i][j] = '|';//�ݹ鷵�������λ��or����
            }
        }
    }
}

void main(void)
{
    init();
    find(1);
}

