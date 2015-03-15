#include <stdio.h>
#include <math.h>
int main()
{
	int  n,i;
	scanf("%d",&n);
	for (i = 1 ; i <=  n ; i ++)
	{
		int a,b;
		double c;
		scanf("%d %d",&a,&b);


		c=1/tan(atan(1.0/a)-atan(1.0/b));
		printf("%d\n", (int)(2012.0/(b*c-a*b-c*a)+0.5));

	}
	return 0 ;

}
