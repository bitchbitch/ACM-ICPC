// File Name: seechange.cpp
// Author: darkdream
// Created Time: 2015年04月13日 星期一 15时24分55秒

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

int main(){
  FILE *p = fopen("out1","r");
  FILE *p1 = fopen("out","r");
  char str[1000];
  char str1[1000];
  int t = 0 ; 
  while(fgets(str,1000,p))
  {
	  t ++;
       fgets(str1,1000,p1);
       if(strcmp(str,str1) != 0 )
       {
         printf("***%d\n",t);
		 break;
       }
  }
return 0;
}
