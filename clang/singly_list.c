#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE* next;
}NODE;


NODE* create_node(int x)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

void traverse(NODE* n)
{
    printf("%d \n",n->data);
    if(n->next != NULL) 
    {
        traverse(n->next);
    }
}

NODE* pre_insert(NODE* head,int x)
{
    NODE* newNode = create_node(x);
    newNode->next = head;
    return newNode;

}

NODE* rev_insert(NODE* head,int x)
{
    NODE* newNode = create_node(x);
    NODE* n = head;

    // null node
    if(n==NULL)
    {
        return newNode;
    }


    while(n->next != NULL)
    {
        n = n->next;
    }
    n->next = newNode;
    return head;
}

NODE* deleate_node(NODE* head,int x)
{
    NODE* n = head;
    // empty list
    if(n==NULL)
    {
        return head;
    }
    if(n->data == x)
    {
        return n->next;
    }
    while(n->next)
    {
        if(n->next->data=x)
        {
            n->next = n->next->next;
        }
        n = n->next;
    }
    return head;
}

NODE* insert(NODE* head,int x)
{
    //notes :i==NULL,说明n为head，解决头部插入
    // n == null，说明迭代超限，此时break，i为原链最后一个，不会出界。直接将newNode加入到i后面即可。
    NODE* newNode = create_node(x);
    NODE* n = head;
    NODE* i = NULL;
    if(n==NULL)
    {
        return newNode;
    }
    for(n;n!=NULL;n->next)
    {
        if(n->data>=x)
        {
            break;
        }
        i = n;
    }
    if(i!=NULL)
    {
        i->next = newNode;
    }
    newNode->next = n;
}

NODE* merge(NODE* a,NODE* b)
{
    NODE* head = create_node(INT_MIN);
    NODE* n = head;
    while(a!=NULL&&b!=NULL)
    {
        if(a->data<b->data)
        {
            n->next = a;
            n = n->next;
            a = a->next;
        }
        else
        {
            n->next = b;
            n = n->next;
            b = b->next;
        }
    }
    while(a!=NULL)
    {
        n->next = a;
        n = n->next;
        a = a->next;
    }
    while (b!=NULL)
    {
        n->next = b;
        n = n->next;
        b = b->next;
    }
    return head->next;
    
}

NODE* partition(NODE* head,int x)
{

}

int main()
{
    NODE* head = create_node(1);
    // printf("%d",head->data);
    NODE* n_1 = create_node(2);
    NODE* n_2 = create_node(5);
    NODE* n_3 = create_node(8);
    head->next = n_1;
    n_1->next = n_2;
    n_2->next = n_3;
    // traverse(head);
    NODE* null_head = NULL;
    NODE* h_2 = rev_insert(null_head,3);
    NODE* m_1 = create_node(4);
    NODE* m_2 = create_node(6);
    h_2->next = m_1;
    m_1->next = m_2;
    NODE* re = merge(head,h_2);
    traverse(re);


}