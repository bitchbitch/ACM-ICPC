	// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年12月09日 星期二 21时37分38秒

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
int a[1000005];
int b[1000005];
int main(){
    freopen("in","w",stdout); 
    srand(time(NULL));
	printf("100\n");
	for(int i =1;i <= 1 ; i ++)
	{
	   int n ,m ;
	   if(rand()%10 <= 10)
	   {
	    n = rand()%10000 + 1;
	    m = rand()%10000 + 1;
	   }else{
	    n = rand()%100 + 1;
	    m = rand()%100 + 1;
	   }
	   printf("%d %d\n",n,m);
	   for(int j = 1;j <= n; j ++)
	       a[j] = rand();
	   sort(a+1,a+1+n);
	   for(int j = 1;j <= n;j ++)
	        printf(j == 1?"%d":" %d",a[j]);
	   printf("\n");
	   for(int j = 1;j <= m;j ++)
	       b[j] = rand();
	   sort(b+1,b+1+m);
	   for(int j = 1;j <= m;j ++)
	        printf(j == 1?"%d":" %d",b[j]);
	   printf("\n");
	}
return 0;
}
