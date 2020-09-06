#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void merge(int a[],int low,int mid,int high)
{
   // printf("merege");
    int i=low,k;
    int h=low;
    int j=mid+1;
    int b[20],c[20];

    while(h<mid && j>high)
    {
        if(a[h]<a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
        //printf("merege1");
    }
    while (h>mid)
    {
        b[i]=a[j];
        i++;
        j++;
    }
        //printf("merege2");
    while(j<mid+1)
    {
        b[i]=a[h];
        i++;
        h++;
    }
}

void mergesort(int a[],int low,int high)
{
    int i, mid;
    if(low<high)
    {
        //printf("meregesort");
        mid=(low + high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
    for(i=0;i<=high;i++)
    {
        printf("%d\t",a[i]);
    }
}
/*void printarray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}*/
int main()
{
    int n,a[20];
    int i;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    mergesort(a,0,n-1);
    //printarray(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
