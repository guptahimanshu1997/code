#include<stdio.h>
#include<stdlib.h>
int comp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;
    for( i=0;i<n;i++)
        scanf("%d",&arr[i]);


    qsort(arr,n,sizeof(int),comp);



        for(i=0;i<n;i++)
        {

                printf("%d ",arr[i]);


        }
        return 0;
}

