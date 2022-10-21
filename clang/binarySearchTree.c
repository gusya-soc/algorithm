#include<stdio.h>
#include<stdlib.h>

#define false 0;
#define true 1;

typedef struct NODE
{
    int data;
    struct NODE* left;
    struct NODE* right;
}NODE;

struct findResult
{
    struct NODE* node;
    struct NODE* parent;
};

NODE* create(int x);
int cnt(NODE* node);
int sum(NODE* node);
int height(NODE* node);
int is_same(NODE* a,NODE* b);
// struct findResult* find(NODE* root,int x);
NODE* find(NODE* root,int x);
int insert(NODE* root,int x);
void btsDelete(NODE* root,int x);
void inTraverse(NODE* root);


int main()
{
    NODE* root = create(26);
    NODE* x_1 = create(13);
    NODE* x_2 = create(6);
    root->left = x_1;
    x_1->left = x_2;
    int result = is_same(root,x_1);
    printf("%d\n",result);

    // struct findResult* re = find(root,6);
    NODE* re = find(root,6);
    if(re)
    {
        // printf("node.data:%d\n",re->node->data);
        // printf("node.data:%d\n",re->parent->data);
        printf("node.data:%d\n",re->data);
    }else{
        printf("Null\n");
    }
    // printf("%d",root->data);
    inTraverse(root);
    return 0;
}




int cnt(NODE* node)
{
    if(node==NULL)
    {
        return 0;
    }
    return 1+cnt(node->left)+cnt(node->right);
}

NODE* create(int x)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int sum(NODE* node)
{
    if(node==NULL)
    {
        return 0;
    }
    return node->data+sum(node->left)+sum(node->right);
}

int height(NODE* node)
{
    if(node==NULL)
    {
        return 0;
    }
    int a = height(node->left);
    int b = height(node->right);
    if(a>=b)
    {
        return 1+a;
    }else{
        return 1+b;
    }
}

int is_same(NODE* a,NODE* b)
{
    if(!a && !b)
    {
        return true;
    }
    if(!a || !b)
    {
        return false;
    }
    if(a->data!=b->data)
    {
        return false;
    }else
    {
        return (is_same(a->left,b->left) && is_same(a->right,b->right));
    }

}

NODE* find(NODE* root,int x)
{
    while(root&&root->data!=x)
    {
        // if(root->data==x)
        // {
        //     return root;
        // }
        if(x<root->data)
        {
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return root;
}

// ISSUE: this function will cause unintended root changes
// struct findResult* find(NODE* root,int x)
// {
//     struct findResult* re;
//     NODE* parent;
//     NODE* node = root;
//     while(node && node->data!=x)
//     {
//         // if(root->data==x)
//         // {
//         //     return root;
//         // }
//         parent = node;
//         if(x<node->data)
//         {
//             node = node->left;
//         }else{
//             node = node->right;
//         }
//     }
//     re->node = node;
//     re->parent = parent;
//     return re;
// }


void inTraverse(NODE* root)
{
    if(!root)
    {
        return;
    }
    inTraverse(root->left);
    printf("%d ",root->data);
    inTraverse(root->right);
}

int insert(NODE* root,int x)
{
    return;
}