#include<bits/stdc++.h>

#define R 100//random range
#define arraySize 100 // array size




int* creatRandomArray(int n);
int* bubble();
int* select();
int* insert_shift();
int* insert_swap();
void swap(int* a,int* b);
void show();
void checker();
void merge_merge(int a[],int s,int m,int e);
void heap_up(int a[],int idx);
void heap_down(int a[],int idx);


void swap(int*a ,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void checker(int a[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        if(a[i]>a[i+1])
        {
            printf("sorting check failed\n");
            return;
        }
    }
    printf("sorting check pass\n");
}

int* bubble(int a[],int size)
{
    int count = 0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            count++;
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
    printf("loops:%d\n",count);// (n^2-n)/2;O(n^2)
    return a;
}

int* select(int a[],int size)
{
    int count = 0;
    for(int i=0;i<size-1;i++)
    {
        int min = INT_MAX;
        int index;
        for(int j=i;j<size;j++)
        {
            count++;
            if(min>a[j])
            {
                min = a[j];
                index = j;
            }
        }
        swap(&a[i],&a[index]);
    }
    printf("loops:%d\n",count);//(n-1)(n-4);O(n^2)
    return a;
}

int* insert_shift(int a[],int size)
{
    int count =  0;
    for(int i=1;i<size;i++)
    {
        if(a[i-1]>a[i])
        {
            int tmp = a[i];
            int j = i;
            for(j;j>0&&a[j-1]>tmp;j--)
            {
                count++;
                a[j] = a[j-1];
            }
            a[j] = tmp;
        }
    }
    printf("loops:%d\n",count);
    return a;
}
int* insert_swap(int a[],int size)
{
    int count = 0;
    for(int i=1;i<size;i++)
    {
        for(int j=i;j>0&&(a[j-1]>a[j]);j--)
        {
            count++;
            swap(&a[j],&a[j-1]);
        }
    }
    printf("loops:%d\n",count);
    return a;
}

void quick(int a[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    
    int pos;
    int piv = a[s];
    int i = s;int j = e;


    // get the true position
    while(i<j)
    {
        while(i<j && a[j]>=piv)
        {
            j--;
        }
        a[i] = a[j];
        while(i<j && a[i]<=piv)
        {
            i++;
        }
        a[j]=a[i];
    }
    a[i]=piv;
    pos = i;


    quick(a,s,pos-1);
    quick(a,pos+1,e);
}

void merge_divide(int a[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid = (s+e)/2;
    merge_divide(a,s,mid);
    merge_divide(a,mid+1,e);
    merge_merge(a,s,mid,e);

}
void merge_merge(int a[],int s,int m,int e)
{
    int i = s;
    int j = m+1;
    int index = 0;
    int tmp[e+1];

    //有序数组合并
    while(i<=m && j<=e)
    {
        if(a[i]<a[j])
        {
            tmp[index++] = a[i++];
        }
        else
        {
            tmp[index++] = a[j++];
        }
    }
    while(i<=m)
    {
        tmp[index++] = a[i++];
    }
    while(j<=e)
    {
        tmp[index++] = a[j++];
    }


    // 复制回原数组
    index = 0;
    while(s<=e)
    {
        a[s++] = tmp[index++];
    }
}

void heap(int a[],int size)
{
    for(int i = 1;i<size;i++)
    {
        heap_up(a,i);
    }
    for(int i=size-1;i>=1;i--)
    {
        heap_down(a,i);
    }
}
void heap_up(int a[],int idx)
{
    int tmp = a[idx];
    int i = idx;
    for(i;i>=1&&tmp>a[(i-1)/2];i = (i-1)/2)
    {
        a[i] = a[(i-1)/2];
    }
    a[i] = tmp;
}
void heap_down(int a[],int idx)
{
    swap(&a[0],&a[idx]);
    // int tmp = a[0];
    int node = 0;
    int child = 1;
    while(child<idx)
    {
        if(child+1<idx && a[child+1]>a[child])
        {
            child = child+1;
        }
        if(a[node]<a[child])
        {
            swap(&a[node],&a[child]);
        }
        node = child;
        child = 2*child+1;
    }
}

int* creatRandomArray(int n)
{
    int* re = new int[n];
    for(int i=0;i<n;i++)
    {
        re[i] = rand()%R;
    }
    return re;
}
void show(int a[])
{
    for(int i=0;i<arraySize;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(0));
    // int* a =creatRandomArray(arraySize);
    // bubble(a,arraySize);
    // show(a);
    // checker(a,arraySize);
    // int* b =creatRandomArray(arraySize);
    // select(b,arraySize);
    // show(b);
    // checker(b,arraySize);

    // int* c = creatRandomArray(arraySize);
    // insert_swap(c,arraySize);
    // show(c);
    // int* d = creatRandomArray(arraySize);
    // insert_shift(d,arraySize);
    // show(d);
    // quick(d,0,arraySize-1);
    // show(d);
    // checker(d,arraySize);


    // int* e = creatRandomArray(arraySize);
    // show(e);
    // merge_divide(e,0,arraySize-1);
    // show(e);
    // checker(e,arraySize);

    // int t[8] = {0,3,6,4,2,5,1,7};
    // heap_up(t,7);
    // show(t);
    // for(int i=0;i<8;i++)
    // {
    //     heap_up(t,i);
    // }
    // show(t);
    int* f = creatRandomArray(arraySize);
    show(f);
    heap(f,arraySize);
    show(f);
    checker(f,arraySize);
    return 0;
}