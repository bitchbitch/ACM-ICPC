#include <stdio.h>
#include <string.h>
#include <math.h>
long long gcd(long long a, long long b)
{
	return b == 0 ? a:gcd(b,a%b);
}
long long ABS( long long a)
{
  if(a <= 0 )
	  return -a ; 
  else 
	  return a;
}
int main()
{
	//freopen("1001.in","r",stdin);
	long long t ;
	scanf("%lld",&t);
	while(t--)
	{
		long long k , n , m ;
		scanf("%lld %lld %lld",&k,&n,&m);
		// printf("%lld %lld\n",n,m);
		if(m < n )
		{
			long long temp = n;
			n = m;
			m = temp ;
		}

		long long step = n* m /gcd(n,m);
		long long sum = 0 ;
		long long t = 1;
		// printf("%lld**\n",step);
		k = k - 1 ; 
		// printf("%lld %lld %lld\n",k,step,gcd(3,4));
		if(k >= step )
		{

			for(long long i = 1; i <= step/n -1; i ++)
			{
				if((i+1) * n - 1 >= t *m )
				{

					sum += ((i*n) % m) *(t*m - i *n);
					sum += (((i+1)*n-1) - t * m +1) *(ABS(((i + 1 )*n -1)%m - (n-1)));
					t ++ ;
					// printf("\n******%lld\n",(i*n) % m);
				}
				else
				{
					sum += ((i*n) % m ) * n;
					// printf("\n******%lld\n",(i*n % m));
				}

			}
			// printf("\n******%lld\n",sum);
			sum *= (k/step);
			k = k - (step)*(k/step);
		}

		t = 1;
		for(long long i = 0; ; i ++ )
		{
			if(k >= (i+1) * n )
			{
				if((i+1) * n - 1 >= t *m )
				{

					sum += ((i*n) % m) *(t*m - i *n);
					//printf("%lld\n",sum);
					sum += (((i+1)*n-1) - t * m + 1) *(ABS(((i + 1 )*n -1)%m - (n-1)));
					t ++ ;
				}
				else
				{
					sum += ((i*n) % m ) * n;
				}
				// printf("\n1*****%lld\n",sum);
			}
			else
			{
				if(t * m <= k )
				{
					sum += ((i*n) % m) *(t*m - i *n);
					// printf("%lld\n",sum);
					sum += (k - t*m + 1 ) *(ABS(((i + 1 )*n -1)%m - (n-1)));
					t++;
				}
				else
					sum +=(i*n % m ) * (k - i*n +1);
				//printf("\n2*****%lld\n",sum);
				break;
			}
		}

		printf("%lld\n",sum);

	}
	return 0 ;
}
