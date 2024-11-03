//count sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int findmax(int arr[], int n) {
    int x = arr[0]; 
    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
            x = arr[i];
    }
    return x;
}
void countsort(int arr[],int n)
{
    int max=findmax(arr,n);
    int *b = malloc(sizeof(int) * (max + 1));
    for(int i=0;i<max+1;i++)
    {
        b[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        b[arr[i]]++;
        
    }
    int i=0;
    int j=0;
    while(i<max+1)
    {
        if(b[i]>0)
        {
            arr[j++]=i;
            b[i]--;
        }
        else
        i++;
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
    countsort(arr,n);
    printf("\nThe sorted numbers are:\n");
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
}