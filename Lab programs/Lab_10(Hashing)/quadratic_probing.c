//Quadratic probing
#include<stdio.h>
#define SIZE 10
int hash(int key)
{
    return key%SIZE;
    
}
int probe(int h[],int key)
{
    int index=hash(key);
    int i=0;
    while(h[(index+i*i)%SIZE]!=0)
    {
        i++;
    }
    return (index+i*i)%SIZE;
}
void insert(int h[],int key)
{
    int index=hash(key);
    if(h[index]!=0)
    {
        index=probe(h,key);
    }
    h[index]=key;
}
int search(int h[],int key)
{
    int index=hash(key);
    
    int i=0;
    while(h[(index+i*i)%SIZE]!=key)
    {
        i++;
        
    }
    if(h[(index+i*i)%SIZE]==0)
    {
        return -1;
    }
    return (index+i*i)%SIZE;
   
}
int main()
{
    int ht[10]={0};
    insert(ht,12);
    insert(ht,13);
    insert(ht,23);
    insert(ht,43);
    
    printf("\nkey %d",search(ht,43));
}
