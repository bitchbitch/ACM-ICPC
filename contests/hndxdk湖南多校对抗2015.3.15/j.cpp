// File Name: j.cpp
// Author: darkdream
// Created Time: 2015年03月18日 星期三 18时57分57秒

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
#define maxn 1000005
using namespace std;
int t ;
char str[maxn];
int nxt[maxn][66];
int dp1[maxn];
LL dp2[maxn];
int hs[360];
int num[66];
int pk[maxn];
int sum;
int ans;
LL p(int n ,int k)
{
   pk[0] = 1;
   for(int i = 1; i <=  k;i ++)
	   pk[i] = (pk[i-1] *n )% M;
}
int main(){
    scanf("%d",&t);
	for(int i = 'a' ;i <= 'z' ;i ++)
	{
	   hs[i] = i - 'a';
	}
	for(int i = 'A' ;i <= 'B' ;i ++)
	{
	   hs[i] = i -'A'+ 26;
	}
	for(int i = '0';i <= '9' ;i ++)
	{
	   hs[i] = i - '0' +52;
	}
	while(t--)
	{
        int k; 
		scanf("%d",&k);
		scanf("%s",str);
		ans = 0;
		sum = 0;
		int len = strlen(str);
		p(k,len);
		for(int i = 0;i < len ;i ++)
		{
			if(i > 0)
			for(int j = 0 ; j < k ;j ++)
				nxt[i][j] = nxt[i-1][j];
	        if(num[hs[str[i]]] == 0 )
			{
			  sum ++ ; 
			  num[hs[str[i]]] = 1; 
			}
			if(sum == k)
			{
			  ans ++ ; 
			  memset(num,0,sizeof(num));
			  sum  = 0 ; 
			}
			dp1[i] = ans +1;
			dp2[i] = 0 ; 
			if(ans == 0 ){
			     for(int j = 0 ;j < k;j ++){
				   int tt = nxt[i][j];
				   dp2[i]++;
				 }
			}else{
		        for(int j = 0 ;j < k;j ++)
				{
				   int tt = nxt[i][j];
				   if(dp1[tt] == ans)
					   dp2[i] = (dp2[i]+dp2[tt])%M;
				   else{
				       dp2[i] = (dp2[i] + pk[ans])%M;
				   } 

				}
			}
			nxt[i][hs[str[i]]] = i;
		}
		LL rans = (pk[dp1[len-1]] + M - dp2[len-1])%M;
		printf("%d %lld\n",dp1[len-1],rans);

	}
return 0;
}
