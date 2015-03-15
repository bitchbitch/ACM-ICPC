// File Name: 4951.cpp
// Author: darkdream
// Created Time: 2014年08月18日 星期一 16时35分46秒

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
int ans[560];
int hs[560][2];
int hs1[560][2];
int n;
void init(){
   memset(hs,0,sizeof(hs));
   memset(hs1,0,sizeof(hs1));
   for(int i = 0 ;i < n;i ++)
	   for(int j = 0 ;j < n ;j ++)
	   {
	      hs[i*j/n][0] ++ ;
		  hs[i*j%n][1] ++ ;
	   }

}
int main(){
	int ca = 0 ; 
     while(scanf("%d",&n) != EOF,n)
	   {
		  init();
		   ca ++ ;
		  for(int i = 1;i <= n;i ++)
		  {
		     for(int j = 1;j <= 2*n ;j ++)
			 {
			   int temp;
			   scanf("%d",&temp);
			   if(j % 2 ==  1)
			   {
			     hs1[temp][0] ++ ;  
			   }else{
			     hs1[temp][1] ++ ;
			   }
			 } 
		  }
		  for(int i = 0;i < n;i ++)
		  {
		     for(int j = 0;j < n;j ++)
			 {
			   if(hs1[i][1] == hs[j][1] && hs1[i][0] == hs[j][0])
			   {
			      ans[j] = i ;   
			   }
			 }
		  }
		  printf("Case #%d:",ca);
		  for(int i =0 ;i < n;i ++)
			  printf("%d ",ans[i]);
		  printf("\n");
	   }
	 
	return 0;
}
