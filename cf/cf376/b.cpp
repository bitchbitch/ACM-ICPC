// File Name: b.cpp
// Author: darkdream
// Created Time: 2013年12月24日 星期二 22时12分11秒

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
int hs[200];
int main(){
  int n,m ; 
  memset(hs,0,sizeof(hs));
  scanf("%d %d",&n,&m);
 for(int i =1;i <= m;i ++)
 {
	int a,b ,c ;
    scanf("%d %d %d",&a,&b,&c);
	hs[a] -= c;
	hs[b] += c;
 }
 int sum = 0 ; 
 for(int i =1;i <= n;i ++)
 {
   if(hs[i] <= 0)
     sum += -hs[i];
 }
 printf("%d\n",sum);
return 0;
}
