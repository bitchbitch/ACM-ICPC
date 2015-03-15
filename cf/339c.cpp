// File Name: 339c.cpp
// Author: darkdream
// Created Time: 2014年08月03日 星期日 16时38分23秒

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
int ans[1004];
int num = 0 ; 
int b[30];
int lb = 0; 
int m; 
int dfs(int num ,int last ,int k)
{
    if(k == m + 1)
		return 1 ;
	for(int i = 1;i <= lb ;i ++)
	{
	   if(b[i] > num && b[i] != last)
	   {
	       if(dfs(b[i]-num,b[i],k+1))
		   {
			   ans[k] = b[i];
		       return 1;
		   }
	   }
	}
	return 0 ; 
}
int main(){
   char str[14];
   scanf("%s",str);
   scanf("%d",&m);
   int len = strlen(str);
   for(int i = 0;i < len; i ++)
   {
          if(str[i] == '1')
			{
			  lb ++ ; 
			  b[lb] = i+1 ;
			}
   }
   if(dfs(0,0,1))
   {
     printf("YES\n") ;
	 for(int i =1 ;i <= m;i ++)
		 printf("%d ",ans[i]);
   }else{
     printf("NO\n");
   }
return 0;
}
