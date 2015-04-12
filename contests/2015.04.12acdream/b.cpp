// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月12日 星期日 20时03分02秒

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
#include<queue>
#include<ctime>
#define LL long long

using namespace std;
int t; 
vector<int>mp[10005];
int n;
int d,yd;
int dis(double x1,double y1,double x2,double y2)
{
	double ans = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	if(ans <= d )
		return 1; 
	return 0 ; 
}
struct node{
  int x, y;
}p[10005];
int vis[10005];
int ok ; 
struct qunode{
   int num ,step ; 
   qunode(){}
   qunode(int _num,int _step)
   {
       num = _num;
	   step = _step ;
   }
};
int bfs()
{  
	ok = 0 ; 
	queue<qunode> qu;	
	qu.push(qunode(0,0));
	int mians = yd; 
	/*for(int i = 1;i <= n;i ++)
	{
	  for(int j = 0 ;j<mp[i].size();j ++)
		  printf("%d ",mp[i][j]);
	  printf("******\n");
	}*/
	while(!qu.empty())
	{
		qunode tmp = qu.front(); 
		//printf("%d\n",tmp.num);
		qu.pop();
		mians = min(mians,yd-p[tmp.num].y);

		if(tmp.num == n+1)
		{
		   ok =1; 
		   return  tmp.step;
		}
		for(int i = 0 ;i < mp[tmp.num].size(); i ++)
		{
		   if(!vis[mp[tmp.num][i]])
		   {
			  // printf("%d to %d\n",tmp.num,mp[tmp.num][i]);
			  vis[mp[tmp.num][i]] = 1; 
		      qu.push(qunode(mp[tmp.num][i],tmp.step+1));
		   }
		}
	
	}
	return mians;
}
int main(){
	scanf("%d",&t);
	while(t--){
		ok = 0 ; 
		memset(vis,0,sizeof(vis));
	   for(int i = 0;i <= 10000;i ++)
		   mp[i].clear();

       scanf("%d %d %d",&yd,&n,&d);
	   for(int i = 1;i <= n;i ++)
	   {
		   scanf("%d %d",&p[i].x,&p[i].y);
	   }
			 if(yd <= d )
				 mp[0].push_back(n+1);
	   for(int i = 1;i <= n;i ++ )
	   {
		  if(p[i].y <= d)
		  {
		     mp[0].push_back(i);
		  }
		  if(yd - p[i].y <= d)
		  {
		    mp[i].push_back(n+1);
		  }
	      for(int j = i+1;j <= n;j ++)
		  {
			    if(dis(p[i].x,p[i].y,p[j].x,p[j].y))
				{
			       mp[i].push_back(j) ;
				   mp[j].push_back(i);
				}
		  }
	   }
	   int tt = bfs();
	   if(ok)
		   printf("YES\n%d\n",tt);
	   else printf("NO\n%d\n",tt);
	}
return 0;
}
