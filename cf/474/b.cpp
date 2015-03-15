// Author: darkdream
// Created Time: 2014年10月06日 星期一 23时39分31秒

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
int b[100005];
int n , m ; 
int find(int x)
{
    int l = 1; 
	int r = n;
	while(l <= r)
	{
	  int mid = (l + r)/2;
	  if(a[mid] < x)
	  {
	    l = mid + 1;
	  }else {
	    r = mid - 1;
	  }
	}
	return l;
}
int main(){
  scanf("%d",&n);
  for(int i =1 ;i <= n;i ++)
  {	  scanf("%d",&a[i]);
      a[i] = a[i-1] + a[i];
  }
  scanf("%d",&m);
  for(int i =1 ;i <= m;i ++)
  {
	  scanf("%d",&b[i]);
      printf("%d\n",find(b[i]));
  }
return 0;
}
