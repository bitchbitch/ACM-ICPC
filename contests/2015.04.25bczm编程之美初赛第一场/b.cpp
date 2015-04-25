// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月25日 星期六 15时33分47秒

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
struct node{
   int  l,r,w; 	
}a[30]; 
int cmp(node a, node b)
{
   if(a.l == b.l)
	   return a.r > b.r;
   return a.l < b.l ; 
}
int ok[30];
int n ;
double solve(int k)
{
    int t = 0 ; 
	memset(ok,0,sizeof(ok));
	double sum = 0 ; 
	while(k)
	{
		ok[t] = k %2;  
		k /= 2;
	    t ++ ; 
	}
	double r = -1e30;
	for(int i =0 ;i < n;i ++)
	{
		if(ok[i] == 0 )
			continue;
		if(a[i].l > r)
		{
			sum += a[i].w - 1.0*(a[i].r - a[i].l) *(a[i].r -a[i].l)/4;  
		}else {
			if(r > a[i].r)
				sum += a[i].w;
			else 
			 sum += a[i].w - (1.0*(a[i].r - a[i].l) *(a[i].r -a[i].l)/4 - 1.0*(r - a[i].l) *(r- a[i].l)/4);  
		}
		r = max(r,1.0*a[i].r); 
	}
//	printf("%lf\n",sum);
	return sum; 
}
int T; 
int main(){
	scanf("%d",&T);
    for(int ca = 1; ca <= T; ca ++){
	    scanf("%d",&n);
		int ta,tb,w; 
		for(int i = 0;i < n;i ++)
		{
			scanf("%d %d %d",&ta,&tb,&a[i].w);
			a[i].l = ta -tb;
			a[i].r = ta + tb; 
		}
		sort(a,a+n,cmp);
		int num = (1 << n) -1;
		double mx = 0;
		for(int i = 0 ;i <= num ;i ++)
		{
			mx = max(solve(i),mx);
		}
		printf("Case #%d: %.2f\n",ca,mx);

	}  
return 0;
}
