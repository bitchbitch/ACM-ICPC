// File Name: c.c
// Author: darkdream
// Created Time: 2013年09月15日 星期日 12时47分22秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long
#pragma comment(linker,"/STACK:102400000,102400000")
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
#define maxn 1100
int map1[maxn][maxn];
int visit[maxn][maxn];
int map2[maxn][maxn];
int xadd[] = {0,1,0,-1};
int yadd[] = {1,0,-1,0};
int n, maxstep; 
void dfs1(int x, int y , int d,int step)
{
	int tx = x + xadd[d];
	int ty = y + yadd[d];
	if(tx >= 0 && ty >= 0 && tx <= n-1 && ty <= n-1 && !visit[tx][ty])
	{
		visit[tx][ty] = 1;
		map1[tx][ty] = step +1;
		dfs1(tx,ty,d,step+1);
	}else{
		int td;
		td = (d + 1) % 4;
		tx = x + xadd[td];
		ty = y + yadd[td];
		if(tx >= 0 && ty >= 0 && tx <= n-1 && ty <= n-1 && !visit[tx][ty])
	    {
		 visit[tx][ty] = 1;
		 map1[tx][ty] =  step+1;
		 dfs1(tx,ty,td,step+1);
		}else{
		 maxstep = step;
		}
	}
}
int ok = 0;
int ansx ,ansy;
void dfs2(int x, int y , int d,int step){
	if(map1[x][y] == step || (map1[x][y] == maxstep && step >=  maxstep))
	{
	  ansx = x; 
	  ansy = y;
	  ok = 1; 
	  return;
	}
	if(ok)
		return;
	int tx = x + xadd[d];
	int ty = y + yadd[d];
	if(tx >= 0 && ty >= 0 && tx <= n-1 && ty <= n-1 && !visit[tx][ty])
	{
		visit[tx][ty] = 1;
	     map2[tx][ty] = step+1;
		dfs2(tx,ty,d,step+1);
	}else{
		int td;
		td = (d - 1 + 4) % 4;
		tx = x + xadd[td];
		ty = y + yadd[td];
		if(tx >= 0 && ty >= 0 && tx <= n-1 && ty <= n-1 && !visit[tx][ty])
	    {
		 visit[tx][ty] = 1;
		 map2[tx][ty] = step+1;
		 dfs2(tx,ty,td,step+1);
		}
		else{
		 if(map1[x][y] >= step)
		 {
		   ok = 1; 
		   ansx = x; 
		   ansy = y ;
		   return;
		 }
		}
	}
}
int main(){
	while(scanf("%d",&n) != EOF &&  n ){
	    maxstep = -1;
		int x,y,d;
		ok = 0 ;
		memset(map1,0,sizeof(map1));
		memset(visit,0,sizeof(visit));
		scanf("%d %d %d",&x,&y,&d);
		visit[x][y] = 1;
		map1[x][y] = 1;
		dfs1(x,y,d,1);
        
		memset(map2,0,sizeof(map2));
		memset(visit,0,sizeof(visit));
		scanf("%d %d %d",&x,&y,&d);
		map2[x][y] = 1;
		visit[x][y] = 1;
		dfs2(x,y,d,1);
		
		
	   /*for(int i = 0 ;i < n;i ++)
		{
		  for(int j = 0 ; j <n ;j ++)
		   {
		     printf("%d ",map1[i][j]);
		   }
		  printf("\n");
		}
		printf("\n");
	   for(int i = 0 ;i < n;i ++)
		{
		  for(int j = 0 ; j <n ;j ++)
		   {
		     printf("%d ",map2[i][j]);
		   }
		  printf("\n");
		}*/
       
		if(ok)
			printf("%d %d\n",ansx,ansy);
		else printf("-1\n");
	}

	return 0 ;
}
