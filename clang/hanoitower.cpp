#include<bits/stdc++.h>

void hanoitower(int n,int a,int b ,int c)
{
    if(n==1)
    {
        printf("%c - %c\n",a+65,c+65);
        
    }else{
    hanoitower(n-1,a,c,b);
    printf("%c - %c\n",a+65,c+65);
    hanoitower(n-1,b,a,c);
    }
}

int main()
{
    hanoitower(5,0,1,2);
}