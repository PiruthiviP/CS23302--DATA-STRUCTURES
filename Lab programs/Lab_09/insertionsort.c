//Insertion  sort
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionsort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int x=a[i];
        while(j>-1&&a[j]>x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
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
    insertionsort(arr,n);
    printf("\nThe sorted numbers are:\n");
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
}