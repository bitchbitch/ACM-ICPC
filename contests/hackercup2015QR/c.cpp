// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年01月10日 星期六 20时10分04秒

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
int mp[5][105][105];
int bex , bey ; 
int enx,  eny ;
int n , m; 
int vis[105][105][105];
void fillmap(int k )
{
    for(int i = 1;i <= n;i ++)
	{
	   for(int j = 1;j <= m ;j ++)
	   {
	      if(mp[k][i][j]  == 2) 
		  {
		    int x = i + 1; 
			while(mp[k][x][j] == 1 || mp[k][x][j] == -1)
			{
		       	mp[k][x][j] = -1;
				x ++ ; 
			}
		  } else if(mp[k][i][j] == 3)
		  {
		    int x = i - 1; 
			while(mp[k][x][j] == 1 || mp[k][x][j] == -1)
			{
		       	mp[k][x][j] = -1;
				x -- ; 
			}
		  } else if(mp[k][i][j] == 4)
		  {
		    int x = j + 1; 
			while(mp[k][i][x] == 1 || mp[k][i][x] == -1)
			{
		       	mp[k][i][x] = -1;
				x ++; 
			}
		  }else if(mp[k][i][j] == 5)
		  {
		     int x = j -1; 
			 while(mp[k][i][x] == 1 || mp[k][i][x] == -1)
			 {
				mp[k][i][x] = -1;
			    x --;
			 }
		  }
	   }
	}
}
void print(int k )
{
   for(int i = 1;i <= n;i ++)
   {
       for(int j = 1;j <= m ;j ++)
	   {
	      printf("%d ",mp[k][i][j]);
	   }
	   printf("\n");
   }
   printf("\n");
}
void changeto(int k )
{
    for(int i = 1;i <= n;i ++)
	{
       for(int j = 1;j <= m;j ++)
	   {
           if(mp[k-1][i][j] == 0)	
		       mp[k][i][j] == 0;
		   else if(mp[k-1][i][j] == 1)
			   mp[k][i][j] = 1;
		   else if(mp[k-1][i][j] == 2)
		       mp[k][i][j] = 5;
		   else if(mp[k-1][i][j] == 3)
		       mp[k][i][j] = 4;
		   else if(mp[k-1][i][j] == 4)
		       mp[k][i][j] = 2;
		   else if(mp[k-1][i][j] == 5)
		       mp[k][i][j] = 3;
		   else if(mp[k-1][i][j] == -1)
			   mp[k][i][j] = 1;
	   }
	}
	fillmap(k);
	//print(k);
}
struct node{
  int x,y,step,flag;
  node(){
  
  }
  node(int _x ,int _y ,int _step ,int _flag)
  {
     x = _x; 
	 y = _y;
	 step = _step;
	 flag = _flag; 
  }
}qu[101000];
int xadd[] = {1,-1,0,0};
int yadd[] = {0,0,-1,1};
int bfs()
{
    memset(vis,0,sizeof(vis));
    qu[1] = node(bex,bey,0,0);
	vis[0][bex][bey] = 1; 
	int l = 1; 
	int r = 1;
    while(l <= r)
	{
	  // printf("%d %d\n",qu[l].x,qu[l].y);
       if(qu[l].x == enx && qu[l].y == eny)
	   {
	         return  qu[l].step;
	   }
	   int k = (qu[l].flag + 1)%4; 
	   for(int i = 0;i <= 3; i ++)
	   {
	       int tx = qu[l].x + xadd[i];
		   int ty = qu[l].y + yadd[i];
		   if(mp[k][tx][ty] == 1 &&  vis[k][tx][ty] != 1)
		   {
		      vis[k][tx][ty] = 1;
			  r ++ ; 
			  qu[r] = node(tx,ty,qu[l].step + 1, k);
		   }
	   }
	   l ++ ; 
    }	
	return 0 ;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ca ++)
	{
	   scanf("%d %d",&n,&m);
	   char str[1000];
	   memset(mp,0,sizeof(mp));
	   for(int i = 1;i <= n;i ++)
	   {
	      scanf("%s",&str[1]);
          for(int j = 1;j <= m;j ++)
		  {
		      if(str[j] == 'S') 
			  {
			      bex = i ; 
				  bey = j ; 
			      mp[0][i][j] = 1;
			  }else if(str[j] == 'G')
			  {
			      mp[0][i][j] = 1;
				  enx = i ; 
				  eny = j;
			  }else if(str[j] == '#')
			  {
			      mp[0][i][j] = 0 ; 
			  }else if(str[j] ==  '.')
				  mp[0][i][j] = 1 ;
			  else if(str[j] == 'v')
			      mp[0][i][j] = 2; 
			  else if(str[j] == '^')
				  mp[0][i][j] =3;
			  else if(str[j] == '>')
				  mp[0][i][j] =4 ; 
			  else if(str[j] == '<')
				  mp[0][i][j] =5;
		  }
	   }
	      
		  fillmap(0);
		  changeto(1);
		  changeto(2);
		  changeto(3);
		  //for(int i = 0 ;i <= 3;i ++ )
			//  print(i);
		  int ok = bfs();
		  printf("Case #%d: ",ca);
		  if(ok == 0 )
			  printf("impossible\n");
		  else printf("%d\n",ok);
	}
return 0;
}
