// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年02月08日 星期日 03时02分52秒

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
int a[6][20000];
int sum[6];
int x[6],y[6];
double ans = 0 ; 
int n;
int num = 0 ; 
int hehe[6];
void solve(int k )
{
   for(int i = 1;i <= y[k]; i ++)
   {
	  i = i -1;
      for(int j = 1;j <= n ;j ++)
	  {
	    if(j == k)
			continue;
		if(i < x[j] || i > y[j])
			break;
        double tmp = 1.0/sum[j];
		for(int s = 1;s <= n; s ++)
		{
		    if(s == j || s == k)
				continue;
			//printf("%d %d %d tmp = %lf %d %d\n",k,j,s,tmp,x[s],i);	
			if(x[s] >= i )
			{
				tmp *= 0;
			}
			else if(i-1 >= x[s] && i-1 <= y[s])
			{
//		       printf("%d %d %d tmp = %lf %d %d %d\n",k,j,s,tmp,x[s],i,sum[s]);	
			 // if(s > j)
			   tmp = tmp*(i-1-x[s]+1)/sum[s];
			 // else 
			  // tmp = tmp*(i-x[s])/sum[s];
			}
		}
		printf("%d %d %d %lf\n",k,j,i,tmp);
		ans += i * tmp ;
	  }
	  i = i +1;
   }
}
int main(){
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
   {
	  scanf("%d %d",&x[i],&y[i]);
	  sum[i] = y[i] - x[i] + 1; 
   }
   for(int i = 1;i <= n;i ++)
   {
     solve(i); 
   }
   printf("%.9lf",ans);
return 0;
}
