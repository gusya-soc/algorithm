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
struct findResult* find(NODE* root,int x);
// NODE* find(NODE* root,int x);
int insert_1(NODE* root,int x);
void btsDelete(NODE* node,int x);
void inTraverse(NODE* root);
void levelTraverse(NODE* node);
NODE* btsDeleteRecursion(NODE* node,int x);

int main()
{
    NODE* root = create(26);
    NODE* x_1 = create(13);
    NODE* x_2 = create(6);
    root->left = x_1;
    x_1->left = x_2;
    int result = is_same(root,x_1);
    printf("%d\n",result);

    struct findResult* re = find(root,6);
    // NODE* re = find(root,6);
    if(re)
    {
        printf("node.data:%d\n",re->node->data);
        printf("node.data:%d\n",re->parent->data);
        // printf("node.data:%d\n",re->data);
    }else{
        printf("Null\n");
    }
    // printf("%d",root->data);
    inTraverse(root);
    
    printf("\n");
    NODE* root2 = create(6);
    insert_1(root2,4);
    insert_1(root2,8);
    insert_1(root2,2);
    insert_1(root2,1);
    insert_1(root2,3);
    insert_1(root2,7);
    insert_1(root2,9);
    inTraverse(root2);
    printf("\n");
    //not work
    // btsDelete(root2,6);
    // inTraverse(root2);

    btsDeleteRecursion(root2,6);
    inTraverse(root2);
    printf("\n%d ",root2->data);
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

// NODE* find(NODE* root,int x)
// {
//     while(root&&root->data!=x)
//     {
//         // if(root->data==x)
//         // {
//         //     return root;
//         // }
//         if(x<root->data)
//         {
//             root = root->left;
//         }else{
//             root = root->right;
//         }
//     }
//     return root;
// }

// ISSUE: this function will cause unintended root changes
struct findResult* find(NODE* root,int x)
{
    struct findResult* re = (struct findResult*)malloc(sizeof(struct findResult));
    NODE* parent;
    NODE* node = root;
    while(node && node->data!=x)
    {
        parent = node;
        if(x<node->data)
        {
            node = node->left;
        }else{
            node = node->right;
        }
    }
    re->node = node;
    re->parent = parent;
    return re;
}


void inTraverse(NODE* node)
{
    if(!node)
    {
        return;
    }
    inTraverse(node->left);
    printf("%d ",node->data);
    inTraverse(node->right);
}
void levelTraverse(NODE* node)
{
    if(!node)
    {
        return;
    }
    // TODO：we dont have QUEUE!!!

}

int insert_1(NODE* node,int x)
{
    // NODE* parent;
    // while(node && node->data!=x)
    // {
    //     parent = node;
    //        if(x<node->data)
    //     {
    //         node = node->left;
    //     }else{
    //         node = node->right;
    //     }
    // }
    // if(node)
    // {
    //     // target node existed
    //     return 0;
    // }

    struct findResult* p = find(node,x);
    if(p->node)
    {
    //  the target node existed
        return 0;
    }
    node = create(x);
    if(x<p->parent->data)
    {
        p->parent->left = node;
    }else{
        p->parent->right = node;
    }
    return 1;
}


void btsDelete(NODE* node,int x)
{
    if(!node)
    {
        return;
    }
    struct findResult* p = find(node,x);
    if(!p->node)
    {
        //the node not found
        return;
    }
    if(p->node->left&&p->node->right)
    {
        NODE* tmp = p->node->right;
        while(tmp->left)
        {
            tmp = tmp->left;
        }
        p->node->data = tmp->data;
        btsDelete(p->node->right,tmp->data);

    // TODO:we need more elegant!!
    }else if(p->node->left) //only have one node
    {
        p->node->data = p->node->left->data;
        free(p->node->left);
        p->node->left = NULL;
        
    }else if(p->node->right)
    {
        p->node->data = p->node->right->data;
        free(p->node->right);
        p->node->right = NULL;
    }else{
        p->node = NULL;
    }
}

NODE* btsDeleteRecursion(NODE* node,int x)
{
    if(!node)
    {
        return NULL;
    }
    if(node->data==x)
    {
        if(!node->left)
        {
            return node->right;
        }
        if(!node->right)
        {
            return node->left;
        }

        NODE* tmp = node->right;
        while(tmp->left)
        {
            tmp=tmp->left;
        }
        node->data = tmp->data;
        node->right = btsDeleteRecursion(node->right,tmp->data);
    }else if(x < node->data)
    {
        node->left=btsDeleteRecursion(node->left,x);
    }else{
        node->right=btsDeleteRecursion(node->right,x);
    }
    return node;
}