// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年02月18日 星期三 01时06分26秒

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
#include<queue>
#define LL long long

using namespace std;
char str[2004][2004];
struct node{
  int x, y ; 
  node()
  {}
  node(int _x,int _y)
  {
     x= _x; 
	 y= _y;
  }
};
queue <node> q3;
void cheack(int x, int y)
{
   if(str[x][y] == '.' )
   {
      int sum = 0 ; 
	  if(str[x][y+1] == '.')
       sum ++;
	  if(str[x][y-1] == '.')
       sum ++;
	  if(str[x+1][y] == '.')
       sum ++;
	  if(str[x-1][y] == '.')
       sum ++;
      if(sum == 1) 
		  q3.push(node(x,y));
   }
}
void cheackaround(int x, int y)
{
   cheack(x,y-1);
   cheack(x,y+1);
   cheack(x+1,y);
   cheack(x-1,y);
}
void solve()
{
    while(q3.size() != 0 )
    {
      node tmp = q3.front();
	  q3.pop();
	  int x = tmp.x;
	  int y = tmp.y;
	  if(str[x][y+1] == '.')
	  {
	     str[x][y] = '<';
		 str[x][y+1] = '>';
		 cheackaround(x,y+1);
	  }
	  if(str[x][y-1] == '.')
	  {
	    str[x][y] = '>';
		str[x][y-1] = '<';
		cheackaround(x,y-1);
	  }
	  if(str[x+1][y] == '.')
	  {
	    str[x][y] = '^';
		str[x+1][y] = 'v';
		cheackaround(x+1,y);
	  }
	  if(str[x-1][y] == '.')
	  {
	    str[x][y] = 'v';
		str[x-1][y] = '^';
		cheackaround(x-1,y);
	  }
	}
}
int main(){
   int n , m; 
   scanf("%d %d",&n,&m);
   for(int i = 1;i <= n;i ++)
   {
     scanf("%s",&str[i][1]);
   }
   for(int i = 1;i <= n;i ++)
	   for(int j = 1;j <= m;j ++)
	   {
		  cheack(i,j);	
	   }
   solve();
   for(int i = 1;i <= n;i ++)
	   for(int j= 1;j <= m; j ++)
	   {
	     if(str[i][j] == '.')
		 {
		   printf("Not unique\n");
		   return 0 ; 
		 }
	   }
   for(int i = 1;i <= n;i ++)
	   printf("%s\n",&str[i][1]);

return 0;
}
