// File Name: concom.c
// Author: darkdream
// Created Time: 2013年12月11日 星期三 13时12分05秒
/*
ID: dream.y1
PROG: concom
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int hs[200][200] = {0};
double map[200][200] = {0};
int k;
int visit[200] = {0};
void dfs()
{
	for(int i = 1;i <= 100 ;i ++)
	{
	  int ok = 0 ;
	  if(hs[k][i] && !visit[i] )
	  {
		 visit[i] = 1;
	     for(int j = 1;j <= 100 ;j ++)
		 {
		    map[k][j] += map[i][j];
			if(map[k][j] >= 0.5)
			{
			   hs[k][j] = 1; 
			   ok = 1;
			}
		 }
		 
	  }
	  if(ok)
		  i = 0 ;
	}
}
int main(){
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	int n ;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		int a, b ,temp;
		scanf("%d %d %d",&a,&b,&temp);
		map[a][b] = temp*1.0/100;
		if(map[a][b] >=  0.5- 1e-8)
		{
			hs[a][b] = 1;
		}
	}
	for(k =1 ;k <= 100; k ++)
	{
		memset(visit,0,sizeof(visit));
		visit[k] = 1;
		dfs();
	}
	for(int i = 1;i <= 100;i ++)
		for(int j = 1; j<= 100  ;j ++)
		{
			if(hs[i][j] && i != j )
				printf("%d %d\n",i,j);
		}
	return 0 ;
}
