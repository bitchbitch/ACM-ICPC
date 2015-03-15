// File Name: f.cpp
// Author: darkdream
// Created Time: 2015年03月14日 星期六 12时22分50秒

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
int n , m ; 
int main(){
    while(scanf("%d %d",&n,&m) != EOF)
	{
		 if(n == 0 && m == 0 )
			 break;
		  int tmp = 0 ; 
	      if(n > m )
		  {
		    tmp = n / m; 
			n = n %m ;
		  }
			printf("%d %d / %d\n",tmp,n,m);

	}
return 0;
}
