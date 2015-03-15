#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<iostream>
using namespace std;
#define MAXN (2000+10)
#define MAXM (50000+10)
int n,m,a[MAXN][MAXN] = 0 ,b[MAXN][MAXN] = 0 ;
int x1,y1,x2,y2,t;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{scanf("%d",&a[i][j]); a[i][j]+=a[i-1][j];}

	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
		{scanf("%d",&b[i][j]); b[i][j]+=b[i][j-1];}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (x1>x2) {t=x1;x1=x2;x2=t;}
		if (y1>y2) {t=y1;y1=y2;y2=t;}
		long long ans=0;
	    for(int i=1;i<=n;i++) 
			ans+=1LL*(a[x2][i]-a[x1-1][i])*(b[i][y2]-b[i][y1-1]);
		printf("%lld\n",ans);
	}
	return 0;
}
