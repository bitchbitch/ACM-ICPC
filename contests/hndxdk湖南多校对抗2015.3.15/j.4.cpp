// File Name: j.4.cpp
// Author: darkdream
// Created Time: 2015年03月20日 星期五 16时43分43秒

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
#include<climits>
#define LL long long
#define maxn 1000005
#define M 1000000007
using namespace std;
int t, k;
char str[maxn];
int hs[600];
int ok[64];
int nxt[64];
int dp[maxn];
int site[maxn];
int sum[maxn];
int main(){  
	for(int i = 'a' ;i <= 'z' ;i ++)
	{
		hs[i] = i - 'a';
	}
	for(int i = 'A' ;i <= 'Z'; i++)
	{
		hs[i] = i - 'A' + 26; 
	}
	for(int i = '0' ;i <= '9'; i ++)
	{
		hs[i] = i - '0' + 52;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&k,str);
		int len = strlen(str);
		memset(ok,0,sizeof(int)*k);
		sum[0] = 0;
		int wei = 0 ;
		memset(nxt,-1,sizeof(int)*k);
		int twei = 0 ;
		int tt;
		for(int i = len -1;i >= 0 ;--i)
		{
            site[i] = wei;  
			tt = nxt[hs[str[i]]] ;
			if(wei){
				sum[wei] = (sum[wei]+sum[wei-1])%M;
				dp[i] = sum[wei-1];
				if(site[tt] != wei)
				{
				    sum[wei-1] = (sum[wei-1]-dp[tt]+M)%M;
				}else{
				    sum[wei] = (sum[wei]-dp[tt]+M)%M;
				}
			}else{
			    sum[wei] += k-twei;
				dp[i] = k -twei;
				if(tt != -1)
				{
				    sum[wei] -= dp[tt];
				}
			}
			if(ok[hs[str[i]]] == 0)
			{
			  ok[hs[str[i]]] = 1;
			  twei ++ ;
			}
			if(twei == k )	
			{
			  wei ++ ;
			  twei = sum[wei] = 0 ;
			  memset(ok,0,sizeof(int)*k);
			}
			nxt[hs[str[i]]] = i ; 
		}
		if(!wei){
			printf("1 %d\n",k-twei);
		}else{
		    printf("%d %d\n",wei+1,sum[wei-1]);	
		}
	}
return 0;
}
