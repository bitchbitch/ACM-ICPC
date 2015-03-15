// File Name: h.cpp
// Author: darkdream
// Created Time: 2013年04月27日 星期六 19时14分49秒

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

using namespace std;
int a[1005];
int main(){
   int n; 
   while(scanf("%d",&n) != EOF)
   {
	 memset(a,0,sizeof(a));
	 int tsum = 0;
	 for(int i = 1;i <= n;i ++ )
	 {
	   scanf("%d",&a[i]);
	   tsum += a[i];
	 }
	 int sum = 0;
	 for(int i = 1; i<= n;i ++)
       {
		   if((tsum-a[i])% 2 == 0)
			 sum ++;;
	   }
	 printf("%d\n",sum);
   }
return 0;
}
