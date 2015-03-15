// File Name: 433b.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 10时28分17秒

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
long long a[100005];
long long b[100005];
int main(){
  long long n; 
  scanf("%I64d",&n);
  b[0] = 0 ;
  for(long long i =1 ;i <= n;i ++)
  {

     scanf("%I64d",&a[i]);
	 b[i] =b[i-1]+a[i];
  }
  sort(a+1,a+1+n);
  a[0] = 0 ; 
  for(long long i =1;i <= n;i ++)
  {
    a[i] = a[i-1]+a[i];
  }
  long long m ;
  scanf("%I64d",&m);
  while(m--)
  {
	 long long t,l,r;
     scanf("%I64d %I64d %I64d",&t,&l,&r);
	 if(t == 1 )
	 {
	    printf("%I64d\n",b[r] -b[l-1]);
	 }else
	    printf("%I64d\n",a[r] -a[l-1]);
  }
return 0;
}
