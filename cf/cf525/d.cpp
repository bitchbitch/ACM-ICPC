// File Name: d.cpp
// Author: darkdream
// Created Time: 2015年03月27日 星期五 16时05分31秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#define LL long long

using namespace std;
int n ,m ;
char mp[2005][2005];
bool vis[2005][2005];
struct  node{
	int x, y;
	node(){}
	node(int _x, int _y)
	{
		x = _x; 
		y = _y ;
	}
}tmp;
int lx, ly ,rx,ry;
int xadd[] = {0,0,1,-1};
int yadd[] = {1,-1,0,0};
queue<node>qu;
void bfs(int x,int y)
{
      qu.push(node(x,y));
      int tx,ty;
	  while(!qu.empty())
	  {
	     tmp = qu.front();
         qu.pop();
		 if(mp[tmp.x][tmp.y] != '.')
			 continue;
		 if(mp[tmp.x-1][tmp.y] == '.' && mp[tmp.x][tmp.y+1] =='.' && mp[tmp.x-1][tmp.y+1] == '*')
		 {
		   tx = tmp.x -1;
		   ty = tmp.y +1; 
		   mp[tx][ty] = '.';
		   qu.push(node(tx,ty));
		   for(int i = 0 ;i <= 3 ;i ++)
	           qu.push(node(tx+xadd[i],ty+yadd[i]))	;   
		 }
		 if(mp[tmp.x-1][tmp.y] == '.' && mp[tmp.x][tmp.y-1] =='.' && mp[tmp.x-1][tmp.y-1] == '*')
		 {
		   tx = tmp.x -1;
		   ty = tmp.y -1; 
		   mp[tx][ty] = '.';
		   qu.push(node(tx,ty));
		   for(int i = 0 ;i <= 3 ;i ++)
	           qu.push(node(tx+xadd[i],ty+yadd[i]))	;   
		 }
		 if(mp[tmp.x+1][tmp.y] == '.' && mp[tmp.x][tmp.y+1] =='.' && mp[tmp.x+1][tmp.y+1] == '*')
		 {
		   tx = tmp.x +1;
		   ty = tmp.y +1; 
		   mp[tx][ty] = '.';
		   qu.push(node(tx,ty));
		   for(int i = 0 ;i <= 3 ;i ++)
	           qu.push(node(tx+xadd[i],ty+yadd[i]))	;   
		 }
		 if(mp[tmp.x+1][tmp.y] == '.' && mp[tmp.x][tmp.y-1] =='.' && mp[tmp.x+1][tmp.y-1] == '*')
		 {
		   tx = tmp.x +1;
		   ty = tmp.y -1; 
		   mp[tx][ty] = '.';
		   qu.push(node(tx,ty));
		   for(int i = 0 ;i <= 3 ;i ++)
	           qu.push(node(tx+xadd[i],ty+yadd[i]))	;   
		 }
	  }
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%s",&mp[i][1]);        
	}
	for(int i = 1 ;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			if( mp[i][j] == '.')
			{
				bfs(i,j);
			}
		}
	}
	for(int i = 1;i <= n;i ++)
		puts(&mp[i][1]);
	return 0;
}
