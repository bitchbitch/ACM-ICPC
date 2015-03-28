// File Name: g.cpp
// Author: darkdream
// Created Time: 2015年03月28日 星期六 12时04分39秒

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
#define maxn 100005
using namespace std;
multiset<int>  st;
int n , k ; 
int a[maxn]; 
int main(){
   while( scanf("%d %d",&n,&k) != EOF)
   {
	int mx = 1;
	st.clear();
	for(int i = 1 ;i <= n;i ++)
	{
	   scanf("%d",&a[i]);
	}
	for(int i = 1,j = 1; i <= n;i ++)
	{
	   st.insert(a[i]);
	   for(;*st.rbegin()-*st.begin() > k ; j ++)
	   {
	      st.erase(st.find(a[j]));
	   }
	   if(i - j +1 >= mx)
		   mx = i-j+1;
	}
	printf("%d\n",mx);
   }
return 0;
}
