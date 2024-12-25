//sum of a binary tree
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}*root=NULL;
struct queue
{
    struct node **Q;
    int rear;
    int front;
    int size;
};
void create(struct queue *q,int size)
{
      q->size=size;
    q->Q= (struct node **)malloc(q->size * sizeof(struct node *));
    q->front=q->rear=0;
  
}
void enqueue(struct queue *q,struct node *x)
{
    if((q->rear+1)%q->size==q->front)
    {
    printf("FULL");
    return ;
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
        
    }
}
struct node *dequeue(struct queue *q)
{
    struct node *x=NULL;
    
    if(q->front==q->rear)
    {
        printf("EMPTY");
        
    }
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isempty(struct queue q)
{
    return q.front==q.rear;
    
}

void treecreate()
{
    struct node *p,*t;
    struct queue q;
    int x;
    create(&q,100);
    printf("Enter the root element:");
    scanf("%d",&x);
    root=(struct node*)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isempty(q))
    {
        p=dequeue(&q);
        printf("Enter the left child of %d:",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->lchild=t->rchild=NULL;
        p->lchild=t;
        enqueue(&q,t);
        }
        
        printf("Enter the right child of %d:",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->lchild=t->rchild=NULL;
        p->rchild=t;
        enqueue(&q,t);
        }
        
        
    }
    
}
int sum(struct node *p)
{
    int x=0,y=0;
    if(p!=NULL)
    {
        x=sum(p->lchild);
        y=sum(p->rchild);
    
    return x+y+p->data;
    }
    return 0;
}
void preorder(struct node *p)
{
    if(p!=NULL)
    {
        printf("%3d",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
   
}
int main()
{
    treecreate();
    preorder(root);
    printf("\nThe sum of the tree is %d",sum(root));
}
