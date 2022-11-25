#include<bits/stdc++.h>

#define N 6

// 数组a：x轴上y的位置上有皇后.a[0] = 2 ==> (0,2)上有皇后

int a[N];
int count = 0;
int check(int x,int y);
int nQueen_r(int x,int n)
{

    if(x==n)
    {
        count++;
        printf("第%d个解：\n",count);
        for (int i = 0; i < N; i++)        //行
        {
            for (int j = 0; j < N; j++)   //列
            {
                if (a[i] != j)
                    printf("x");
                else
                    printf("Q");
            }
            printf("\n");
        }
        printf("\n");
        return 1;
    }
    int res = 0;
    for(int y=0;y<n;y++)
    {
        if(check(x,y))
        {
            a[x]=y;
            res += nQueen_r(x+1,n);
        }
    }
    return res;
}

int nQueen(int n)
{
    return 0;
}

int check(int x,int y)
{
    for(int i=0;i<x;i++)
    {
        if(a[i]==y || abs(i - x) == abs(a[i] - y)){
            return 0;
        }
    }
    return 1;
}

int main()
{

    printf("%d Queens %d ansers",N,nQueen_r(0,N));
    // for (int i = 1; i <= N; i++)        //行
    // {
    //     for (int j = 1; j <= N; j++)   //列
    //     {
    //         if (a[i] != j)
    //             printf("x");
    //         else
    //             printf("Q");
    //     }
    //     printf("\n");
    // }
}