#include<stdlib.h>
#include <stdio.h>
struct element 
{
    struct element *link;
    int data;
};

struct element *sp;

void push(int data)
{
    struct element *e;
    e = malloc(sizeof(struct element));
    e->link = sp;
    e->data = data;
    sp = e;
}

void pop()
{
    if(sp==NULL)
    {
        return;
    }
    printf("%d",sp->data);
    sp = sp->link;
}

int main()
{
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    pop();
    pop();
    return 0;
}
