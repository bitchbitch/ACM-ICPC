// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年08月15日 星期五 23时41分47秒

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
map<int,int>a;
int main(){
   int n;
   a.clear();
   int mxnum = -1e9+1; 
   int minum = 1e9 + 1;
   int temp ;
   scanf("%d",&n);
   for(int i =1 ;i <= n;i ++)
   {
       scanf("%d",&temp);
	   a[temp] = a[temp] + 1; 
	   if(temp > mxnum)
	     mxnum = temp ;
	   if(temp < minum)
		   minum = temp ;
   }
   printf("%d ",mxnum - minum);
   if(mxnum != minum)
   {
	   printf("%lld\n",1ll*a[mxnum]*a[minum]);
   }else {
       printf("%lld\n",1ll*a[mxnum]*(a[mxnum] - 1)/2) ;
   }
return 0;
}
