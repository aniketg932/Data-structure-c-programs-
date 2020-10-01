#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void printRandoms(int lower, int upper, int *a)
{
    int i;
    for (i = 0; i < 50; i++)
    {
        a[i]=(rand()%(upper - lower + 1));
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high-1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int part= partition(arr, low, high);
        quickSort(arr, low, part - 1);
        quickSort(arr, part+1, high);
    }
}


int main()
{
    double time_speed=0.0;
    clock_t begin=clock();

    int a[50 ];
    int lower=1,upper=50;
    printRandoms(lower, upper , a);

    printf("\n\n Unsorted array: \n\n");
    for(int i=0;i<50;i++)
    printf("%d ",a[i]);
    printf("\n");

    quickSort(a,0,49);

    printf("\n\n Sorted array: \n\n");
    for(int i=0;i<50;i++)
    printf("%d ",a[i]);
    printf("\n");

    printf("\n\n Reverse array: \n\n");
    for(int i=49;i>=0;i--)
    printf("%d ",a[i]);
    printf("\n");



    clock_t end=clock();
    time_speed=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nThe execution time %lf \n",time_speed);
    return 0;
}

