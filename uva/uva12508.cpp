// File Name: uva12508.cpp
// Author: darkdream
// Created Time: 2014年10月08日 星期三 09时45分37秒

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
#define eps 1e-8
using namespace std;
int n , m ;
LL solve(int k)
{
	LL sum = 0 ;  
    for(int i = 1 ;i <= n;i ++)
	{
	    for(int j = 1;j <= m;j ++)
		{
			LL ans = 0 ;
	        LL temp =0;
			if(i * j <= k )
			{
			  temp = (j+1)*2 + (i+1) * 2 - 4;
			  //有 4个重复计数了
			}
			
			ans += temp;
			temp = 0 ; 
			for(int x = 1; x <= i ; x ++)
			{
		        double t = (x*j - k)*1.0/i ;   	
				
				int p = (x *1.0*j/i -eps);
				int tt = t+ 1.0 - 1e-6;
				
				tt = max(tt,0);
			    if(x == i && tt ==  0 )
				   tt ++ ; 
				temp += max(0,(p-tt+1));
			}
			temp *= 4; //对角线
            ans += temp;
			temp = 0 ; 
			for(int x = 1; x < i; x ++ )
			{
		       int t = (k - i*j + x *j)/x;
			   if(t >= 1)
			   {
			      temp += min(j-1,t);
			   }
			}
			
			temp *= 4;//第三种情况
			ans += temp;
			sum += ans*(n-i + 1)*(m-j+ 1);
		}
	}
    return sum;
}
int main(){
     int a, b ;
	 int t; 
	 scanf("%d",&t);
	 while(t--)
	 {
	   scanf("%d %d %d %d",&n,&m,&a,&b);
       printf("%lld\n",solve(b*2) - solve(a*2-1)) ; 	 
	 }
return 0;
}
