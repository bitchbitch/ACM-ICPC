// File Name: 351a.cpg
// Author: darkdream
// Created Time: 2015年03月08日 星期日 12时21分23秒

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
int a[5000];
const double eps = 1e-8;
int main(){
   int n ; 
   scanf("%d",&n);
   double sum = 0 ; 
   int n0 = 0 ; 
   for(int i = 1;i <= 2*n;i ++)
   {
      double tmp;
	  scanf("%lf",&tmp);
	  int x = (tmp*1000+eps);
	  a[i] = x % 1000;
      if(a[i] == 0 )
		  n0 ++ ; 
	  sum += a[i]*1.0/1000;
   }
   double  ans = 1e9 ;
 //  if(n == 32)
   //printf("%f %d %d\n",ans,min(2*n-n0,n),n0);
   for(int i = max(0,n-n0);i <= min(2*n-n0,n) ;i ++)
	   ans = min(ans,fabs(sum-i));
   printf("%.3f\n",ans); 
return 0;
}
