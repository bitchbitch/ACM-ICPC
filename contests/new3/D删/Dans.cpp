// File Name: Dans.cpp
// Author: darkdream
// Created Time: 2014年12月09日 星期二 21时46分39秒

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
#define maxn 10005
using namespace std;
int a[maxn];
int b[maxn];
int main(){
    int T ;
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    time_t  be = clock();
	scanf("%d",&T);
	while(T--)
	{
	  int n ,m ; 
	  scanf("%d %d",&n,&m);
	  for(int i = 1;i <= n;i ++)
	     scanf("%d",&a[i]);
	  for(int i= 1; i <=m;i ++)
	     scanf("%d",&b[i]);
	  int i = 1; 
	  int j = 1;
	  int sum = 0 ; 
	  while(sum < n+m)
	  {
	     if(i == n +1)
		 {
		    printf("%d",b[j]);
			j ++; 
		 }else if(j == m + 1){
		    printf("%d",a[i]);
		    i ++ ; 
		 }else if(a[i] < b[j])
		 {
		    printf("%d",a[i]);
		    i ++ ; 
		 }else{
		    printf("%d",b[j]);
			j ++; 
		 }
	    sum ++ ; 
        if(sum != n+m )
			printf(" ");
		else printf("\n");
	  }
	}
    time_t  en = clock();
	//printf("%lf\n",(en-be)*1.0/CLOCKS_PER_SEC);
return 0;
}
