// File Name: e.cpp
// Author: darkdream
// Created Time: 2014年08月10日 星期日 13时46分45秒

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
char str[1004][14];
char str1[1004][14];
char str2[1004][14];
int hs[1004];
int main(){
   int t ; 
   scanf("%d",&t);
   while(t--)
   {
     int n ; 
	 scanf("%d",&n);
     memset(hs,9,sizeof(hs));
	 for(int i= 1;i <=n;i ++)
	  {
	    scanf("%s",str[i]);
	  }
	  for(int i = 1;i <= n;i ++)
	  {
	     scanf("%s",str1[i]);
		 for(int j= 1;j <= n;j ++)
		 {
		   if(strcmp(str[j],str1[i]) == 0)
		   {
		     hs[j] = i;
			 break;
		   }
		 }
	  }
	  for(int i = 1;i <= n;i ++)
	  {
	    scanf("%s",str2[i]);
	  }
	  for(int i = 1;i <= n;i ++)
		  printf(i == 1?"%s":" %s",str2[hs[i]]);
	  printf("\n");
   }
return 0;
}
