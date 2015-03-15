// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年08月15日 星期五 23时24分04秒

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

int main(){
    int n , m ,n1,m1; 
	scanf("%d %d %d %d",&n,&m,&n1,&m1);
   // printf("%d %d %d %d\n",n,m1,n1,m);
   if(n == n1)
   {
       printf("%d %d %d %d\n",n+abs(m-m1),m,n1+abs(m-m1),m1);   
   }else if(m == m1){
       printf("%d %d %d %d\n",n,m+abs(n-n1),n1 ,abs(n-n1)+m1);   
   }else {
      if(abs(n-n1) != abs(m-m1)) 
		{
		  printf("-1\n");
		  return 0; 
		}
	  printf("%d %d %d %d\n",n,m1,n1,m);
   }
return 0;
}
