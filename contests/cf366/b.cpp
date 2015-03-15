// File Name: b.cpp
// Author: darkdream
// Created Time: 2013年11月24日 星期日 23时23分24秒

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

using namespace std;

int ans[100005];
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
  int n , k ; 
  int temp;
  scanf("%d %d",&n,&k);
  memset(ans,0,sizeof(ans));
  for(int i = 1;i <= n;i ++ )
  {
      scanf("%d",&temp);
	  ans[i%k] += temp;
  }
  int minnum = 1000000000;
  int h;
  for(int i = 1 ;i < k;i ++)
  {
     if(ans[i] < minnum)
	 {
	   minnum = ans[i];
	   h = i ;
	 }
  }
  if(ans[0] < minnum)
  {
    minnum = ans[0];
	h = 0 ; 
  }
  
  //printf("%d %d\n",ans[0],ans[1]);
  if(h == 0 )
	  printf("%d\n",k);
  else printf("%d\n",h);

return 0;
}
