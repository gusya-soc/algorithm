#include<bits/stdc++.h>

#define R 100 //random range
#define arraySize 10 // array size




int* creatRandomArray(int n);
int* bubble();
int* select();
int* insert_shift();
int* insert_swap();
void swap(int* a,int* b);
void show();
void checker();

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
        printf("%d,",a[i]);
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

    int* c = creatRandomArray(arraySize);
    insert_swap(c,arraySize);
    show(c);
    int* d = creatRandomArray(arraySize);
    insert_shift(d,arraySize);
    show(d);
    return 0;
}