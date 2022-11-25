#include<bits/stdc++.h>


#define N 10

int fibonacci_r(int n)
{
    // O(2^n)
    
    // if(n<1)
    // {
    //     return 0;
    // }
    // if(n==1)
    // {
    //     return 1;
    // }
    if(n<2)
    {
        return n;
    }
    else
    {
        return fibonacci_r(n-1)+fibonacci_r(n-2);
    }
}

int fibonacci(int n)
{
    // O(n)
    int a=0,b=1,re;
    for(int i=1;i<n;i++)
    {
        re = a+b;
        a = b;
        b = re;
        
    }
    return re;
}

int fibonacci_opt(int n)
{
    // O(n)
    // 2 variables,space optimized.
    int a = 0,b =1;
    for(int i=0;i<n;i++)
    {
        b = b+a;
        a = b-a;
    }
    return a;
}

int fibonacci_array(int n)
{
    // loop but recursion likely.
    int a[n+1];
    a[0] = 0;a[1] = 1;
    for(int i=2;i<=n;i++)
    {
        a[i] = a[i-1]+a[i-2];
    }
    return a[n];
    
}


int main()
{
    printf("%d\n",fibonacci_r(N));
    printf("%d\n",fibonacci_array(N));
}