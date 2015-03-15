// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年08月05日 星期二 12时05分09秒

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
int n , k ; 
LL sum = 0 ; 
int lowbit(int x)
{
	return x&(-x);
}
struct node{
	int num, s,rs ; 
}a[100005];
int num[100005];
int getsum(int x){
	int sum = 0 ;
	while(x >= 1)
	{
		sum += num[x];
		x -= lowbit(x);
	}
	return sum ; 
}
void update(int x)
{
	while(x <= n )
	{
		num[x] ++ ; 
		x += lowbit(x);
	}
	return; 
}
int cmp(node x ,node y )
{
	return x.num < y.num;
}
int cmp1(node x, node y)
{
	return x.s < y.s; 
}
int main(){
	while(scanf("%d %d",&n,&k)!= EOF)
	{
	    memset(num,0,sizeof(num));
		for(int i =1;i <= n;i ++)
		{
			scanf("%d",&a[i].num);
			a[i].s = i  ;
		}
		sort(a+1,a+1+n,cmp);
		int t = 1; 
		a[1].rs = 1; 
		for(int i = 2;i <= n;i ++)
		{
			if(a[i].num == a[i-1].num) 
				a[i].rs = t ;
			else {
				t++;
				a[i].rs = t; 
			}
		}
		sort(a+1,a+1+n,cmp1);
		sum = 0 ;
		for(int i = 1;i <= n;i ++)
		{
			sum += (getsum(n) - getsum(a[i].rs));
			update(a[i].rs);
		}
		if(sum > k)
		  cout << sum-k << endl;
		else printf("0\n");
	}
	return 0;
}
