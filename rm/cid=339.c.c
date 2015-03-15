#include <stdio.h>

int main()
{
	int  a[100010];
	int n ;
	scanf("%d",&n);
	while(n--)
	{
		int m , i , j, k, t = 1 ,max = 0;
		scanf("%d",&m);

		for (i = 1;i <= m ; i ++ )
		{	scanf("%d",&a[i]);
             getchar();
		}
		for (i = 1; i<= m ; i ++)
		{
			int    sum1 = 0 ,sum2 =0; 
			double av = a[i]/2.0;
			for (j = 1; j <= m ; j ++)
			{
				if (a[j] >= a[i])
					sum1 ++;
				if (a[j] >= av)
					sum2++;
				if (a[j]*1.0/av ==2)
					sum2++;
			}
			if (sum1> sum2)
				max = sum1  ;
			else max = sum2;


		}
		printf("%d\n",max);
	}

	return 0;

}
