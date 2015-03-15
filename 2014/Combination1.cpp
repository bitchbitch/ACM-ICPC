#include <stdio.h>
int m,n,a[100];
long s=0;
int main()
{int c(int k);
 printf("input n:"); scanf("%d",&n);
 printf("input m:"); scanf("%d",&m);
 c(1);
 printf("\nC(%d,%d)=%ld\n",n,m,s);
} 

int c(int k)
{int i,j;
 if (k<=m)
  {a[0]=0;
   for (i=a[k-1]+1;i<=n+k-m;i++)
     {a[k]=i;
      if (k==m)
        {s++; printf(" ");
         for (j=1;j<=m;j++)
           printf("%d",a[j]);
         if (s%10==0) printf("\n");
		}
	  else c(k+1);
	 }
  }
 return s;
}
