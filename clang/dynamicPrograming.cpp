#include<bits/stdc++.h>

// q1: how many ways to compose N from subset a.specially,different positions are different ways.eg.n=4,1+3,3+1 are 2ways.
int q1(int a[],int n)
{
    int D[n+1];
    D[1] = 1;D[2] = 1;D[3] = 2;D[4] = 4;
    for(int i=5;i<=n;i++)
    {
        D[i] = D[i-1]+D[i-3]+D[i-4];
    }
    printf("%d",D[n]);
    return D[n];
} 
// q2:Is there a subset in the setA that sums to get K?(subset means non-repetitive)
int q2(int a[],int n,int k)
{
    int D[n+1][k+1];int i,j;
    for(j=0;j<=k;j++)
    {
        D[0][j] = 0;
    }
    for(i=0;i<=n;i++)
    {
        D[i][0] = 1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(a[i-1]>j)
            {
                D[i][j] = D[i-1][j];
            }
            else{
                D[i][j] = D[i-1][j] || D[i-1][j-a[i-1]];
            }
        }
    }
    printf("%d",D[n][k]);
    return D[n][k];
}

int q2_2(int a[],int n,int k)
{
    int i,j;
    int b[n][k+1];
    b[0][0] = 1;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=k;j++){b[i][j]=0;}
        for(j=0;j<=k;j++)
        {
            if(a[i]==j)
            {
                b[i][j]=1;
            }
            if(i>0){
                if(b[i-1][j]) {b[i][j]=1;}
                if(j>=a[i])
                {
                    if(b[i-1][j-a[i]]) {b[i][j]=1;}
                }
            }
        }
    }
    printf("%d",b[n-1][k]);
    return b[n-1][k];
}

int q3(int a[][2],int n,int m)
{
    // a[x][0] = weights;a[x][1] = values;
    int D[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            D[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1][0]>j)
            {
                D[i][j] = D[i-1][j];
            }
            else{
            D[i][j] = std::max(D[i-1][j],a[i-1][1]+D[i-1][j-a[i-1][0]]);
            }
        }
    }
    printf("%d",D[n][m]);
    return D[n][m];
}

int sum(int a[],int i,int j)
{
    int ret = 0;
    for(i;i<=j;i++)
    {
        ret += a[i];
    }
    return ret;
}

int editDistance(int s1[],int s2[],int n,int m)
{
    int D[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            D[i][j] = 0;
            D[0][j] = j;
            D[i][0] = i;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
            {
                D[i][j] = D[i-1][j-1];
            }
            else
            {
                int min = INT_MAX;
                min = std::min(D[i-1][j],min);//delete
                min = std::min(D[i][j-1],min);//insert
                min = std::min(D[i-1][j-1],min);//replace
                D[i][j] = 1+min;
            }
        }
    }
    printf("%d\n",D[n][m]);
    return D[n][m];
}

int lcs_n3(int a[],int n)
{
    int ret = std::max(a[0],0);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int tmp = sum(a,i,j);
            if(tmp>ret)
            {
                ret = tmp;
            }
        }
    }
    return ret;
}
int lcs_n2(int a[],int n)
{
    int ret = std::max(a[0],0);
    for(int i=0;i<n;i++)
    {
        int tmp = 0;
        for(int j=i;j<n;j++)
        {
            tmp += a[j];
            if(tmp>ret)
            {
                ret = tmp;
            }
        }
    }
    return ret;
}
int lcs_dp(int a[],int n)
{
    int ret = 0;
    int d = a[0];
    for(int i=1;i<n;i++)
    {
        d = std::max(a[i],d+a[i]);
        ret = std::max(d,ret);
    }
    printf("%d",ret);
    return ret;
}

int main()
{
    // int a[3] = {1,3,4};
    // q1(a,10);
    // int b[3] = {3,2,4};
    // q2_2(b,3,5);
    // int n = 4,m=8;
    // int a[4][2] = {
    //     {2,3},
    //     {3,4},
    //     {4,5},
    //     {5,6}
    // };
    // q3(a,n,m);
    // int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
    // lcs_dp(a,9);

    int s1[8] = {'s','a','t','u','r','d','a','y'};
    int s2[6] = {'s','u','n','d','a','y'};
    editDistance(s2,s1,6,8);
    
}