// File Name: uva10596.c
// Author: darkdream
// Created Time: 2013年06月15日 星期六 20时44分39秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[204][204];
int kk[204];
int visit[204];
void dfs(int k )
{
	for(int i = 0 ;i <= 55;i ++)
	{
		if(map[k][i] != 0  && visit[i] == 0)
		{	 
			visit[i] = 1;
			dfs(i);
		}
	}

}
void dfs1(int k )
{
	//printf("%d\n",k);
	for(int  i = 0;i <= 55 ;i ++)
	{
		if(map[k][i] != 0)
		{
		//	printf("%d %d\n",k,i);?????
			map[k][i]--;
			map[i][k]--;
			dfs1(i);
			printf("%d %d\n",i,k);
		}
	}
}
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int  t , m;
	scanf("%d",&t);
	for(int CASE = 1; CASE <= t; CASE ++)
	{ 

		int a,  b;
		scanf("%d",&m);
		int ok = 1;
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		memset(kk,0,sizeof(kk));
		while(m--)
		{
			scanf("%d %d",&a,&b);
			map[a][b]++ ;
			map[b][a]++;
			kk[a] ++;
			kk[b] ++;
		}
		for(int i = 0 ;i <= 55;i ++ )
		{
			if(kk[i] %2 == 1)
				ok = 0;
		}
		if(ok)
		{
			visit[a] = 1;
			dfs(a);
			for(int  i = 0 ; i <= 55;i ++)
				if( kk[i] != 0 &&  visit[i] == 0  )
					ok = 0 ;
		}
		if(CASE  != 1 )
			printf("\n");
		printf("Case #%d\n",CASE);
		if( ok == 1)
		{
			dfs1(a);
		}
		else
			printf("some beads may be lost\n");
	}

	return 0 ;
}

