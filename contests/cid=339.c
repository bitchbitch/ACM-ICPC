#include <stdio.h>
#include <math.h>
#define  s 1000003
int a[s];
int main()
{
   __int64 i = 1,n;
   a[1] = 2;
   for (i = 2 ; i < s ; i ++)
	   a[i] = a[i-1]*i*2 % s; 
	  
   scanf("%I64d",&n);
	for (i = 1 ; i <= n ; i ++)
	{
	  __int64 k;
	  scanf("%I64d",&k);
	  if (k < s)
	      printf("%I64d\n",a[k]);
	  else
		  printf("0\n");
	}
   return 0;
}

