// File Name: t.cpp
// Author: darkdream
// Created Time: 2015年03月14日 星期六 13时37分30秒

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
#include<queue>
#define LL long long

using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  int A,B;
  for(int i = 1;i <= n;i++)
  {
     scanf("%d %d",&A,&B); 
     int sum = 1 ; 
	 int t = 1; 
	 for(int i = 1;i <= A+B ;)
	 {
	     if(i <= A && i <= B)
		 {
		    sum += t*2; 
		 }else if(i > A && i <= B)
		 {
		     sum += t*2 - (i - A);
		 }else if(i <= A && i >= B)
		 {
		     sum += t*2 -(i -B);
		 }else{
		     sum += t*2 -(i-B) - (i-A);
		 }
		 t *= 2; 
		 i += t; 
	 }
	 printf("%d\n",sum);
  }
return 0;
}
