#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
const int maxn = 100005;
int A[maxn];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i  < n;++i)
		scanf("%d",&A[i]);
		int ans = -1000000009,M = A[n-1];
		for(int i = n - 2;i >= 0;--i)
		{
			M = min(M,A[i+1]);
			ans = max(ans,A[i]-M);
		}
		printf("%d\n",ans);
	}
	return 0;
}		
