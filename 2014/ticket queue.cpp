#include <stdio.h>
long f(int j,int i)
{long y;
 if (i==0 && j==0) y=0;
  else
   if (i==0) y=1;
   else
    if (j+2<i) y=0;
    else y=f(j-1,i)+f(j,i-1);
  return y;
}
int main()
{int m,n;
 printf("input m,n:");scanf("%d %d",&m,&n);
 printf("f(%d,%d)=%ld\n",m,n,f(m,n));
}
