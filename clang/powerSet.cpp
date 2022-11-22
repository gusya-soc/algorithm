#include<bits/stdc++.h>
#include"utils.h"

#define SIZE 5

int flag[SIZE];
int* a  = creatRandomArray(SIZE,SIZE*10);
void powerSet_R(int a[],int c,int size)
{
    if(c==size)
    {
        for(int i=0;i<size;i++)
        {
            if(flag[i]==1)
            {
                printf("%d,",a[i]);
            }
        }
        printf("\n");
        return;
    }

    flag[c] = 1;
    powerSet(a,c+1,size);
    flag[c] = 0;
    powerSet(a,c+1,size);

}

void powerSet_bin(int a[],int size)
{
    // 生成集合个数的二进制排列.eg. {1,2,3},size=3,L={001,010,011...}

    // 遍历该L数组，有1就对应原集合里的元素
}



int main()
{
    powerSet(a,0,SIZE);
    return 0;
}