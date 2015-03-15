// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年02月03日 星期二 00时26分41秒

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
char str[105][105];
int mp[100][100];
int ru[100];
int chu[100];
int vis[100];
char ans[100]; 
int be = 0 ;
int dfs(int k )
{
	int ok = 1;
	chu[k] = 0 ; 
	for(int i = 0 ;i <= 30;i ++)
	{
		if(mp[k][i] == 1)
		{
			if(!vis[i])
			{
				ru[i] -- ; 
			}else{
				ok = ok & 0 ; 
			}
		}
	}
	return ok ; 
}
int count()
{
	int ok = 0 ; 
	for(int i = 0 ;i <= 26 ;i ++)
	{
		if(chu[i] || ru[i])
			ok  = 1 ; 
		if(chu[i] != 0 && ru[i] == 0)
		{
			return i ; 
		}
	}
	if(ok)
		return -1;
	else return -2;
}
int main(){
	int n; 
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%s",str[i]);
	}
	for(int i = 2;i <= n;i ++)
	{

		for(int j = 1 ;j < i ;j ++ )
		{
			int len = min(strlen(str[i]),strlen(str[j])) ;
			for(int s = 0 ; s < len ;s ++)
			{
				if(str[i][s] != str[j][s])
				{
					if(mp[str[j][s]-'a'][str[i][s]-'a'] != 1)
					{
						ru[str[i][s] - 'a'] ++;
						chu[str[j][s] - 'a'] ++;
						mp[str[j][s] -'a'][str[i][s] -'a'] ++; 
					}
					break;
				}
			}
		}
	}
	while(1)
	{
		int k = count();
		if(k == -1)
		{
			printf("Impossible\n");
			return  0;
		}else if(k == -2)
		{
			break; 
		}
		if(vis[k])
		{
			printf("Impossible\n");
			return 0;
		}
		vis[k] = 1; 
		ans[be] = k +'a';
		be ++ ;
		int tmp = dfs(k);
		if(tmp == 0 )
		{
			printf("Impossible\n");
			return 0 ;
		}
	}
	for(int i = 0 ;i < 26;i ++)
	{
		if(vis[i] == 0 )
		{
			ans[be] = i + 'a';
			be ++ ; 
		}
	}
	printf("%s\n",ans);
	return 0;
}
