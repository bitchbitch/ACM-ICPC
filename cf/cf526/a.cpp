// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年04月05日 星期日 00时33分59秒

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
char str[1005];
int ok = 0 ; 
int main(){
  int n ; 
  scanf("%d",&n);
  scanf("%s",&str[1]);
  for(int i = 1; i < n;i ++ ) 
  {
	if(str[i] == '*')
      for(int j = 1;j <= 100 ;j ++)
	  {
	     if(i + 4 * j <= n && str[i+j] == '*' && str[i+2*j] == '*' && str[i+3*j] =='*'&& str[i+4*j] == '*')
		 {
		   ok = 1; 
		   break;
		 }
	  }
	if(ok)
		break;
  }
  if(ok)
	  printf("yes\n");
  else puts("no");
return 0;
}
