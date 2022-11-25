#include<bits/stdc++.h>
int a[1024];
int check(int x,int y)
{
    for (int i = 0; i < x; i++)
    {
        if (a[i]==y || a[i] == y-x+i || a[i]==y+x-i)
        {
            return 0;
        }
        
    }
    return 1;
    
}
void printa(int n)
{
    int i;
    if (n>0)
    {
        printf("%d",a[0]);
    }
    for ( i = 1; i < n; i++)
    {
        printf(",%d",a[i]);
    }
    printf("\n");
    
    
}

void nQueen(int n,int x)
{
    int y = 0;
    while(1)
    {
        while (y<n)
        {
            if (check(x,y))
            {
                a[x] = y;
                x = x+1;
                if (x>=n)
                {
                    printa(n);
                    goto backtrack;
                }
                y = 0;
            }
            else{
                y = y + 1;
            }
        }
        
    }
    backtrack:
        x = x -1;
        if (x<0)
        {
            return;
            
        }
        y = a[x]+1;
        
}
int main()
{

    nQueen(5,0);
    // BUG: can not run at N=4
    nQueen(4,0);
}