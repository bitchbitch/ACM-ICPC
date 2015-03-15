#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	int a,b,c;
}dp[1010];
int cmp(const void *a ,const void *b)
{
  return (*(node *)b).c - (*(node *)a).c;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		for(int i= 1;i<= n;i++)
		{
			scanf("%d%d",&dp[i].a,&dp[i].b);
		}
		long long  max = 0;
		for(int i = 1;i <= n; i ++)
		{
          for(int j = i; j<= n;j ++)
		  {
		     dp[j].c = dp[j].a - (i-1) *dp[j].b;
		  }
		  qsort(dp+1,n,sizeof(node),cmp);
		  long long sum = 0 ; 
		  long long tsum = 0 ; 
		  for(int j = 1;j <= i ;j ++)
		  {
		    sum += dp[j].c ; 
			tsum += (i-j-1)*dp[j].b ; 
		  }
		  sum -= tsum ; 
		  if(sum > max)
			  max = sum ; 
		}
		printf("%lld\n",max);
	}
	return 0;
} 
