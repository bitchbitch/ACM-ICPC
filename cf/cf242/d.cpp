// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年04月25日 星期五 16时04分50秒

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
#include<climits>

using namespace std;
int map1[400][400];
int map2[400][400];
int map3[400][400];
int map4[400][400];
int main(){
   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   long long  sum = 0 ;
   clock_t a,b;
   int ansx
   
   for(int i = 1;i <= 300 ;i ++)
	   for(int j = 1; j<= 300 ;j ++)
		   for(int ij = i+1; ij <= 300 ;ij++)
			   for(int ji = j + 1; ji <= 300 ;ji ++)
				   sum ++ ; 
   printf("%ld\n",b-a);
   printf("%lld\n",sum);
return 0;
}
