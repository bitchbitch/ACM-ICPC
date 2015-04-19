// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年04月18日 星期六 20时49分04秒

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
  FILE *p2 = fopen("in","r");
  char str[1000];
  char str1[1000];
  char str2[1000];
  int t = 0; 
   fgets(str2,1000,p2);
  while(fgets(str,1000,p))
  {
       fgets(str1,1000,p1);
   fgets(str2,1000,p2);
	   t++;
       if(strcmp(str,str1) != 0 )
       {
        printf("%s\n%s****%s\n%d\n",str,str1,str2,t);
       }
  }
return 0;
}
