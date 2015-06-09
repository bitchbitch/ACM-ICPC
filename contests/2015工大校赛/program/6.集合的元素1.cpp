#include <stdio.h>
int main()
{int n,t,k,i,j,h,a[30000];
 printf("please input n=");
 scanf("%d",&n);
 a[1]=1;a[2]=2;t=2;k=3;
 while (t<n)
 {for (i=2;i<=t;i++)
   for (j=1;j<i;j++)
     if ((k==2*a[i]+3*a[j]||k==2*a[j]+3*a[i])&&(k!=a[t]))
       {t++;a[t]=k;}
  k++;
 }
 printf("%d\n",a[n]);
} 
