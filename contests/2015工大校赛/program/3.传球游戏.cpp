#include <stdio.h>
int gcd(int m,int n)
{int i,t;
 if (m>n) {t=m;m=n;n=t;}
 for (i=m;i>=1;i--)
    if (m%i==0 && n%i==0)
     return i;     
}

int main()
{int n,k,i;
 scanf("%d",&n);
 k=n/2;
 for (i=k;i>=1;i--)
   if (gcd(n,i)==1)
      {printf("%d\n",i);break;}
}
