// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月13日 星期一 00时13分25秒

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
int v1,v2;
int t,d ;
int a[105];
int b[105];
int main(){
	scanf("%d %d",&v1,&v2);
	scanf("%d %d",&t,&d);	
    if(v2 < v1)
		swap(v1,v2);
	a[1] = v1; 
	int sum = a[1]; 
	for(int i = 2;i <= t;i ++)
	{
		a[i] = a[i-1] + d; 
	    sum += a[i];
	}
	
	b[t] = v2;
	sum -= (a[t] -b[t]);
	for(int i = t-1;i  >= 1; i --)
	{
	   b[i] = b[i+1]+d;
 	   if(b[i] > a[i])
		   break;
	   //printf("%d %d\n",a[i],b[i]);

	   sum -=(a[i]-b[i]);
	}
    printf("%d\n",sum);
return 0;
}
