#include <stdio.h>
#include <stdlib.h>
#define N 10
struct dat
{
    int k;
    struct dat *n;
};
int func1(int n);
void func2(struct dat *p);
void func3(struct dat *p);
void func4(struct dat *p1,struct dat *p2);

int main(void)
{
    struct dat *p =NULL,*np;
    int n = 0;
    while(n<N)
    {
        np = (struct dat *)malloc(sizeof(struct dat));
        np->k = func1(n);
        np->n = p;
        p = np;
        n++;
    }
    func2(p);
}


int func1(int n)
{
    if(n==0||n==1) return n;
    else return func1(n-2)+func1(n-1);
}
void func2(struct dat *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->k);
        p=p->n;
    }
    printf("\n");
}



