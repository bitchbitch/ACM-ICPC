#include <stdio.h>
 int a[1000004];
int main()
{
  long   int n,i;
	a[1]=1;
   for (i = 2; i <=1000003; i++)
	{   int t = i;
		while(t % 10 == 0)
		   t = t /10;

    	a[i] = a[i-1]*(t%100000);
		while(a[i]%10 == 0 )
			a[i] = a[i]/10;
         a[i] = a[i]%100000;
	}



	while (scanf("%d",&n) != EOF)
	{
	  printf("%lld\n",a[n]%10);
	}
  return 0;

}
