// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年02月08日 星期日 01时13分28秒

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
int a[55];
int n , m; 
int count()
{
	int sum = 0 ; 
   for(int i = 0;i < n;i ++)
   {
	   int mi = a[i]; 
	   for(int j = i ;j < n;j ++)
	   {
	        mi = min(mi,a[j]);
			sum += mi;
	   }
   }
   return sum;
}
int main(){
  scanf("%d %d",&n,&m);
  for(int i = 0;i < n;i ++)
  {
    a[i] = i+1; 
  }
  int mx = 0 ; 
  do{
   //for(int i = 0 ;i < n;i ++)
	 //  printf("%d ",a[i]);
   mx = max(mx,count());
  }while(next_permutation(a,a+n));
  int t = 0 ; 
  for(int i = 0;i < n;i ++)
  {
    a[i] = i+1; 
  }
  do{
    if(count() == mx)
	{
	   for(int i = 0 ;i < n;i ++)
			   printf("%d ",a[i]);
	   printf("\n");
	   t++;
	}
  }while(next_permutation(a,a+n));
  printf("%d\n",t);
return 0;
}
