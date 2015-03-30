// File Name: 245h.cpp
// Author: darkdream
// Created Time: 2015年03月30日 星期一 11时09分19秒

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
char  str[6000];
map<int ,int >dpj[5005];
map<int ,int >dpo[5005];
map<int ,int >::iterator tp;
struct qu{
 int l , r,si; 
}a[1000005];
int ans[1000005];
int q, n ; 
int cmp(qu a, qu b)
{
  return a.l > b.l ;
}
int tree[6005];
int lowbit(int x)
{
  return x & -x;
}
void update(int x)
{
   while(x <= n)
   {
      tree[x] += 1; 
	  x += lowbit(x);
   }
}
int getsum(int r)
{
  int ans  = 0 ; 
  while(r >= 1)
  {
     ans += tree[r];
	 r -= lowbit(r);
  }
  return ans;
}
inline void read_int(int &ret){
   char ch = getchar();
   while(!isdigit(ch)){
     ch = getchar();
   }
   ret =0 ; 
   while(isdigit(ch)){
      ret = ret*10 + ch -'0' ;
	  ch = getchar();
   }
}
int main(){
 //   freopen("input","r",stdin);
//	freopen("output","w",stdout);
	clock_t be ,en ;
	be = clock();
	scanf("%s",&str[1]);
	 scanf("%d",&q);
	 for(int i = 1;i <=q ;i ++)
	 {
		 read_int(a[i].l);
		 read_int(a[i].r);
		 a[i].si = i ; 
	 }
	 sort(a+1,a+1+q,cmp);
     n = strlen(&str[1]);
	 int tt = 1;  
	 for(int i = n;i >= 1;i --)
	 {
	    dpj[i][1] = i;
		update(i);
		if(str[i] == str[i+1])
		{
		  dpo[i][2] = i+1;
		  update(i+1);
		}
        for(tp = dpj[i+1].begin() ; tp != dpj[i+1].end();tp++)
		{
		   if(str[i] == str[tp->second +1])
		   {
		       dpj[i][tp->first+2] = tp->second +1;
			   update(tp->second+1);
		   }
		}
        for(tp = dpo[i+1].begin() ; tp != dpo[i+1].end();tp++)
		{
		   if(str[i] == str[tp->second +1])
		   {
		       dpo[i][tp->first+2] = tp->second +1;
			   update(tp->second+1);
		   }
		}
		while(a[tt].l == i && tt <= q)
		{
		   ans[a[tt].si] = getsum(a[tt].r);
		   tt++;
		}
		if(tt >q)
			break;
		dpj[i+1].clear();
		dpo[i+1].clear();
	 }
	 for(int i = 1;i <= q; i ++)
		 printf("%d\n",ans[i]);
	 en = clock();
//	 printf("%lf\n",(en -be)*1.0/CLOCKS_PER_SEC);
return 0;
}
