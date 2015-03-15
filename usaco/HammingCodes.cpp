// File Name: HammingCodes.cpp
// Author: darkdream
// Created Time: 2013年11月24日 星期日 16时02分43秒
/*
ID: dream.y1
PROG: hamming
LANG: C++
*/
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

int sum = 0 ; 
int ans[100][10];
int temp[10];
int n, b,d;
int solve( )
{
  for(int i = 1;i<= sum;i ++)
  {
	int tsum = 0 ;
    for(int j =1; j <= b;j ++)
	{
		if(temp[j]^ans[i][j])
			tsum ++;
	}
	if(tsum < d)
	  return  0;
  }
  return 1;
}

int main(){
	freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
	sum ++; 
	int limit = 1;
	scanf("%d %d %d",&n,&b,&d);
	limit = 1;
	limit = 1 << b;
	memset(ans,0,sizeof(ans));

		for(int i =1 ;i <= limit;i ++ )
		{
			int k = i ;
			for(int j =1 ;j <= b ;j ++)
			{
				if(k % 2 ==1 )
					temp[j] = 1; 
				else temp[j] = 0 ;
				k = k/2; 
			}
			if(solve())
			{
				 sum ++;
				 ans[sum][0] = i ;
			     for(int j = 1; j <= b; j ++)
				 {
				   ans[sum][j] = temp[j];
				 }
			}
			if(sum == n)
				break;

		}
		for(int i = 1;i <= n;i ++)
		{	
			printf(i%10 == 1?"%d":" %d",ans[i][0]);
		    if(i % 10 == 0 )
				printf("\n");
		}
		if(n % 10 != 0)
		printf("\n");
	return 0;
}
