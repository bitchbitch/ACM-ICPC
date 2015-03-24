// File Name: 509.cpp
// Author: darkdream
// Created Time: 2015年03月24日 星期二 10时01分03秒

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
#define maxn 305
using namespace std;
int a[305];
int ans[405];
int sum[405];
int tmp[405];
int ok(int k ,int n)
{
    if(k ==  0)
		return 1;
    int tl = k /9 ; 
	int tt= (k % 9 ==0 ?0:1);
	if(tl + tt -1 <= n)
	{
	  for(int i = 0 ;i <tl;i ++)
		  tmp[i] = 9 ;
	  tmp[tl] = k % 9;
	  return 1;
	}
	return 0 ; 
}
void solve(int k)
{
    memset(sum,0,sizeof(sum));
    for(int i = 400 ;i >= 0  ;i --)
	{
       sum[i] = sum[i+1]+ ans[i];
	}
	for(int i = 0 ;i <=  400 ;i ++)
	{
	   int t = k - sum[i+1] ;
	   if(ans[i] == 9 || t <= ans[i])
		   continue;
	   for(int  j = ans[i] + 1; j <= 9 ;j ++)
	   {
		   memset(tmp,0,sizeof(tmp));
	       if(ok(t-j,i-1))
		   {
			  for(int s = i +1;s <= 400; s ++)
				  tmp[s] = ans[s];
			  tmp[i] = j; 
		      return ;
		   }
	   }
	}
}
int main(){
   int n ;
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
   {
      scanf("%d",&a[i]);
	  solve(a[i]) ;   
	  int j;
	  for(j = 400; j>= 0 ;j --)
	  {
	    if(tmp[j] != 0)
			break;
	  }
	  for(;j >= 0 ;j --)
		  printf("%d",tmp[j]);
	  printf("\n");
	  memcpy(ans,tmp,sizeof(tmp));
   }
return 0;
}
