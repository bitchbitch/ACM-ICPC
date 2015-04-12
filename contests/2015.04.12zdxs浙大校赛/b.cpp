// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月12日 星期日 13时51分52秒

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
int t; 
int n;
int a[15];
int notok[][3] ={
	{1,3,2},{3,1,2},{1,7,4},{7,1,4},
	{1,9,5},{9,1,5},{4,6,5},{6,4,5},
	{7,9,8},{9,7,8},{7,3,5},{3,7,5},
	{2,8,5},{8,2,5},{3,9,6},{9,3,6}
};
int vis[15];
int ok()
{
	int visn[15];
	memset(visn,0,sizeof(visn));
	for(int j = 1;j <= n-1;j ++)
	{
		for(int i = 0 ;i <= 15;i ++)
		{
			if(a[j] == notok[i][0] && a[j+1] == notok[i][1] &&visn[notok[i][2]] == 0 )
				return 0 ;
		}
		visn[a[j]] = 1;
	}
	return 1; 
}
int main(){
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d",&a[i]);
			vis[a[i]] = 1; 
		}
		int ans = 0 ; 
		sort(a+1,a+1+n);
		do{
			if(ok())
				ans ++ ; 
		}while(next_permutation(a+1,a+1+n));
		printf("%d\n",ans);
		sort(a+1,a+1+n);
		int tt = 0 ; 
	    do{
			if(ok())
			{
				for(int i = 1;i <= n;i ++)
					printf(i == 1?"%d":" %d",a[i]);
				printf("\n");
				tt ++;
			}
		}while(next_permutation(a+1,a+1+n));
		//printf("%d\n",tt);
		
	}
	return 0;
}
