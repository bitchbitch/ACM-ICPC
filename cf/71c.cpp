// File Name: 71c.cpp
// Author: darkdream
// Created Time: 2015年03月20日 星期五 21时45分50秒

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
#define maxn 100001
using namespace std;
int a[100005];
int hs[100005];
int n;
int tt;
int zyz[10];
int dp[10][100050];
void sai()
{
   int li = sqrt(n)+1;
   for(int i = 2;i <= li ;i ++)
   { 
      if(hs[i] == 0)
	  {
	    int k = i*i ;
		while(k <= n)
		{
		   hs[k] = 1; 
		   k += i ; 
		}
	  }
   }
   hs[4] = 0 ; 
   hs[2] = 1; 
   tt = 0 ; 
   for(int  i = 2;i <= n ;i ++)
   {
     if(hs[i] == 0 && n % i == 0 )
	 {
	   tt ++ ;
	   zyz[tt] = n/i ; 
	 }
   }
}
int main(){
	scanf("%d",&n);
	sai();
	/*for(int i = 1;i <= tt; i ++)
		printf("%d ",zyz[i]);
	printf("\n");*/
	int tmp ; 
	for(int i = 1;i <= n;i ++)
	{
	   scanf("%d",&tmp);
	   if(tmp == 0 )
	   {
	   for(int j = 1; j <= tt; j++)
	   {
	       dp[j][i%zyz[j]] = 1;
	   }
	   }
	}
	for(int i = 1;i <= tt;i ++)
	{
	  for(int j =0 ;j < zyz[i];j ++)
		  if(dp[i][j] == 0)
		  {
		    printf("YES\n");
			return 0 ; 
		  }
	}
	printf("NO\n");
return 0;
}
