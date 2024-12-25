//Selection  sort
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int a[],int n)
{   
    int i,j,k;
    for( i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(a[j]<a[k])
            
                k=j;
            }
       
        swap(&a[i],&a[k]);
    }

}

int main()
{
    srand(time(NULL));
    int arr[30];
    int n;
    printf("How many number u want to enter:");
    scanf("%d",&n);
   
    for(int i=0;i<n;i++)
    arr[i]=rand()%(100+1)-1;
    printf("The elements before sorted\n");
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
    selectionsort(arr,n);
    printf("\nThe sorted numbers are:\n");
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
}