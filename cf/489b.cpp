// File Name: 489b.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 08时35分11秒

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
int a,b[1000];
int hs[1000];
int main(){
  int n , m; 
  scanf("%d",&n);
  for(int i = 1;i <= n;i ++)
  {
    scanf("%d",&a);
    hs[a] ++; 
  }
  scanf("%d",&m);
  int sum = 0 ; 
  for(int i = 1; i<= m;i ++)
  {
    scanf("%d",&b[i]);
  }
  sort(b+1,b+m+1);
  for(int i = 1;i <= m;i ++)
  {
    for(int j= b[i] -1 ;j <= b[i] +1; j ++)
	{
	  if(hs[j] != 0 )
	  {
	    sum ++ ; 
		hs[j] --;
		break;
	  }
	} 
  }
  printf("%d\n",sum);
        
return 0;
}
