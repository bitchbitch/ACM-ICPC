#include <stdio.h>
int main()
{int a,b,k,n,i,j,h,t,u,c[3000],d[3000];
 printf("Please input a,b:");
 scanf("%d%d",&a,&b);
 n=0;
 for (i=a;i<=b;i++)
 {for (j=1;j<=i-1;j++)
   {for (t=0,u=2;u<=j;u++)
      if (i%u==0 && j%u==0)
        {t=1;break;}
    if (t==0)
       {n++;c[n]=j;d[n]=i;}
   }
 }
 for (i=1;i<=n-1;i++)
   for (j=1;j<=n-i;j++)
      if (c[j]*d[j+1]>c[j+1]*d[j])
      {h=c[j];c[j]=c[j+1];c[j+1]=h;
       h=d[j];d[j]=d[j+1];d[j+1]=h;
	  }
 printf("n=%d\n",n);
 printf("Term %d is: %d/%d\n",n-10,c[n-10],d[n-10]);
}
