// File Name: pingguo.cpp
// Author: darkdream
// Created Time: 2015年04月02日 星期四 19时53分18秒

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
struct pinguo{
   int val ;
   int tadd;
   int tjian;
   int flagpush;
   int flagpop;
   void topush(int v)
   {
	  tadd += v; 
	  if(flagpush)
	  {
        return;
	  }
	  flagpush = 1; 
	  while(tadd != 0)
	  {
		  if(tadd >= 5 - val){
			  tadd -= 5-val;
			  val = 5;
		  }else
		  {
			  val += tadd; 
			  tadd = 0 ;
		  }
	      sleep(1); 
	  }
	  flagpush = 0;
   }
   void topop(int v)
   {
	  tjian += v; 
	  if(flagpop)
	  {
        return;
	  }
	  flagpop = 1;
	  while(tjian != 0)
	  {
		  if(tjian >= val)
		  {
			  tjian -=val;
			  val = 0 ; 
		  }else{
			  val -= tjian;
			  tjian = 0 ;
		  }
	      sleep(1); 
	  }
	  flagpop = 0 ;
   }
}
int main(){

return 0;
}
