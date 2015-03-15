#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;
#define M 1000000007
#define maxn 100005
int n,m,p;
LL c[maxn];
LL dp[maxn];
LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
LL C(int n)
{
    LL ans = 1;
    for(int i=1; i<= n; i++)
    {
        LL a = (n+1-i);
        LL b = i ;
        ans = ans * (a * quick_mod(b, p-2) % p) % p;
        c[i] = ans ;
	}
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
	dp[1] = 1;
	c[0] = 1;
	dp[1] = 1;
    for(int i = 2;i <= 100000;i ++ )
		dp[i] = (i * dp[i-1])%M;
	while(T--)
    {
	    p = M ; 
		scanf("%d",&n);
		LL sum ; 
		sum = (dp[n]-1)%M;
		printf("%lld\n",sum);
	}
    return 0;
}

