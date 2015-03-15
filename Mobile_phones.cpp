// File Name: Mobile_phones.cpp
// Author: darkdream
// Created Time: 2014年04月25日 星期五 14时30分51秒

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
#include<climits>

using namespace std;
int sum[2026][2026];
int s; 
int main(){
   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   int t; 
   while(1)
   {
      scanf("%d",&t);
	  if(t == 0 )
	  {
	     scanf("%d",&s); 
		 memset(sum,0,sizeof(sum));
	  }
	  if(t == 1 )
	  {
	    int x, y , z; 
		scanf("%d %d %d",&x,&y,&z);
	  }
	  if(t == 2)
	  {
	      
	  }
	  if(t == 3 )
		  break;
   }
return 0;
}
