// File Name: memset.cpp
// Author: darkdream
// Created Time: 2014年02月20日 星期四 19时47分06秒

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
int k[1000];
int main(){
  memset(k,1,sizeof(k));
  for(int i = 1;i <= 100;i ++)
	  printf("%d\n",k[i]);
  while(k[10])
  {
    if(k[10] % 2)
	   printf("1");
	else printf("0");
	k[10] =  k[10] /2;
  }
return 0;
}
