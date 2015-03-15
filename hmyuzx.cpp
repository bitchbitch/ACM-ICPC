// File Name: hmyuzx.cpp
// Author: darkdream
// Created Time: 2013年11月29日 星期五 19时56分03秒

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
int b[1005];
int main(){
  int n; 
  while(scanf("%d",&n) != EOF)
  {
	 memset(b,0,sizeof(b));
     a[n+1] = 0 ;
	 for(int i= 1;i <= n;i ++)
	 {
	   scanf("%d",&a[i]);
	 }
	 for(int i =1 ;i <= n;i ++)
	 {
	    int j ;
		for(j = i +1; j <= n;j++)
		{
		  if(a[j] > a[i])
			  break;
		}
		b[i] = a[j];
	 }
	 for(int i =1 ;i <= n;i ++)
		 printf("%d\n",b[i]);
  
  }
return 0;
}
