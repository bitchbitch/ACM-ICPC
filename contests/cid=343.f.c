#include <stdio.h>
#include <string.h>
long  long int a[110],b[110];
int main()
{
	int t ;
	scanf("%d",&t);
	while (t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int N, D, A, K, X ,i, j;
		long long sum = 0 ;
		scanf("%d %d %d %d %d",&N,&D,&A,&K,&X);
		a[K] =N ;
		for (i = 1;i <= X ; i++)
		{
			for (j = K+1; j >= 1 ; j --)
				a[j] = a[j-1];
			for (j = D+1 ; j >=2 ; j--)
				b[j] = b[j-1];
			b[1] =a[K+1];

			for (j = 1 ;  j <= A ;j ++)
				a[0] += b[j];

			for (j = 1; j <=D ; j++)
				sum = sum +b[j];

		}
		printf("%lld\n",sum*5);

	}
	return 0 ;
}
