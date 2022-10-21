#include <stdio.h>

void f(int m);

int main()
{
    f(7);
    return 0;
}

void f(int m)
{
    for(int i=0;i<=100;i++)
    {
        if(i%m==0)
        {
            printf("%d ",i);
        }
    }
}