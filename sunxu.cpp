// File Name: sunxu.cpp
// Author: darkdream
// Created Time: 2013年11月25日 星期一 16时42分29秒

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

using namespace std;


int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
   int a, b,c;
   scanf("%d %d %d",&a,&b,&c);
   if(a > b)
   {
     int temp = a; 
	  a = b; 
	  b = temp;
   }if(a > c)
   {
      int temp = a; 
	  a = c; 
	  c = temp;
   }
   if(b > c)
   {
      int temp = b; 
	  b = c; 
	  c = temp;
   }
   printf("%d %d %d\n",a,b,c);

return 0;
}
