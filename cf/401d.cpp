// File Name: 401d.cpp
// Author: darkdream
// Created Time: 2015年03月23日 星期一 21时00分39秒

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
LL  n, m ; 
int mp[100][100];
int solve(int x1,int y1,int x2,int y2)
{
   return mp[x2][y2] - mp[x1-1][y2] - mp[x2][y1-1] + mp[x1-1][y1-1];  
}
int main(){
  int n , m ;
  scanf("%d %d",&n,&m);
  for(int i = 1;i <= n;i ++)
  {
	 int tmp = 0 ; 
     for(int j= 1;j <= m; j ++)
	 {
	    scanf("%1d",&mp[i][j]);
		if(mp[i][j])
		{
		  tmp ++ ; 
		}
		mp[i][j] = mp[i-1][j] + tmp ;
	 }
  }
  int mx =0 ; 
  for(int i= 1;i<= n;i ++)
  {
    for(int j= 1;j <= m;j ++)
	{  	
	   for(int ij = i;ij <= n;ij ++)
	   {
	     for(int ji = j ;ji <= m;ji ++)
	     {
		     if(solve(i,j,ij,ji) == 0 )
			 {
			    mx =  max(mx,(ij - i +1)* 2 + (ji -j + 1 )*2)    ;
			 }
		 }
	   }
	}
  }
  printf("%d\n",mx);
  return 0;
}
