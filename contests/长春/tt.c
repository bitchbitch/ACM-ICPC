#include <stdio.h>
#include <stdint.h>
#define mod 95041567
/*该函数是用来计算组合函数的即 n! / (m! * (n-m)!)*/
uint64_t combine(int n,int m)
{
	int i = 0;
	uint64_t a = 1,b = 1,k = 1;

	if (m > n / 2) 
		m = n - m;

	/*get (n - m)! */
	for (i = n - m;i > 1;i--) {
		a *= i;
	}

	/* get n! */
	for (i = n;i > 1;i--) {
		b *= i;
	}

	/* get m! */
	for (i = m;i > 1;i--) {
		k *= i;
	}

	return b / (k * a);
}

uint64_t bell(int n) 
{
	uint64_t t = 0;
	int i;

	if (n == 0)
		return 1;
	else {
		for (i = 0;i <= n-1;i++) {
			t += combine(n-1,i) * bell(i) ;
		}
	}

	return t;
}

int main(void)
{
	int n = 0;
	while (scanf("%d",&n) != EOF) {
		printf("bell(%d) = %lld\n",n,bell(n));
	}
}

