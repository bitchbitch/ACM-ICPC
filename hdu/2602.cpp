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
int dp[1005];
struct node{
  int w, v;
}List[1006];
int main(){
   int T; 
   scanf("%d",&T);
   while(T--)
   {
     int n ,v;
	 scanf("%d %d",&n,&v);
	 memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;i ++)
	  scanf("%d",&List[i].v);
	for(int i = 1;i <= n;i ++)
	  scanf("%d",&List[i].w);
	for(int i = 1;i <= n;i ++)
	{
	   for(int j = v; j >= 0 ;j --)
	   {
	      if(j + List[i].w <= v)
			  dp[j+List[i].w] = max(dp[j+List[i].w],dp[j] + List[i].v);
	   }
	 }
	 printf("%d\n",dp[v]);
   }
return 0;
}
