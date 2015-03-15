#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	int a,b;
    int c;
}a[1010];
int dp[1004][1004];
int cmp(const void * a,const void *b)
{
   return (*(node *)a).b - (*(node *)b).b;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		memset(a,0,sizeof(a));
		for(int i= 1;i<=n;i++)
		{
			scanf("%d %d",&a[i].a,&a[i].b);
		}
		memset(dp,0,sizeof(dp));
		qsort(a+1,n,sizeof(node),cmp);
	    for(int i = 1; i <= n ;i ++)
		{
			
			for(int j = 0 ;j <= n;j ++)
			{
			  if(dp[i-1][j] > dp[i-1][j+1] + a[i].a - (j) * a[i].b)   
			       dp[i][j] = dp[i-1][j];
			  else dp[i][j] = dp[i-1][j+1] + a[i].a - (j) * a[i].b;
			}
		}
		printf("%d\n",dp[n][0]);
	}
	return 0;
} 
