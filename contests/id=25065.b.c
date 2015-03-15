#include <stdio.h>
#include <math.h>
int main()
{
  double a,b,c,d;
  int n,i;
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i++)
  { double l,sum;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    l =( a+b+c+d)/2.0;
	
	sum = (l-a)*(l-b)*(l-c)*(l-d);
	if (l <= a || l<=b || l<=c || l<=d )
		printf("Case %d: -1\n",i);
	else 
	{
	 sum = sqrt(sum);
	 printf("Case %d: %.6lf\n",i,sum);
	
	}
  
  }
  return 0;
}
