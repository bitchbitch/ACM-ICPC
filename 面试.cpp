#include<stdio.h>
int main()
{
    int n,m,a[10],b[10];
    while(~scanf("%d%d",&n,&m))
    {
        int sum=0,i=0,j=0;
        while(n>0)
        {
            a[i]=n%10;
            n=n/10;
            i++;
        }
        while(m>0)
        {
            b[j]=m%10;
            m=m/10;
            j++;
        }
        if(i>j)
        j=i;
        for(i=0;i<j;i++)
        {
            if(a[i]+b[i]>9)
            {
                sum++;
                a[i+1]++;
            }
        }
        if(sum==0)
        printf("No operator\n");
        else if(sum==1)
        printf("%d operator\n",sum);
        else
        printf("%d operators\n",sum);
    }
    return 0;
}

