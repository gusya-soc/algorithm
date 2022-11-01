#include<stdlib.h>
#include<stdio.h>


struct element 
{
    struct element *link;
    int data;
};

typedef struct queue
{
    struct element *front;
    struct element *rear;
}q;