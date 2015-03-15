// File Name: ans.cpp
// Author: darkdream
// Created Time: 2014年11月27日 星期四 21时12分13秒

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
char str[1000];
int solve(int l ,int r)
{
    if(r-l+1 == 3 && str[l] == 'W'&& str[l+1] == 'L'&& str[l+2] == 'A')
    {
	  return 1;
	}
	return 0 ;
}
int main(){
   int n;
   //freopen("in","r",stdin);
   //freopen("out","w",stdout);
   scanf("%d",&n);
   getchar();
   for(int i =1;i <= n;i ++)
   {
     gets(str);
	 int len = strlen(str);
	 int l = 0 ; 
	 int sum = 0 ; 
	 for(int j = 1 ;j <=len;j ++)
	 {
	   if(str[j] == ' ' || str[j] == '\0')
	   {
	     sum +=solve(l,j-1);
		 l = j + 1;
	   }
	 }
     if(sum % 2 == 1 )
		 printf("Yes\n");
	 else printf("No\n");
   }
	
    return 0;
}
