// File Name: 234c.cpp
// Author: darkdream
// Created Time: 2014年08月03日 星期日 16时16分35秒

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
int a[100005];
int za[100005];
int fa[100005];
int ans = 1e9; 
int main(){
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);

     int n ;
	 scanf("%d",&n);
	 memset(za,0,sizeof(za));
	 memset(fa,0,sizeof(fa));
	 for(int i = 1;i <= n;i ++)
	 {
	    scanf("%d",&a[i]);
	    if(a[i] >= 0)
		{
		   za[i] = za[i-1] + 1;   
		}else{
		   za[i] = za[i-1];
		}
	 }
     for(int i = n;i >= 2; i --)
	 {
	    if(a[i] <= 0 )
		{
		   fa[i] = fa[i+1] +1;
		}else{
		   fa[i] = fa[i+1];
		}
		if(fa[i] + za[i-1] < ans)
			ans = fa[i] + za[i-1];
	 }
	 printf("%d\n",ans);
return 0;
}
