// File Name: DynamicProgramming.cpp
// Author: darkdream
// Created Time: 2013年11月25日 星期一 18时28分09秒

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

int n , a[10000];
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
   int i ; 
   
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
	   scanf("%d",&a[i]);
   printf("%d\n",check(1,1,99999));
 

	return 0;
}

check(s,n,)
