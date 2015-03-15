#include <stdio.h>
int main()
{
	int  n,a[30],b[30];
	double c[30];
	while (scanf("%d",&n)!= EOF)
	{
		int i ,j,k,m ,t ,sum1 = 0;
		__int64  sum2=0;
		double t1;
		for (i = 1 ; i<= n ;i++)
		{scanf("%d %d",&a[i],&b[i]);
			sum1 = sum1 +a[i];
			c[i] = 1.0*a[i]/b[i];
		}	
		for (i = 1; i <= n ; i ++)
		{   for (j = i ;j <= n; j ++)
			{
				if (c[i] <c[j])
				{
					t = a[i];
					a[i]=a[j];
					a[j]= t ;
					t = b[i];
					b[i]=b[j];
					b[j]= t ;
					t1 = c[i];
					c[i] = c[j];
					c[j]= t1 ;


				}
			}
			sum2 = b[i]*sum1+sum2;
			sum1 = sum1 -a[i];
		}
		printf("%I64d\n",sum2);
	}
	return 0;
}

