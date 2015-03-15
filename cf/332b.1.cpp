// File Name: 332b.1.cpp
// Author: darkdream
// Created Time: 2014年07月30日 星期三 10时13分41秒

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
#define maxn 200050 
using namespace std;
LL a[maxn];
LL sum[maxn];
LL m[maxn];
int s[maxn];
int n , k ; 
int main(){
     scanf("%d %d",&n,&k);
	 a[0] = 0 ; 
	 int temp ; 
	 for(int i = 1;i <=  n;i ++)
	 {
	    scanf("%d",&temp);
		a[i] =a[i-1]+ temp; 
	 }
	 int p = n - k + 1; 
	 for(int i = 1;i <= p ; i ++)
	 {
	   sum[i] = a[i+k-1] - a[i-1];
	 }
	 m[p] = sum[p];
	 s[p] = p ; 
	// printf("%lld\n",sum[5]);
	 for(int i = p -1;i >= 1 ;i --)
	 {
	    if(sum[i] >= m[i+1])
		{
		    m[i] = sum[i];
			s[i] = i ;
		}else{
		   m[i] = m[i+1];
		   s[i] = s[i+1];
		}
	 }
	 int a, b ;
	 LL maxa = -1e9 ; 
	 for(int i =1 ;i <= p;i ++)
	 {
	    if(sum[i] + m[i+k] > maxa) 
		{
		   a = i ; 
		   b = s[i+k];
		   maxa = sum[i] + m[i+k];
		}
	 }
	 printf("%d %d\n",a,b);
return 0;
}
