//Bubble sort
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int a[],int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                flag=1;
            }
            
        }
        if(flag==0)break;
    }
}

int main()
{
    srand(time(NULL));
    int arr[30];
    int n;
    printf("How many number u want to enter:");
    scanf("%d",&n);
    printf("Enter the numbers");
    for(int i=0;i<n;i++)
    arr[i]=rand()%(100+1)-1;
    bubblesort(arr,n);
    printf("The sorted numbers are:\n");
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
}