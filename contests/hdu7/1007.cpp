// File Name: 1007.cpp
// Author: darkdream
// Created Time: 2014年08月12日 星期二 21时05分18秒

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
map<int,map<int,int> > a;
map<int,int>  hashx , hashy;
const int maxn = 100005; 
int T , n , m ,k; 
struct node{
   int x, y ,c; 
}l[maxn];
int cmp(node t,node tt)
{
     return t.x < tt.x;
}
int cmp1(node t,node tt)
{
    return t.y < tt.y;
}
int main(){
    int T; 
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ca ++)
	{
	   hashx.clear(),hashy.clear(),a.clear();
	   scanf("%d %d %d",&n,&m,&k);
	   for(int i = 1;i <= k;i ++)
		  scanf("%d %d %d",&l[i].x,&l[i].y,&l[i].c);
       sort(l+1,l+1+k,cmp);
	   int mapx,mapy;
	   mapx = mapy = 0; 
	   for(int i = 1;i <= k;i ++)
		   if(hashx.find(l[i].x) == hashx.end())
			   hashx[l[i].x] = ++mapx;
	   sort(l+1,l+1+k,cmp1);
	   for(int i =1;i <= k ;i ++)
	   {
	      if(hashy.find(l[i].y) == hashy.end())
		  {
		      hashy[l[i].y] = ++ mapy;  
		  }
		  a[hashx[l[i].x]][hashy[l[i].y]] = l[i].c;
	   }
	   scanf("%d",&m);
	   printf("Case #%d:\n",ca);
	   for(int i = 1;i <= m;i ++)
	   {
	      int Q,A,B;
		  scanf("%d %d %d",&Q,&A,&B);
		  if(Q ==  1){
		      if(hashx.find(A) != hashx.end())
			  {
			    int temp = hashx[A];
				hashx[A] = hashx[B];
				hashx[B] = temp;
			  }
		  }else if( Q == 2){
			  if(hashy.find(A) != hashy.end())
			  {
				int temp = hashy[A];
				hashy[A] = hashy[B];
				hashy[B] = temp;
			  }
		  }else {
		     if(hashx.find(A) != hashx.end() && hashy.find(B) != hashy.end())
			 {
			    printf("%d\n",a[hashx[A]][hashy[B]]);
			 }else printf("0\n");
		  }
	   }
	}
	
	return 0;
}
