// File Name: 107b.cpp
// Author: darkdream
// Created Time: 2015年03月24日 星期二 21时40分11秒

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
int n , m , h ; 
int a[1005];
int main(){
	scanf("%d %d %d",&n,&m,&h);
    int sum = 0 ; 
	for(int i = 1;i <= m;i ++)
	{
	   scanf("%d",&a[i]);
	   sum += a[i];
	}
	a[h] -- ; 
	n -- ;
	sum -- ;
	if(sum < n )
	{
		printf("-1\n");
	    return 0 ; 
	}
    int r1 = sum;
	int l1 = (sum-a[h] + 1);
	int l2 = sum - a[h] - n +1 ; 
//	printf("%d %d %d\n",r1,l1,l2);
	double ans = 1.0;
	for(int i = l1 ;i <= r1;i ++)
	{
	    ans = ans * (double)(l2+(i-l1))*1.0/i; 
	}
	printf("%f\n",1.0- ans);
return 0;
}
