#include <stdio.h>
#include <limits.h>

void traverse(int a[],int size);
void reverse(int a[],int size);
void board();
void shift_right(int a[],int size);
void insert(int a[],int size,int x);
void insert_2(int a[],int size,int x);
void sort(int a[],int size);
int merge(int a[],int b[],int size_a,int size_b);
void merge_2(int a[],int b[],int size_a,int size_b);

int main()
{
    int a[9] = {1,4,7,2,5,3,8,6,9};
    int b[10] = {1,3,5,7,9};
    int size_a = sizeof(a)/4;
    int size_b = 5;
    // printf("%d\n",size_a);
    // traverse(a,size_a);
    // reverse(a,size_a);
    // shift_right(a,size_a);
    // int x = -5;
    // insert(b,size_b,x);
    // insert_2(b,size_b,x);
    int c[9] = {2,4,6,8,10,11,12,13,16};
    merge_2(b,c,5,9);
}

void board()
{
    printf("\n==========\n");
}

void sort(int a[],int size)
{

}

void traverse(int a[],int size)
{
    printf("traverse:\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    board();
}

void reverse(int a[],int size)
{
    printf("reverse:\n");
    // printf("%d",size);
    int tmp;
    int i = 0;
    int j = size-1;
    while(i<j)
    {
        printf("%d %d\n",a[i],a[j]);
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
        
    }
    traverse(a,size);
    board();
}

void shift_right(int a[],int size)
{
    int last = a[size-1];
    printf("loop shift right:\n");
    for(int i=size-1;i>0;i--)
    {
        a[i] = a[i-1];
    }
    a[0]=last;
    traverse(a,size);
    board();
}

void insert(int a[],int size,int x)
{
    // 不能正确处理头插
    int tmp[size+1];
    int i =0;

    for(i;i<size;i++)
    {
        // 头插补丁
        if(x<a[i])
        {
            tmp[i] = x;
            tmp[i+1] = a[i];
            break;
        }
        if(x>a[i]&&x<a[i+1])
        {
            tmp[i]=a[i];
            tmp[i+1]=x;
            break;
        }
        tmp[i]=a[i];
    }
    printf("%d",i);
    for(int j=i+2;j<size+1;j++)
    {
        tmp[j] = a[j-1];
    }
    traverse(tmp,size+1);
}

void insert_2(int a[],int size,int x)

{
    // more elegant
    // int i = size-1;
    // for(i;i>=0;i--)
    // {
    //     if(a[i]>x){
    //         a[i+1] = a[i];
    //     }else{
    //         break;
    //     }
    // }
    // a[i+1] = x;
    // traverse(a,size+1);

    // the most elegant but have a bug when the x<=0
    int i = size-1;
    // fixed x<=0 bug
    for(i;a[i]>x&&i>=0;i--)
    {
        a[i+1] = a[i];
    }
    printf("%d\n",i);
    a[i+1] = x;
    traverse(a,size+1);
}



int merge(int a[],int b[],int size_a,int size_b)
{    
    printf("===========\nmerge:\n");
    int i = 0;
    int j = 0;
    int k = 0;
    int c[size_a+size_b];
    while(i<size_a&&j<size_b)
    {
        if(a[i]<=b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    if(i==size_a)
    {
        while(j<size_b)
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<size_a)
        {
            c[k] = a[i];
            i++;
            k++;
        }
    }

    traverse(c,size_a+size_b);

    return 0;
}

void merge_2(int a[],int b[],int size_a,int size_b)
{
    // more elegant
    int i=0;
    int j=0;
    int k=0;
    a[size_a]= INT_MAX;
    b[size_b] = INT_MAX;
    int c[size_a+size_b];
    for(k;k<size_a+size_b;k++)
    {
        if(a[i]<b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
    }
    traverse(c,size_a+size_b);
}