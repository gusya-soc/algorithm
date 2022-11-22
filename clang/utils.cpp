#include<bits/stdc++.h>

int* creatRandomArray(int n,int R)
{
    int* re = new int[n];
    for(int i=0;i<n;i++)
    {
        re[i] = rand()%R;
    }
    return re;
}