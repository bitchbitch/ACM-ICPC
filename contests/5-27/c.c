// File Name: c.c
// Author: darkdream
// Created Time: 2013年05月31日 星期五 18时14分34秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[1000010];
int c[1000010];
int b[1000010];
int f[1000010];
long long dp[1000010];
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n ;
	while(scanf("%d",&n) != EOF,n)
	{  
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i ++)
		{	scanf("%d",&a[i]);
		
     		c[i-f[a[i]]] ++;
			f[a[i]] = i ;
		}
        memset(f,0,sizeof(f));
		b[1] = 1;
		f[a[n]] = 1;
		for(int i = 2;i <= n;i ++)
		{
            if(f[a[n-i+1]] == 0)
			{
                f[a[n-i+1]] = 1;
				b[i] = b[i-1]+1;
			}
			else  b[i] = b[i-1];
		}
		dp[1] = n;
		int sum = n;
		for(int i = 2 ; i <= n; i ++)
		{
			dp[i] = dp[i-1] - b[i-1];
			sum-= c[i-1];
			dp[i]+= sum;
		}
		
		int q; 
		scanf("%d",&q);
		while(q--)
		{
			int temp;
			scanf("%d",&temp);
		    printf("%I64d\n",dp[temp]) ;
		}
	}

	return 0 ;
}
