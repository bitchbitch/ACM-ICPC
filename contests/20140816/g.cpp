// File Name: g.cpp
// Author: darkdream
// Created Time: 2014年08月16日 星期六 12时43分06秒

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
char str[1000];
int main(){
  int t; 
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s",str);
	int len = strlen(str);
	int ok = 0 ; 
	for(int i = 0 ;i < len ;i ++)
	{
	  if(str[i] == 'D')
		  ok = 1;
	}
	if(ok )
		printf("You shall not pass!\n");
	else printf("Possible\n");
  }
return 0;
}
