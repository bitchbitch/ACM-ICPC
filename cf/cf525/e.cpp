// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年03月27日 星期五 01时21分34秒

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
int n ,m ;
LL s ; 
LL a[100];
map<LL,LL> mp[50][50][50];
map<LL,LL>::iterator  tt;
LL b[100];
int main(){
    scanf("%d %d %I64d",&n,&m,&s);
	mp[0][0][0][0] = 1;  
	for(int i = 1;i <= n ;i ++)
	{
        scanf("%I64d",&a[i]);
		if(a[i] <= 18 )
		{
			b[i]  = 1; 
			for(int j =1 ;j <= a[i]; j ++)
			{
				b[i]*= j ;
			}
		}
		for(int j = 0;j <= n;j ++)
		{
		   for(int k = 0 ;k  <= m ;k ++)
		   {
		        for(tt = mp[i-1][j][k].begin();tt != mp[i-1][j][k].end(); tt++)
				{
				   if(tt->first +a[i] <=  s)
				       mp[i][j+1][k][tt->first + a[i]] += tt->second;
				   mp[i][j][k][tt->first] += tt->second;
				   if(a[i] <= 18 && tt->first +b[i] <= s)
					   mp[i][j+1][k+1][tt->first + b[i]] += tt->second;
				}
		   }
		}
	}
	LL sum = 0 ; 
	for(int j = 0 ;j <= n;j ++)
	{
	   for(int k = 0 ;k <= m ;k ++)
	   {
	      if(mp[n][j][k].find(s) != mp[n][j][k].end())
		  {
		    sum += mp[n][j][k][s];
		  }
	   }
	}
	printf("%I64d\n",sum);
return 0;
}
