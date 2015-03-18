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
using namespace std;
int t ;
char str[1000005];
int hs[360];
int num[100][66];
int sum[100];
int ok[100];
int ans[100];
LL p(int n ,int k)
{
   if(k == 0 )
	   return 1; 
   if(k ==  1)
	   return n ;
   LL tmp = p(n,k/2);
   if(k % 2 == 0 )
	   return tmp * tmp %M;
   return tmp * tmp * n % M;
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
		int len = strlen(str);
		memset(num,0,sizeof(num));
		memset(ok,0,sizeof(ok));
		memset(sum,0,sizeof(sum));
		for(int i = 0;i < len ;i ++)
		{
	        if(num[k][hs[str[i]]] == 0 )
			{
			  sum[k] ++ ; 
			  num[k][hs[str[i]]] = 1; 
			}
			if(sum[k] == k)
			{
			  ans[k] ++ ; 
			  memset(num[k],0,sizeof(num[k]));
			  sum[k]  = 0 ; 
			}
		/*	for(int j = 0 ;j < k ;j ++)
			{
			    if(ok[j] == 0)
					continue;
				if(num[j][hs[str[i]]] == 0 )
				{
					sum[j] ++ ; 
					num[j][hs[str[i]]] = 1; 
				}
				if(sum[j] == k)
				{
					ans[j] ++ ;
					printf("***\n");
					memset(num[j],0,sizeof(num[j]));
					sum[j] = 0 ; 
				}
			}
			ok[hs[str[i]]] = 1;*/
		}
		if(ans[k] == 0)
	    {
		  printf("%d %d\n",ans[k]+1,k - sum[k]);
		  continue;
		}
		LL rans = 0 ;
		rans = p(k,ans[k])*(k-sum[k])%M;
		printf("%d %lld\n",ans[k]+1,rans);
	}
return 0;
}
