// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年04月04日 星期六 13时39分13秒

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
int fa[1000];
vector<int> mp[300];
char str[1000005];
char str1[10];
char str2[10];
int main(){
	scanf("%d",&t);
	while(t--)
	{
	   scanf("%s",str);
	   int len = strlen(str);
       for(int i = 1;i <= 299;i ++)
		   mp[i].push_back(i);
	   int q; 
	   scanf("%d",&q);
	   for(int i = 1;i <= q;i ++)
	   {
		    scanf("%s %s",str1,str2);
			int ta = str1[0];
			int tb = str2[0];
		    for(int i = 0 ;i < mp[tb].size();i ++) 	
				mp[ta].push_back(mp[tb][i]);
			mp[tb].clear();
	   }
	   //printf("***\n");
	   for(int i = 1;i <=299 ;i ++)
	   {
	      for(int j = 0 ;j < mp[i].size() ;j ++)
		  {
		    fa[mp[i][j]] = i ; 
		  }
		  mp[i].clear();
	   }
	   for(int i = 0 ;i < len ;i ++)
	   {
	       printf("%c",fa[str[i]]);
	   }
	   printf("\n");
	}

return 0;
}
