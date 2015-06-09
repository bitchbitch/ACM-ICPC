#include <stdio.h>
#include <math.h>
int main()
{float s;
 int x,n,b,c,d,i,j,l,a[30000];
 printf("请输入起始小数位：");
 scanf("%d",&x);
 x=x+9;
 s=0;n=1;
 while (s<=x+10)
  {s+=log10(n);n++;}
 for (i=0;i<=x+5;i++) a[i]=0;
 for (c=1,j=n;j>=1;j--)
 {d=j;
  for (i=0;i<=x+4;i++)
    {a[i]=c/d;c=(c%d)*10+a[i+1];}
  a[i+5]=c/d;
  for (b=0,i=x+5;i>=0;i--)
   {a[i]=a[i]*1+b;b=a[i]/10;a[i]=a[i]%10;}
  a[0]+=1;c=a[0];
 }
 for (i=x-9;i<=x;i++)
     printf("%d",a[i]);
 printf("\n");
}
