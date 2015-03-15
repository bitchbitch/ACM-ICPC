// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年09月20日 星期六 21时50分23秒

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
int ve[100005];
int hsa[100005];
int hsb[100005];
int ok[100005];
int  find(int x,int status)
{
	if(ok[x])
		return 1 ;
	if((hsa[x] ||  hsb[x])&& !(hsa[x] && hsb[x]))
	{
		return 0;
	}
	if(status == 1)
	{
		int tt = find(hsa[x],2);
		return tt;
	}
	if(status == 2)
	{
		int tt = find(hsb[x],1);
		return tt;
	}
}
map<int,int> mp;
int main(){
	int n , a, b;
	scanf("%d %d %d",&n,&a,&b);
	memset(hsa,0,sizeof(hsa));
	memset(hsb,0,sizeof(hsb));
	memset(ok,0,sizeof(ok));
	mp.clear();

	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&ve[i]);
		mp[ve[i]] = i;
		if(mp[a-ve[i]])
		{
			hsa[mp[a-ve[i]]] = i; 
			hsa[i] = mp[a-ve[i]];
		}
		if(mp[b-ve[i]])
		{
			hsb[mp[b-ve[i]]] = i; 
			hsb[i] = mp[b-ve[i]];
		}

		for(int j = 1;j <= n;j ++)
		{
			printf("%d ",hsa[j]);
		}
		printf("\n");
		for(int j = 1;j <= n;j ++)
		{
			printf("%d ",hsb[j]);
		}
		printf("\n");
	}
	for(int i = 1;i <= n;i ++)
	{
		if(!ok[i])
		{
			if(hsa[i] && !hsb[i]) 
			{
				printf("******1\n");
				if(!ok[hsa[i]])
				{
					ok[i] = 1;
					ok[hsa[i]] = 1;
				}else{
					printf("NO\n");
					return 0 ;
				}
			}else if(hsb[i] && !hsa[i]) 
			{
				printf("******2\n");
				if(!ok[hsb[i]])
				{
					ok[i] = 2;
					ok[hsb[i]] = 2;
				}else{
					printf("NO\n");
					return 0 ;
				}
			}else if(hsb[i] && hsa[i]){
				printf("******3\n");
				if(!ok[hsb[i]] && !ok[hsb[i]])
				{
					int n1 = find(hsa[i],2);
					int n2 = find(hsb[i],1);
					if((n1 && n2 )||!(n1 || n2))
					{
						printf("NO\n");
						return 0 ;
					}else if(n1){
						ok[i] = 1;
						ok[hsa[i]] = 1;
					}else {
						ok[i] = 2;
						ok[hsb[i]] = 2;
					}
				}else if(ok[hsb[i]] && !ok[hsa[i]]){
					ok[i] =1;
					ok[hsa[i]] = 1;
				}else if(ok[hsa[i]] && !ok[hsb[i]])
				{
					ok[i] = 1;
					ok[hsb[i]] = 1;
				}
			}else{
				printf("NO\n");
				return 0 ;
			}
		}
	}
	for(int i = 1;i <= n;i ++)
		if(!ok[i])
		{
			printf("NO\n");
			return 0 ;
		}
	printf("YES\n");
	for(int i = 1;i <= n;i ++)
		printf("%d ",ok[i] - 1);
	return 0;
}
