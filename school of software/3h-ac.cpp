/*
传统算法解决八皇后问题
一行一行的填矩阵
*/
#include <stdio.h>
#include <stdlib.h>

int a[8];
int count;

int complace(int col,int sel)   //判断是否可以放棋子
//返回1表示不能放；返回0表示可以放
{
    int flag,i;

    flag=0;

    if(col==0)
        ;

        for(i=0;i<col;i++)
            if(col-i==sel-a[i]||col-i==a[i]-sel||sel==a[i])
                flag=1;
    return flag;
}

void search(int m)
{
    int i,j;

    if(m==8)
    {
        printf("No %d:\n",count);
        count++;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(j==a[i])
                    printf("A");
                else
                    printf(".");
            }
            printf("\n");
        }

    }

    else
    {
        for(i=0;i<8;i++)
        {
            if(complace(m,i)==0)
            {
                a[m]=i;         //a[i]表示皇后在这行的哪一列
                search(m+1);
            }
        }
    }

}
int main()
{
    count=1;
    search(0);

    return 0;
}