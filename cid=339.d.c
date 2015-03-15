#include <stdio.h>
int main()
{
  long int  t;
  scanf("%d",&t);
  while (t--)
  {
     long int sum =1;
	 int n ;
	 scanf("%d",&n);
	 int i ;
	 for(i = 1 ; i<= n; i ++ )
		 sum =sum*n;
  printf("%lld\n",sum);

  }
    return 0;
}
