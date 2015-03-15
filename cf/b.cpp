// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年01月28日 星期三 00时47分49秒

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
char str[100005];
int main(){
  scanf("%s",str);
  int ok = 0 ; 
  int len = strlen(str);
  int h = str[len-1] - '0';
  for(int i = 0;i < len-1 ;i ++)
  {
     int k = str[i] -'0';
	 if(k % 2 == 0 && k < h )
	 {
		 swap(str[i],str[len-1]);
	    ok = 1; 
		break;
	 }
  }
  if(ok)
  {
	  printf("%s\n",str);
      return 0 ; 
  }
  for(int i = len -1;i >= 0 ;i --)
  {
     int k  = str[i] -'0';
	 if(k % 2 == 0 )
	 {
	   swap(str[i],str[len-1]);
	   ok = 1; 
	   break;
	 }
  }
  if(ok )
  {
    printf("%s\n",str);
	return 0 ; 
  }
  printf("-1\n");
return 0;
}
