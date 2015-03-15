// File Name: 372a.cpp
// Author: darkdream
// Created Time: 2013年12月12日 星期四 12时04分30秒

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
int a[102];
int sum[102] ={0};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i <= n;i ++)
	{  
		scanf("%d",&a[i]);
		sum[i] = sum[i-1] + a[i];
	}		  
	int max = sum[n];
	int ok = 0 ; 
	for(int i = 1;i <= n;i ++)
		for(int j= i;j <= n ;j ++)
		{
			int tsum = sum[n];
			tsum -= sum[j] - sum[i-1];
			tsum += j-i+1 - (sum[j] - sum[i-1]);
			if(tsum >= max)
			{	max = tsum;
			    ok = 1; 
			}
		}
	if(ok == 0 )
		max -= 1;
	printf("%d\n",max);
	return 0;
}
