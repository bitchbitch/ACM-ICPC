// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年09月18日 星期四 23时36分10秒

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
int a[10005];
int n , m , k ; 
int isok(int x)
{
	int t = 0 ; 
	while(x)
	{
		if(x & 1)
		{
			t++ ;
		}
		x >>= 1;
	}
	if(t <= k )
		return 1;
	return 0 ; 
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i =1 ;i <= m+1;i ++)
	{
		scanf("%d",&a[i]);
	}
	int num = (1 << n)-1;
	int sum = 0 ;
	for(int j = 1;j <= m;j ++ )
	{
		int temp = a[m+1]^a[j];
		if(isok(temp))
			sum ++;
	}

printf("%d\n",sum);
return 0;
}
