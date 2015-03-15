/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2014-08-12 14:55
 * Filename : 1005.1.cpp
 * Description :
 * *********************************************************/
// File Name: 1005.1.cpp
// Author: darkdream
// Created Time: 2014年08月12日 星期二 14时37分57秒

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
LL n3[1000];
LL n , x, y ,z ,t ; 
LL ans = 0 ;
int anss  = 0 ; 
int main(){
   
   int T;
// freopen("input","r",stdin);
  // freopen("output","w",stdout);
   n3[1] = 3; 
   for(int i = 2;i <= 11;i ++)
      n3[i] = n3[i-1] * 3; 
   scanf("%d",&T);
   while(T--)
   {
	   ans = 0 ; 
       scanf("%lld %lld %lld %lld %lld",&n,&x,&y,&z,&t);
	   for(int i= 0 ;i <= n3[n];i ++)
	   {
	      int a[20];
		  memset(a,0,sizeof(a));
		  int p = 0 ; 
	      int k = i ; 
	      while(k)
		  {
		     p++;
		     a[p] = k % 3; 
		     k = k /3; 
		  }
		  int nv = 0 ;
		  LL sum = 0 ;
		  LL tt = t;
		  for(int j = 1;j <= n;j ++)
		  {
		     sum += nv * y * tt; 
		     if(a[j] == 0 )
			   tt += z ; 
			 else if(a[j] == 1 ){
			   nv ++ ; 
			 }else{
			   sum += x * tt; 
			 }
		//	 printf("%lld %lld ",sum,tt);
		  }
		 // printf("\n");
	      if(sum >= ans)
		  {
		    ans = sum ;
		   for(int i = 1;i <= n;i ++)
			   printf("%d ",a[i]);
		   printf("\n");
		  }
	   }
     printf("%lld\n",ans);
   }
return 0;
}
