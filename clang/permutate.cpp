#include<bits/stdc++.h>
int isvisited[3];
char seq[3];

void swap(char*a ,char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void permutate_r(char a[],int c,int size)
{
    if(c==size)
    {
        printf("%s\n",a);
        return;
    }

    for (int i = c; i < size; i++)
    {
        swap(&a[i],&a[c]);
        permutate_r(a,c+1,size);
        swap(&a[i],&a[c]);
    }
    
}

void permutate_r2(char a[],int c,int size)
{
    if(c==size)
    {
        printf("%s\n",seq);
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (!isvisited[i])
        {
            isvisited[i] = 1;
            seq[c] = a[i];
            permutate_r2(a,c+1,size);
            isvisited[i] = 0;

        }
        
    }
    
}

int main()
{
    char a[3] = {'a','b','c'};
    permutate_r2(a,0,3);

}