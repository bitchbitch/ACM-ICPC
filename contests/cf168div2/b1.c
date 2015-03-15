// File Name: b1.c
// Author: darkdream
// Created Time: 2013年02月21日 星期四 20时50分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define N 55
char d[N][N];
bool f[N][N];
int vis[N][N][4][2];
int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};
int s[N*N];
int n , m ;
bool cheak(int x,int y)
{
  if(x <0 || x >= n ) return 0;
  if (y < 0 || y >= m) return 0 ;
  if (d[x][y] == 'W') return 0 ;
  return 1;

}
void dfs(int x,int y ,int k ,int used)
{
    int i ;
	vis[x][y][k][used] = 1;
	f[x][y] = 1;
	int tx = x + dx[k], ty = y + dy[k];
	if(cheak(tx,ty) && !vis[tx][ty][k][used]) dfs(tx,ty,k,used);
	if (used) return ;
	for (i = 0 ;i <4; i++)
	{
	     if (i== k) continue;
		  tx = x + dx[i], ty = y + dy[i];
		 if(cheak(tx,ty) && !vis[tx][ty][i][1]) dfs(tx,ty,i,1);

	}


}
int main(){
    int i ,j , k ,top = 0 , x, y;
	scanf("%d %d",&n,&m);
	for (i = 0 ;i< n;i++)
		scanf("%s",d[i]);
	for (i = 0 ;i< n ; i++)
		for (j = 0 ;j< m ;j++)
		{
		 int p = i*m+j;
		  if (d[i][j] == 'B' )

			  s[top++] = p ;
		}

	for (i = 0 ;i< top ;i++)
	{
	  memset(vis,0,sizeof(vis));
	  memset(f,0,sizeof(f));
	   x = s[i]/m ;
	   y = s[i]%m;
	   for (k = 0 ; k<4; k++)
	   {
	     dfs(x,y,k,0);
	   }
	   for (j = i ;j< top ;j++)
	  { int xx = s[j]/m,yy = s[j]%m;
	      if (!f[xx][yy])
		  {     puts("NO");
		     return 0 ;
		  }
	   }
	
	
	}
	puts("YES");
	return 0;   	
}
