// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年04月12日 星期日 13时44分39秒

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
int a[5];
int main(){
  int t; 
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %d %d",&a[1],&a[2],&a[3],&a[4]);
	int hs[2] = {0,0};
	if(a[1] == 0 )
	{
	  printf("Invalid\n");
	  continue;
	}
	if(a[2] <= a[3])
	{
		hs[0] = 1 ; 
	}else{
	   a[2] -= a[3]; 
	}
    if(a[4] <= a[1])
	{
		hs[1] = 1; 
	}else{
	   a[4] -= a[1];
	}
	if(hs[0])
	{
	  printf("Discard");
	}else printf("%d %d",a[1],a[2]);
	if(hs[1])
		printf(" Discard\n");
	else printf(" %d %d\n",a[3],a[4]);
	
  }

return 0;
}
