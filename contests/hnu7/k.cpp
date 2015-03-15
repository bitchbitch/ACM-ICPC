// File Name: k.cpp
// Author: darkdream
// Created Time: 2014年08月10日 星期日 16时31分20秒

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
int n,m;
int hs[30];
int nv[30];
char str[200][200];
struct node{
	int x, y ; 
}site[30][10000];
int nums[30];
int xadd[] = {1,-1,0,0};
int yadd[] = {0,0,-1,1};
int visit[200][200];
int sum = 0;
void dfs(int x , int y)
{
	//printf("%d %d %c\n",x,y,str[x][y]);
	for(int i = 0  ;i <= 3;i ++)
	{
		int tx = x + xadd[i];
		int ty = y + yadd[i];
		if(!visit[tx][ty])
		{
			if(str[tx][ty] =='$') 
			{
				sum ++ ;
				visit[tx][ty] = 1;
				dfs(tx,ty);
			}
			else if(str[tx][ty]  == '.')
			{
				visit[tx][ty] = 1; 
				dfs(tx,ty);
			}else if(str[tx][ty] <= 'z' && str[tx][ty]>= 'a')
			{
			//	printf("%c\n",str[tx][ty]);
				hs[str[tx][ty] - 'a'] = 1; 
				visit[tx][ty] =1 ; 
				dfs(tx,ty);
			}else if(str[tx][ty] <= 'Z' && str[tx][ty] >= 'A')
			{
            //    printf("%d %d %c\n",tx,ty,str[tx][ty]);
				if(hs[str[tx][ty] - 'A'])
				{
					visit[tx][ty] = 1; 
					dfs(tx,ty);
				}else{
					nv[str[tx][ty] - 'A'] ++; 
					site[str[tx][ty] - 'A'][nv[str[tx][ty]-'A']].x = tx; 
					site[str[tx][ty] - 'A'][nv[str[tx][ty]-'A']].y = ty; 
				}
			}
		}
	}
}
int main(){
	scanf("%d",&t);
	while(t--)
	{
		memset(visit,0,sizeof(visit));
		sum = 0 ; 
		memset(str,0,sizeof(str));
		memset(hs,0,sizeof(hs));
		memset(nv,0,sizeof(nv));
		scanf("%d %d",&n,&m); 
		for(int i = 1;i <= n;i ++)
		{
			scanf("%s",&str[i+1][2]);
		}
		char temp[200] ; 
		scanf("%s",temp);
		int ltemp = strlen(temp);
		if(temp[0] != '0')
			for(int i = 0 ;i < ltemp ;i ++)
			{
				hs[temp[i] - 'a'] = 1; 
			}
		for(int i = 1;i <= n + 2 ; i++)
			str[i][1] = str[i][m+2] = '.';
		for(int i = 1;i <= m + 2 ;i ++ )
			str[1][i] = str[n+2][i] = '.';
		visit[1][1] = 1 ; 
		dfs(1,1);
		int ok  = 0 ; 
		do{
			ok = 0 ; 
			for(int i = 0 ;i <= 26;i ++)
			{
				if(hs[i] && nv[i])
				{
					//printf("%d\n",i);
					ok = 1;
					visit[site[i][nv[i]].x][site[i][nv[i]].y] = 1; 
					dfs(site[i][nv[i]].x,site[i][nv[i]].y);
					nv[i]--;
				}
			}
		}while(ok);
		printf("%d\n",sum);
	}
	return 0;
}
