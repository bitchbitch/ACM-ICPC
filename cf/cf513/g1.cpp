// File Name: g1.cpp
// Author: darkdream
// Created Time: 2015年02月08日 星期日 02时23分44秒

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
int a[666666];
int b[666666];
double per[666666];
int tmp[8];
int n , k ;
int  count()
{
  int sum = 0 ; 
  for(int i = 1;i <= n;i ++)
  {
    for(int j = 1;j < i ;j ++)
	{
	  if(tmp[j] > tmp[i])
	  {
	    sum++ ; 
	  }
	}
  }
  //printf("%d\n",sum);
  return sum;  
}
int change()
{
   int ans = 0 ; 
   for(int i= 1;i <= n;i ++)
   {
     ans = ans * 10 + tmp[i];
   }
   return ans;
}
void init()
{
   for(int i = 1;i <= n;i ++)
	   tmp[i] = i ; 
   do{
	 int x = change(); 
     b[x] = count();
   }while(next_permutation(tmp+1,tmp+1+n));
}
void fan(int i , int j)
{
  for(int s = i ;s <= (i+j)/2;  s ++)
  {
      swap(tmp[s],tmp[j-(s-i)]);
  }
}
double rans = 0 ; 
void dfs(int x)
{
   if(x == 0)
   {
      int tt = change();
	 // printf("%d %d\n",tt,b[tt]);
	  rans +=b[tt]*pow(2.0/((n+1)*n),k);
      return ;
   }
   for(int i= 1;i <= n;i ++)
	   for(int j = i;j <= n;j ++)
	   {
	      fan(i,j);
		  dfs(x-1);
		  fan(i,j);
	   }
}
int main(){
   scanf("%d %d",&n,&k);
   init();
   memset(per,0,sizeof(per));
   for(int i = 1;i <= n;i ++)
	   scanf("%d",&tmp[i]);
   dfs(k);
   printf("%.9f\n",rans);
return 0;
}
