// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年08月02日 星期六 00时26分37秒

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
int a[40] = {0};
int ans[40] = {0};
int b[100] = {0};
int num = 0 ; 
int hs[30];
void sai()
{
   for(int i = 2;i<= 60 ;i ++)
   {
	   int ok = 0 ; 
        for(int j = 2;j <= i - 1;j ++)
		{
		  if(i % j == 0 )
			  ok = 1; 
		}
		if(ok == 0 )
		{
		  num ++ ; 
		  b[num]  = i;
		}
   }
}
int main(){
   int n ;
   scanf("%d",&n);
   sai();
   printf("%d\n",num);  
   for(int i = 1;i <= n;i ++)
   {
      int temp ; 
	  scanf("%d",&temp);
	  a[temp]++; 
   }
return 0;
}
