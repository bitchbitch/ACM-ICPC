// File Name: uva12510.cpp
// Author: darkdream
// Created Time: 2014年10月08日 星期三 19时13分59秒

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
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long

using namespace std;
int mp[12][12];
int vis[12][12];
int xadd[] = {1,-1,0,0};
int yadd[] = {0,0,1,-1};
struct node
{
   int x;int y;
   int is;
   node(int _x, int _y, int _is)
   {
	    x = _x; 
		y = _y;
		is = 0; 
   }
};
vector<node> C;
int mx = 0;
int ansnum = 0 ; 
int n , m ;
void debug()
{
  for(int i = 1;i <= n;i ++)
  {
      for(int j = 1;j <= m;j ++)
		  printf("%d ",mp[i][j]);
	  printf("\n");
  }
}
void bfs(int x, int y ,int ans)
{
   if(mx == ansnum)
	   return;
   vector<node> Q;
   Q.push_back(node(x,y,0));
   vis[x][y] = 1; 
   int l = 0; 
   int r = 0;
   while(l <= r )
   {
     for(int i = 0 ;i <= 3;i ++)
	 {
	   int tx = Q[l].x + xadd[i] ;
	   int ty = Q[l].y + yadd[i] ;
       if(mp[tx][ty] >= 1 && !vis[tx][ty])
	   {
	     vis[tx][ty] = 1;
		 r ++ ;
		 if(mp[tx][ty] == 2)
		 {
		    Q.push_back(node(tx,ty,1));
		    ans ++ ; 
		 }
		 else Q.push_back(node(tx,ty,0));
	   }
	 }
	 l ++ ; 
   }
   if(ans > mx)
	   mx = ans; 
   for(int i = 0;i < C.size();i ++)
     {
	     if(!C[i].is)
		 {
		    for(int s = 0 ;s <= 3;s ++)
			{
			   int tx = C[i].x + xadd[s];
			   int ty = C[i].y + yadd[s];
			   int ttx = C[i].x - xadd[s];
			   int tty = C[i].y - yadd[s];
			   //printf("%d %d %d %d\n",tx,ty,ttx,tty);
			   if(mp[tx][ty] == 1 && vis[ttx][tty] == 1)
			   {
			       mp[tx][ty] = -1;
				   mp[C[i].x][C[i].y] = 1;
				   C[i].is = 1; 
                   bfs(C[i].x,C[i].y,ans);
			       mp[tx][ty] = 1;
				   mp[C[i].x][C[i].y] = 0;
				   C[i].is = 0 ; 
			   }
			}
		 }
	 }
  for(int i = r; i >= 0 ;i --)
  {
      vis[Q[i].x][Q[i].y] = 0  ;
	  if(Q[i].is)
	  {
         mp[Q[i].x][Q[i].y] = 2  ;
	  }
  }
}
int main(){
    int t ; 
	scanf("%d",&t);
	while(t--)
	{
	     memset(mp,-1,sizeof(mp));
         memset(vis,0,sizeof(vis));
		 scanf("%d %d",&n,&m);
		 char str[20];
		 int bex, bey ;
		 ansnum =0 ; 
		 C.clear();
		 for(int i = 1 ;i <= n;i ++)
		 {
             scanf("%s",&str[1]);
			 for(int j = 1;j <= m; j ++)
			 {
			   if(str[j] == 'S')
			   {
			     mp[i][j] = 1 ; 
				 bex = i ; 
				 bey = j ; 
			   }else if(str[j] == 'C')
			   {
				 ansnum ++;
			     mp[i][j] = 2; 
			   }else if(str[j] == 'X')
			   {
			     mp[i][j] = -1; 
			   }else if (str[j] == 'O'){
			     mp[i][j] = 0 ;
				 C.push_back(node(i,j,0));
			   }else {
			     mp[i][j] = 1; 
			   }
			 }
		 }
		 mx = 0 ; 
		 bfs(bex,bey,0);
		 printf("%d\n",mx);
	}
	
	return 0;
}
