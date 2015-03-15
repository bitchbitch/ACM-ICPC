// File Name: range.c
// Author: darkdream
// Created Time: 2014年04月07日 星期一 17时23分06秒
/*
ID: dream.y1
PROG: range
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

int map[1004][1004];
int hang[1005][1005];
int lie[1005][1005];
int dp[1005][1005];
int M(int x , int y )
{
	if(x > y )
		return x;
	 return y ; 
}

int main(){
	int n ,m; 
	while(scanf("%d %d",&m,&n)!= EOF)
	{
		memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));
		memset(dp,0,sizeof(dp));
		memset(map,0,sizeof(map));
		for(int i =1 ;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				scanf("%d",&map[i][j]);
		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= m;j ++)
			{
				if(map[i][j])
					hang[i][j] = hang[i][j-1] + 1;
			}
		}
		for(int i = 1;i <= m;i ++)
		{
			for(int j = 1;j <= n;j ++)
			{
				if(map[j][i])
					lie[j][i] = lie[j-1][i] + 1;
			}
		}
		int max = 0;
		for(int i = 1;i <= m;i ++ )
		{ dp[1][i] = map[1][i];
			max = M(max,dp[1][i]);
		}
		for(int i = 2; i <= n;i ++)
		{
			for(int j = 1;j <= m; j ++)
			{
				int x = dp[i-1][j-1] +1;
				for(int p = x;p >= 1;p --)
				{
					if(lie[i][j] >= p && hang[i][j] >= p)
					{
						dp[i][j] = p;
						break;
					}
				}
				max = M(max,dp[i][j]);
			}
		}
		printf("%d\n",max*max);
	}
	return 0 ;
}
