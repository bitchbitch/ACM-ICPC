// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年01月18日 星期日 20时51分58秒

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
int fa1[100005];
int fa2[100005];
int hs1[100005];
int hs2[100005];
int find1(int x)
{
   return fa1[x] == x?x:fa1[x] = find1(fa1[x]);
}
int find2(int x)
{
   return fa2[x] == x?x:fa2[x] = find2(fa2[x]);
}
int main(){
  int n , m ; 
  scanf("%d %d",&n,&m);
  int a,b;
  for(int i = 1;i <= n; i ++)
  {
     fa1[i] = fa2[i] = i;  
  }
  memset(hs1,0,sizeof(hs1));
  memset(hs2,0,sizeof(hs2));
  for(int i = 1;i <= m;i++)
  {
	scanf("%d %d",&a,&b);
    if(a < b )
	{
      int x = find1(a);
	  int y = find1(b);
	  if(x != y )
		  fa1[x] = y ; 
	}else{
      int x = find2(a);
	  int y = find2(b);
	  if(x != y )
		  fa2[x] = y ; 
	}
  }
  for(int i =1 ;i <= n;i ++)
  {
	fa1[i] = find1(fa1[i]);
	fa2[i] = find2(fa2[i]);
    hs1[fa1[i]] ++ ; 
	hs2[fa2[i]] ++ ; 
  }
  int sum = 0 ;  
  //for(int i = 1;i <= n;i ++)
//	  printf("%d ",fa1[i]);
 // printf("\n");
  for(int i = 1;i <= n;i ++ )
  {
     if(hs1[i])
		 sum += hs1[i] -1 ; 
	 if(hs2[i])
		 sum += hs2[i] -1;
  }
  printf("%d\n",sum);
return 0;
}
