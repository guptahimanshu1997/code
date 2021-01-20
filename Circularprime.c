#include<stdio.h>
#include<math.h>
int checkprime(int n)
{
     int i;
    for( i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int circular(int n)
{
    int temp1 = n;
    int temp2  = n;
    if(n<=0)
        return -1;
        else if(n==1)
        return 0;
    else
    {

        int count  = 0;
        while(temp1)
        {
           count++;
           temp1 = temp1/10;

        }

        while(checkprime(temp2))
        {
            int rem = temp2 % 10;
            int div = temp2 / 10;
            temp2 = (pow(10, count - 1)) * rem + div;
            if(temp2==n)
            {
                return 1;

            }


        }
        return 0;
    }


}

int main()
{

    int n;
    scanf("%d",&n);
    int ans = circular(n);
    if(ans==1) printf("1");
    else if(ans==-1) printf("-1");
    else printf("0");
}
