#include<cstdio>
#include<algorithm>
#include<map>
#include<time.h>
using namespace std;
typedef __int64 INT;
map<int,int> mp;
INT ss[15] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
int get_next(int n,int k)
{
	INT temp = n;
	temp*= temp;
	INT tt= temp;
	int t = 0;
	while(tt)
	{
		tt/= 10;
		t++;
	}
	return (int)(temp / ss[max(0,t-k)]);
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int  n,k,kase = 1,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&k,&n);
		mp.clear();
		int ans = 0;
		while(1)
		{
			ans = max(ans,n);
			if(mp[n]) break;
			mp[n] = 1;
			n = get_next(n,k);
		}
		printf("Case #%d: %d\n",kase++,ans);
	}
	return 0;
}
