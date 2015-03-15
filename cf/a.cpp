// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年08月02日 星期六 22时35分46秒

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
int n , m,k; 
int hs[1000][1000];
int isok(int a, int b)
{
	if(hs[a][b] && hs[a-1][b] && hs[a-1][b-1] && hs[a][b-1])
       return 1;
	if(hs[a][b] && hs[a-1][b] && hs[a-1][b+1] && hs[a][b+1])
       return 1;
	if(hs[a][b] && hs[a+1][b] && hs[a+1][b+1] && hs[a][b+1])
       return 1;
	if(hs[a][b] && hs[a+1][b] && hs[a+1][b-1] && hs[a][b-1])
       return 1;
   return 0 ; 
} 
int main(){
  scanf("%d %d %d",&n,&m,&k);
  int ok = 0 ; 
  memset(hs,0,sizeof(hs));
  for(int i = 1;i <= k ;i ++)
  {
    int a, b; 
	scanf("%d %d",&a,&b);
	if(ok)
		continue;
	hs[a][b] = 1; 
    if(isok(a,b))
		ok = i ;  
  }
  printf("%d\n",ok);
return 0;
}
