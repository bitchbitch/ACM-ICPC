#include <stdio.h>
int main()
{   int n,t,k,i,j,h,a[30000];
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        a[1]=1;a[2]=2;k=2;
        for (t=3;t<=n;t++)
        {
            k++;
            for (h=0,i=2;i<t;i++)
            {for (j=1;j<i;j++)
                if (k==2*a[i]+3*a[j]||k==2*a[j]+3*a[i])
                {h=1;a[t]=k;break;}
                if (h==1) break;
            }
            if (h==0) t--;
        }
    printf("%d\n",a[n]);
    }
    return 0 ; 
} 
