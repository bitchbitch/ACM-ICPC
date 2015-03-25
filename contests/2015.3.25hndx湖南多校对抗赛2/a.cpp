// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年03月25日 星期三 13时17分06秒

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
  int l , r; 
} a[1005];
int cmp(node a ,node b)
{
   return  a.l < b.l ;
}
int main(){
  int n , m;
  scanf("%d %d",&n,&m);
  for(int i =1;i <= m;i ++)
  {
      scanf("%d %d",&a[i].l,&a[i].r);	
  }
  int tl = 0 ; 
  int tr = 0 ;
  sort(a+1,a+1+m,cmp);
  int sum = n + 1; 
  for(int i = 1;i <= m;i ++)
  {
     if(a[i].l <= tr)
	 {
	    tr = max(a[i].r,tr);
	 }else{
		//printf("%d %d\n",tl,tr);
	    sum += (tr-tl)*2;
		tl = a[i].l ; 
		tr = a[i].r;
	 }
  }
  sum += (tr-tl)*2;
  printf("%d\n",sum);
return 0;
}
