// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年09月29日 星期一 00时20分32秒

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
int n; 
struct node{
 char str[60];
 char str1[60];
}a[100005];
int hs[100005];
int main(){
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
   {
     scanf("%s %s",a[i].str,a[i].str1);   
   }
   int tmp ; 
   for(int i = 1;i <= n;i ++)
   {
      scanf("%d",&tmp);
	  hs[i] = tmp ; 
   }
   char temp[60];
   if(strcmp(a[hs[1]].str,a[hs[1]].str1) < 0 )
   {
     strcpy(temp,a[hs[1]].str);
   }
   else
   {
     strcpy(temp,a[hs[1]].str1);
   }
   for(int i = 2;i <= n;i ++)
   {
      /*puts(temp);
	  puts(a[hs[i]].str);
	  puts(a[hs[i]].str1);
	  puts("");*/
	  if(strcmp(a[hs[i]].str,a[hs[i]].str1) < 0 )
	  {
	    if(strcmp(a[hs[i]].str,temp) > 0)
		{
		  strcpy(temp,a[hs[i]].str);
		  continue;
		}
		if(strcmp(a[hs[i]].str1,temp) > 0)
		{
		  strcpy(temp,a[hs[i]].str1);
		  continue;
		}
		puts("NO");
		return 0;
	  }else {
	    if(strcmp(a[hs[i]].str1,temp) > 0)
		{
		  strcpy(temp,a[hs[i]].str1);
		  continue;
		}
		if(strcmp(a[hs[i]].str,temp) > 0)
		{
		  strcpy(temp,a[hs[i]].str);
		  continue;
		}
		puts("NO");
		return 0;
	  }
   }
   puts("YES");
return 0;
}
