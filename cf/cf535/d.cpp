// File Name: d.cpp
// Author: darkdream
// Created Time: 2015年04月15日 星期三 14时45分20秒

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
#define M 1000000007
using namespace std;
char str[1000005];
int a[1000005];
int next[1000005];
int hs[1000005];
int len ; 
void get_next()
{
	int  k = -1;
	 next[0] = -1;
    int j = 0 ; 
	while(j < len){
		if(k == -1 || str[j] == str[k]){
			++ k ; 
			++ j ;
			next[j] = k ; 
		}else{
			k = next[k];
		}
	}
}
void dfs(int k){
   if(k == 0 )
	   return ;
   hs[len - k + 1] = 1; 
   dfs(next[k]);
}
LL Pow(int k)
{
	if(k < 0)
		return 0;
	LL ans = 1;
	for(int i = 1;i <= k; i ++)
		ans = ans * 26 % M; 
	return ans;
}
int main(){
	int n , m ; 
	scanf("%d %d",&n,&m);
	scanf("%s",str);
	len = strlen(str);
	get_next();
	dfs(next[len]);
	LL ans = 1 ; 
	if(m != 0 )
	{
	scanf("%d",&a[1]);
	ans = Pow(a[1]-1);
	}
	for(int i= 2;i<= m;i++){
		scanf("%d",&a[i]);
		if(a[i] - a[i-1] < len)
		{
			if(hs[a[i]-a[i-1]+1] == 0 )
			{
				printf("0\n");
				return 0 ; 
			}
		}else{
		  ans = ans * Pow(a[i]-a[i-1]-len)%M;
		}
	}
	//printf("%d %I64d\n",n-a[m]-len+1,ans);
	if(m != 0 )
	ans  = ans * Pow(n-a[m]-len + 1) % M;
	else 
		ans = Pow(n);
  //  for(int i= 1;i <= len ;i ++)
	//	printf("%d ",hs[i]);
	printf("%I64d\n",ans);
return 0;
}
