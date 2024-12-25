//Double Hashing
#include<stdio.h>
#define SIZE 10
#define PRIME 7
int hash(int key)
{
    return key%SIZE;
    
}
int prime(int key)
{
    return PRIME -(key%PRIME);
}
int probe(int h[],int key)
{
    int index=hash(key);
    int i=0;
    while(h[(index+i*prime(index))%SIZE]!=0)
    {
        i++;
    }
    return (index+i*prime(key))%SIZE;
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
    while(h[(index+i*prime(key))%SIZE]!=key)
    {
        i++;
        
    }
    if(h[(index+i*prime(key))%SIZE]==0)
    {
        return -1;
    }
    return (index+i*prime(key))%SIZE;
   
}
int main()
{
    int ht[10]={0};
    insert(ht,5);
    insert(ht,25);
    insert(ht,35);
    insert(ht,45);
    
    printf("\nkey %d",search(ht,25));
}
