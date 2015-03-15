// File Name: flip.cpp
// Author: darkdream
// Created Time: 2013年11月29日 星期五 19时31分35秒

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
   int t ;
   scanf("%d",&t);
   while(t--)
   {
     int n; 
	 scanf("%d",&n);
	 int k = n +1;
	 int sum = 0 ; 
	 for(int i =1 ;i <= 32;i ++)
	 {
	     int a = n % 2 ; 
		 int b = k % 2; 
		 if(a != b)
			 sum ++;
		 n/=2;
		 k/=2;
	 }
	 printf("%d\n",sum);
    
   }
return 0;
}
