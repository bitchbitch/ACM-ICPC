// File Name: i.cpp
// Author: darkdream
// Created Time: 2013年04月10日 星期三 14时33分19秒

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
#include<limits.h>
using namespace std;
int f[40005];
struct blocks
{
	int c,w,m;
     bool operator < (const blocks& x) const{
		 return w < x.w;

	 }
};
struct blocks block[405];
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n , v = INT_MIN ;
	scanf("%d",&n);
	for(int i = 0;i < n; i ++ )
	{
		scanf("%d %d %d",&block[i].c,&block[i].w,&block[i].m);
		if(block[i].w > v)
	    {
		  v = block[i].w;
		}
	}
	sort(block,block+n);
/*	for(int i = 0;i < n; i ++ )
	{
		printf("%d %d %d\n",block[i].c,block[i].w,block[i].m);
	}
*/
	memset(f,0,sizeof(f));
	for(int i = 0;i < n; i ++)
	{
		for(int j = 1; j <= block[i].m ; j++ )
		{ 
			for(int t = block[i].w; t > block[i].c ; t--)
			{
				f[t] = f[t]>(f[t-block[i].c]+block[i].c)?f[t]:(f[t-block[i].c]+block[i].c);
			} 
		}
	   /*for(int j = 0 ;j <= v; j ++)
		   printf("%d ",f[j]);
	   printf("\n");*/
	}

	printf("%d\n",f[v]);

	return 0 ;
}

