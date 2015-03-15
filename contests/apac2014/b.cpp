// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年09月15日 星期一 15时11分53秒

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
int a[1000005];
int main(){
  freopen("out","w",stdout);
  int t; 
  scanf("%d",&t);
  for(int ca = 1;ca <= t;ca ++)
  {
      int n , k ; 
	  scanf("%d %d",&n,&k);
	  int temp ;
	  int  p = 0 ; 
	  for(int i =1;i <= n;i ++)
	  {
         scanf("%d",&temp);
		 if(p >= 2 )
		 {
		    if(temp == 2*a[p] -a[p-1])
			{
			  p  = p - 2;
			}
            else{
			  p++ ; 
              a[p] = temp ;
			}
		 }else{
			  p++ ; 
              a[p] = temp ;
		 }
	  }
	  printf("Case #%d: %d\n",ca,p);
  }
return 0;
}
