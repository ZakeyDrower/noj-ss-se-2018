#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long odd_len(long a)    
{
    long i,num,t,c;

    i=a;
    num=a;
    t=0;
    while(i>0)
    {
        c=i%10;
        i=i/10;
        if(t>0)
            num=num*10+c;
        t++;
    }
    if((c==1)||(c==3)||(c=7)||(c==9))
        return num;
    else
        return 0;
}

int judge(long a)
{
    long i;
    int flag;

    flag=1;

    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag)
        return 1;
    else
        return 0;
}

int main()
{
    int a,b,p;
    long i;
    scanf("%d%d",&a,&b);

    if(a<100)
    {
        if(a<=5)
        {
            if(b>=11)
            {
                printf("5\n");
                printf("7\n");
                printf("11\n");
            }
            else if(b>=7)
            {
                printf("5\n");
                printf("7\n");
            }
            else if(b>=5)
            {
                printf("5\n");
            }
        }
        else if(a<=7)
        {
                if(b>=11)
                {
                    printf("7\n");
                    printf("11\n");
                }

            else if(b>=7)
            {
                printf("7\n");
            }
        }
        else if(a<=11)
        {
            if(b>=11)
                printf("11\n");
        }
    }
    for(i=10;i<9999;i++)
    {
        p=odd_len(i);

        if(p>=a)
        {
            if(p>b)
                break;
            else
            {
                if(judge(p))
                {
                   printf("%d\n",p);
                }
            }
        }
    }
    return 0;
}