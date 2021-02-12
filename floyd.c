#include<stdio.h>
int main()
{

    int V,E;
    scanf("%d %d",&V,&E);
    int a[V+1][V+1];
    int i,j;
    for( i=0;i<=V;i++)
    {

        for(j=0;j<=V;j++)
        {
            if(i==j)
                a[i][j] = 0;
            else
            a[i][j] = 100;

        }
    }

    for(i=0;i<E;i++)
    {
         int u,v,w;
         scanf("%d %d %d",&u,&v,&w);
         a[u][v] = w;
         a[v][u] = w;
    }
    int k;
     for (k = 1; k <=V; k++)
    {

        for (i = 1; i <=V; i++)
        {

            for (j = 1; j <=V; j++)
            {

                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }

    for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
            printf("%d ",a[i][j]);

            printf("\n");
    }

}
