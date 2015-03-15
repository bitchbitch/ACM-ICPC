#include<string.h>
#include<algorithm>
#include<cstdio>
using namespace std;
const int M=1000000007;
long long db[1115];
int main()
{
	int n;
	int i,j;
	int t;
	long long ans;
	db[1]=1;
	for(i=2;i<1111;++i)
	{
		db[i]=(10*db[i-1]+1)%M;
	}
	while(scanf("%d",&n) != EOF)
	{
		ans=0;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				scanf("%1d",&t);
				ans+=(t*db[n-j+1]*j+t*db[n-i+1]*i);
				ans%=M;
			}
		}
		printf("%lld\n",ans);
	}	
	return 0;
}
