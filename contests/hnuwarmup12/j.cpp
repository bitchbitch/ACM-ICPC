// File Name: j.cpp
// Author: darkdream
// Created Time: 2015年03月14日 星期六 15时56分31秒

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
char str[20][1000];
int mp[12][12];
char tmp1[1000];
char tmp2[1000];
int tmp ;
char c;
int n;
struct node{
	int si,v;
}ans[1100];
int cmp(node a, node b)
{
	return a.v < b.v;
}
int main(){
	while(scanf("%d",&n) != EOF)
	{
		if(n == 0)
			break;
		memset(mp,0,sizeof(mp));
		for(int i = 1;i <= n;i ++)
		{
			scanf("%s",str[i]); 
		}
		int mx = 0 ;
		int mxnum = 0; 
		for(int i = 1;i <= n-1;i ++)
		{
			scanf("%s %c %d %s",tmp1,&c,&tmp,tmp2); 
			int ta;
			int tb;
			for(int j = 1;j <= n;j++)
			{
				if(strcmp(str[j],tmp1) == 0 )
				{
					ta = j ; 
					break;
				}
			}
			for(int j= 1;j <= n;j ++)
			{
				if(strcmp(str[j],tmp2) == 0 )
				{
					tb = j ; 
					break;
				}
			}
			mp[ta][tb] = tmp;
		}
		int tt = 1;
		while(tt--)
		{
			for(int k = 1;k <= n ;k ++)
			{
				for(int i = 1;i <= n ;i ++)
					for(int j= 1;j <= n ;j ++)
					{
						if(mp[i][k] != 0 && mp[k][j] != 0 ) 
						{
							mp[i][j] = mp[i][k] *mp[k][j];
						}
						if(mp[i][k] != 0 && mp[j][k] != 0 )
						{
							if(mp[i][k] > mp[j][k])
							{
								mp[i][j] = mp[i][k]/mp[j][k];
							}else{
								mp[j][i] = mp[j][k]/mp[i][k];
							}
						}
						if(mp[k][i] != 0 && mp[k][j] != 0 )
						{
						   if(mp[k][i] > mp[k][j])
							   mp[j][i] = mp[k][i]/mp[k][j];
						   else	   
						       mp[i][j] = mp[k][j]/mp[k][i];
						}
						if(mp[i][j] > mx)
						{
							mx = mp[i][j];
							mxnum = i;
						}
					}
			}
		}
		for(int i = 1;i <=n;i ++)
		{
			ans[i].si = i;
			ans[i].v = mp[mxnum][i];
		}
		sort(ans+1,ans+1+n,cmp);
		printf("1%s",str[mxnum]);
		for(int i = 2;i <= n;i ++)
			printf(" = %d%s",ans[i].v,str[ans[i].si]);
		printf("\n");
	}

	return 0;
}
