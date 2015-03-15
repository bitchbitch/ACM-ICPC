// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年04月25日 星期五 15时09分25秒

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
#include<climits>

using namespace std;

struct node{
  int x, y , v; 
}a[10000];
bool cmp(node a , node b)
{
    return sqrt(a.x*a.x +a.y*a.y) < sqrt(b.x*b.x + b.y * b.y);
}
int main(){
   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   int n,s;
   scanf("%d %d",&n,&s);
   for(int i = 0;i < n;i ++)
   {
     scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].v);
   }
   sort(a,a+n,cmp);
   int ok =0 ;
   if(s >= 1000000)
   {
	   printf("%.7lf",0.0);
	   return 0 ; 
   }
   int i ; 
   for(i = 0 ;i < n;i ++)
   {
     s += a[i].v ; 
	 if(s >= 1000000)
		{
		  ok= 1; 
		  break;
		}
   }
   if(ok == 0 )
	   printf("-1\n");
   else printf("%.7lf\n",sqrt(a[i].x*a[i].x + a[i].y * a[i].y) + 1e-9);
return 0;
}
