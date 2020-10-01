#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int *, int);
int main()
{
    double time_speed=0.0;
    int choice,j;
    int lower=100,upper=999;
    printf("choose \n 1 to sort a sorted list. \n 2 to sort a random list. \n 3 to sort a reverse order sorted list.");
    scanf("%d",&choice);
    int n;
    printf("enter the number of elements you want to enter.");
    scanf("%d",&n);
    int a[n];
    switch(choice)
    {
    case 1:
        j=0;
        for(int i=1;i<=n;i++)
        {
            a[j]=i;
            j++;
        }
        clock_t begin=clock();
        sort(a,n);
        clock_t end =clock();
        time_speed=(double)(end-begin)/CLOCKS_PER_SEC;
         printf("\n time speed = %f",time_speed);
    break;
    case 2:
         for(int i=0;i<n;i++)
         a[i]=(rand()%(upper-lower+1));
         begin=clock();
         sort(a,n);
         end =clock();
         time_speed=(double)(end-begin)/CLOCKS_PER_SEC;
          printf("\n time speed = %f",time_speed);
    break;
    case 3:
         j=0;
        for(int i=n;i>=1;i--)
        {
            a[j]=i;
            j++;
        }
        begin=clock();
        sort(a,n);
        end =clock();
        time_speed=(double)(end-begin)/CLOCKS_PER_SEC;
         printf("\n time speed = %f",time_speed);
    break;
    default:
        printf("wrong choice");
    }
}
    void sort(int arr[], int len)
{
    int i, key, j;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    }
