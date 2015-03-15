// File Name: g.cpp
// Author: darkdream
// Created Time: 2014年10月03日 星期五 09时04分49秒

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
char str[300][10];
int  n; 

void solve(int k )
{
	 if(str[k][0] !='?' )
	 {
		  printf("%s\n",str[k]);
	      return ; 
	 }
	int  l = 0 ; 
	int  r = 0 ;
	int i, j ;
    for(i = k-1 ;i >= 1; i --)
	{
	  if(str[i][0] == '?')
	  {
	    l ++ ; 
	  }else  break;
	}
	if(i == 0 )
		l = 1e9;
    for( j = k+1 ;j <= n; j ++)
	{
	  if(str[j][0] == '?')
	  {
	    r ++ ; 
	  }else  break;
	}
	if(j == n +1)
		r = 1e9;
	if(l == r)
	{
	  printf("middle of %s and %s\n",str[i],str[j]);
	}else if(r >  l)
	{
	  for(int s = 1;s <= l+1;s ++)
		  printf("right of ");
	  printf("%s\n",str[i]);
	}else {
	  for(int s = 1;s <= r+1;s ++)
		  printf("left of ");
	  printf("%s\n",str[j]);
	}
}
int main(){
  scanf("%d",&n);
  for(int i = 1;i <= n;i ++)
  {
	  scanf("%s",str[i]);
  }
  int m ;
  scanf("%d",&m);
  for(int i = 1 ;i <=m;i ++)
  {
    int q; 
	scanf("%d",&q);
    solve(q);
  }
return 0;
}
