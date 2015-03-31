// File Name: 354c.cpp
// Author: darkdream
// Created Time: 2015年03月31日 星期二 15时59分31秒

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
int n , k ; 
int a[400000];
int hs[2000005];
int mi = 1e9 ;
int mx = 0;
int main(){
   scanf("%d %d",&n,&k);
   for(int i =1 ;i <= n;i ++)
   {
	   scanf("%d",&a[i]);
	   mi = min(a[i],mi);
	   mx = max(a[i],mx);
	   hs[a[i]] ++ ;
   }
   for(int i = 1;i <= 2000000 ;i++)
	   hs[i] += hs[i-1];
   for(int i = mi ;i >= 1; i --)
   {
	  int tsum = 0 ; 
	  int tmp = 1; 
      while(tmp*i <= mx ) 
	  {
	  //   if(i == 4 )
		//	 printf("%d %d**%d\n",min((tmp+1)*i-1,tmp*i+k),tmp*i-1,hs[min((tmp+1)*i-1,tmp*i+k)] - hs[tmp*i-1]); 
	     tsum  += hs[min((tmp+1)*i-1,tmp*i+k)] - hs[tmp*i-1]; 
		 tmp ++ ;
	  }
	  if(tsum == n)
	  {
		  printf("%d\n",i);
		  return 0 ; 
	  }
	 // printf("%d %d\n",tsum,i);
   }
return 0;
}
