// File Name: test.cpp
// Author: darkdream
// Created Time: 2014年08月01日 星期五 15时55分59秒

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
//int t; 
int hs[505][2];
int main(){
	int n ; 
	while(1)
	{
		memset(hs,0,sizeof(hs));
		scanf("%d",&n);
		for(int i = 0;i < n ;i ++)
			for(int j = 0;j < n ;j ++)
			{
				int x = i* j /n ;
				hs[x][1] ++ ; 
				hs[i*j%n][0]++
			}
		for(int i = 0 ;i < n;i ++)
			printf("%d\n",hs[i]);
	}
	return 0 ; 
}
