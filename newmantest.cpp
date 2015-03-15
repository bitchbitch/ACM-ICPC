#include<stdio.h>
int main()
{
    int i,j,n,x,a,b;
    double sum1,sum2,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum1=sum2=1;
        scanf("%d%d",&a,&b);
        if(a<b)
        printf("0\n");
        if(a!=0&&b==0)
        printf("1\n");

        for(j=1;j<=b;j++){
            sum1=sum1*a;
            a=a-1;
        }
        for(x=1;x<=b;x++){
            sum2=sum2*x;
        }
        m=sum1/sum2;
        printf("%.0lf",m);
    }
    return 0;
}
