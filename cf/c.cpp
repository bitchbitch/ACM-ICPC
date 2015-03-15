// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年01月28日 星期三 00时58分13秒

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

int m,t,r;
int w[1000];
int hs[1000];
int main(){
   scanf("%d %d %d",&m,&t,&r);    
   int tmp;
   for(int i =1 ;i <= m ;i ++)
   {
      scanf("%d",&tmp);
	  w[tmp+350] =1;
   }
   int ok = 1;
   for(int i = 350;i <= 650;i ++)
   {
       if(w[i])
	   {
		 int sum = 0 ; 
	     for(int j = i-1;j>= i-t;j --)
		 {
		   if(hs[j])
			   sum ++ ; 
		 } 
		 if(sum >= r )
			 continue;
		 else{
		   int num = r - sum ; 
           int rnum =0 ; 
		   for(int j = i -1;j >= 0;j --)
		   {
		     if(hs[j] == 0 )
			 {
			   hs[j] = 1;
			   rnum ++ ; 
			 }
             if(rnum == num)
			 {
				if(j + t < i)
					ok = 0 ; 
			    break;
			 }
		   }
		   if(rnum != num)
			   ok = 0 ; 
		 }
	   }
   }
   if(ok == 0 )
	   printf("-1\n");
   else{
      int sum = 0 ; 
	  for(int i = 0 ;i <= 700 ;i ++)
	  {
	    sum += hs[i];
	  }
	  printf("%d\n",sum);
   }
return 0;
}
