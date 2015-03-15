// File Name: a.cpp
// Author: darkdream
// Created Time: 2013年04月11日 星期四 19时23分24秒

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
struct p{
 long long  fist,last;
  bool operator < (const p& x) const {
		 return fist + last < x.fist+ x.last;
		 
  }
};
struct p pe[100005];
int main(){
	long long n; 
	freopen("/home/plac/第一场/A客户数量/1.in","r",stdin);
	freopen("/home/plac/第一场/A客户数量/1X.out","w",stdout);
	while(scanf("%lld",&n) != EOF)
	{
	  memset(pe,0,sizeof(pe));
	  for(long long  i = 0;i < n; i ++)
	  {
		  scanf("%lld %lld",&pe[i].fist,&pe[i].last);
          pe[i].last = (pe[i].last-1)*pe[i].last/2;
	  }
	  sort(pe,pe+n);
	  for(int i = 0;i < n; i ++)
	  {
		  //printf("%lld %lld\n",pe[i].fist,pe[i].fist+pe[i].last);
      
	  
	  }
	  long long  sum , k ;
	  sum = 0;
	  k = -1;
	  for(int i = 0 ;i < n; i ++)
	  {
	    if(pe[i].fist >= k)
		{
		   k = pe[i].fist+ pe[i].last ;
		   sum ++;
		}
	  }
	  printf("%lld\n",sum);

	}

return 0;
}
