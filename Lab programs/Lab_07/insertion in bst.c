#include <stdio.h>
#include<stdlib.h>
struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;
void insert(int key)
{
    struct node *t=root;
    struct  node *r,*p;
    if(root==NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        t=t->lchild;
        else if(key>t->data)
        t=t->rchild;
        else 
        return ;
        
    }
        p=(struct node*)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        if(key<r->data)
        r->lchild=p;
        else
        r->rchild=p;
    
}
void preorder(struct node *p)
{
    if(p)
    {
        printf("%d  ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
        
    }
}
int main()
{
 
   insert(9);
    insert(15);
     insert(5);
      insert(20);
       insert(16);
        insert(8);
         insert(12);
       
   
    preorder(root);
} 