#include <stdio.h>


void merge(int l,int m,int r,int a[])
{
	int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

       while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

       while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }


}

int mergesort(int low,int high,int a[])
{
	int mid;

	if (low<high)
	{
		mid=(high+low)/2;
		mergesort(low,mid,a);
		mergesort(mid+1,high,a);
		merge(low,mid,high,a);
	}
}
